// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Super80sFighterCharacter.h"



ASuper80sFighterCharacter::ASuper80sFighterCharacter()
{
	//I love asian qt3.14s
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	//disable overlap events on the characters capsule component
	GetCapsuleComponent()->bGenerateOverlapEvents = false;

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f, 0.f, 75.f);
	CameraBoom->RelativeRotation = FRotator(0.f, 180.f, 0.f);

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = false; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 0.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	TotalStamina = 100.0f;
	CurrentStamina = TotalStamina;

	TotalHealth = 100.0f;
	CurrentHealth = TotalHealth;

	TArray<INPUT> deleteThis;
	INPUT tapPunch;
	tapPunch.inputType = PUNCH;
	tapPunch.wasHeld = false;
	deleteThis.Add(tapPunch);
	Command DeleteCommand;
	DeleteCommand.InputsForCommand = deleteThis;
	DeleteCommand.functionToCall = &ASuper80sFighterCharacter::PrintMessage;
	CommandList.Add(DeleteCommand);

#pragma region Physics Variables Init
	CustomHighJumpVelocity = 1000.0f;
	CustomShortJumpVelocity = 700.0f;
	JumpThreshold = 0.1f;
	AttackThreshold = 0.2f;
#pragma endregion


	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++) 
}
void ASuper80sFighterCharacter::PrintMessage()
{
	//UE_LOG(LogTemp, Warning, TEXT("%s is The Key"), this->InputComponent->GetAxisKeyValue())
}
void ASuper80sFighterCharacter::SetOtherPlayer(ASuper80sFighterCharacter * OtherPlayer)
{
	EnemyPlayer = OtherPlayer;
}
float ASuper80sFighterCharacter::GetTotalStamina()
{
	return TotalStamina;
}
float ASuper80sFighterCharacter::GetCurrentStamina()
{
	return CurrentStamina;
}
void ASuper80sFighterCharacter::UpdateCurrentStamina(float Stamina)
{
	CurrentStamina = CurrentStamina + Stamina;
}
float ASuper80sFighterCharacter::GetTotalHealth()
{
	return TotalHealth;
}
float ASuper80sFighterCharacter::GetCurrentHealth()
{
	return CurrentHealth;
}
void ASuper80sFighterCharacter::onHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{
	lock_grounded = false;
	if (OtherActor == EnemyPlayer)
	{
		//fix issue with jumping on top of other players
		FVector my_location = GetTransform().GetLocation();
		FVector enemy_location = EnemyPlayer->GetTransform().GetLocation();
		if (my_location.Z > enemy_location.Z)
		{
			if (my_location.Y >= enemy_location.Y)
				non_grounded_forces += FVector(0, 100, 0);
			else
				non_grounded_forces += FVector(0, -100, 0);
			lock_grounded = true;
		}
	}
}
void ASuper80sFighterCharacter::UpdateCurrentHealth(float Health)
{
	CurrentHealth = CurrentHealth + Health;
}
void ASuper80sFighterCharacter::TakeDamage(float damage)
{
	UpdateCurrentStamina(damage * -.5f);
	UE_LOG(LogTemp, Warning, TEXT("YOU TAKING DAMAGE THIS MUCH DAMAGE %f OH NO"), damage);
	UpdateCurrentHealth(-damage);
}
void ASuper80sFighterCharacter::SuperAbility()
{
	UpdateCurrentStamina((-0.25f) * TotalStamina);

}
void ASuper80sFighterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//implementing my physics
	if(!lock_grounded)
		grounded = GetCharacterMovement()->IsMovingOnGround();
	if (grounded)
		non_grounded_forces = FVector(0, 0, 0);
	else
		grounded_forces = FVector(0, 0, 0);
	//currently using .05f so really small forces are ignored, change to 0 if you want to include very small forces
	if (FVector::DistSquared(FVector::ZeroVector, non_grounded_forces) > .05f)
	{
		ControlInputVector += non_grounded_forces * DeltaTime;
		non_grounded_forces -= non_grounded_forces * DeltaTime;
	}
	if (FVector::DistSquared(FVector::ZeroVector, grounded_forces) > .05f)
	{
		ControlInputVector += grounded_forces * DeltaTime;
		grounded_forces -= grounded_forces * DeltaTime;
	}
	if (FVector::DistSquared(FVector::ZeroVector, absolute_forces) > .05f)
	{
		ControlInputVector += absolute_forces * DeltaTime;
		grounded_forces -= absolute_forces * DeltaTime;
	}


	if (/*They are touching the ground only*/ EnemyPlayer->GetTransform().GetLocation().Z == GetTransform().GetLocation().Z) {
		if (EnemyPlayer->GetTransform().GetLocation().Y > GetTransform().GetLocation().Y)
			FlipCharacter(false);
		else
			FlipCharacter(true);
	}
	else
	{
		FlipCharacter(IsFacingRight);
	}


}




void ASuper80sFighterCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	PlayerInputComponent->BindAction("HighJump", IE_Pressed, this, &ASuper80sFighterCharacter::PressHighJump);
	PlayerInputComponent->BindAction("HighJump", IE_Released, this, &ASuper80sFighterCharacter::ReleaseHighJump);
	PlayerInputComponent->BindAction("ShortHop", IE_Pressed, this, &ASuper80sFighterCharacter::PressShortHop);
	PlayerInputComponent->BindAction("ShortHop", IE_Released, this, &ASuper80sFighterCharacter::ReleaseShortHop);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASuper80sFighterCharacter::PressNormalJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ASuper80sFighterCharacter::ReleaseNormalJump);

	PlayerInputComponent->BindAxis("MoveRight", this, &ASuper80sFighterCharacter::MoveRight);



	PlayerInputComponent->BindAction("Attack1", IE_Pressed, this, &ASuper80sFighterCharacter::PressPunch);
	PlayerInputComponent->BindAction("Attack2", IE_Pressed, this, &ASuper80sFighterCharacter::PressKick);
	PlayerInputComponent->BindAction("Attack3", IE_Pressed, this, &ASuper80sFighterCharacter::PressHeavy);
	PlayerInputComponent->BindAction("Attack4", IE_Pressed, this, &ASuper80sFighterCharacter::PressSpecial);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ASuper80sFighterCharacter::StartCrouch);

	PlayerInputComponent->BindAction("Attack1", IE_Released, this, &ASuper80sFighterCharacter::QueStopAttacking);
	PlayerInputComponent->BindAction("Attack2", IE_Released, this, &ASuper80sFighterCharacter::QueStopAttacking);
	PlayerInputComponent->BindAction("Attack3", IE_Released, this, &ASuper80sFighterCharacter::QueStopAttacking);
	PlayerInputComponent->BindAction("Attack4", IE_Released, this, &ASuper80sFighterCharacter::QueStopAttacking);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &ASuper80sFighterCharacter::StopCrouch);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &ASuper80sFighterCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ASuper80sFighterCharacter::TouchStopped);

	PlayerInputComponent->BindKey(EKeys::O, IE_Pressed, this, &ASuper80sFighterCharacter::SuperAbility);




	//spawn a hitbox on the player that can be hit and attacked
	spawnHitbox(EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX, FVector(0, 0, -80), FVector(.5f, .5f, 1.5f), 0);
	spawnHitbox(EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX, FVector(0, 0, -60), FVector(.35f, .35f, 1.25f), 0);

	//add onHit to capsule component
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &ASuper80sFighterCharacter::onHit);
}
void ASuper80sFighterCharacter::MoveRight(float Value)
{
	// add movement in that direction
	ControlInputVector += (FVector(0, -1.f, 0) * Value);

	if (Value > 0)//Moving right
	{
		FlipCharacter(true);
		AddInput(RIGHT);

	}

	else if (Value < 0) {
		FlipCharacter(false);
		AddInput(LEFT);
	}


}
void ASuper80sFighterCharacter::PressPunch()
{
	AddInput(INPUT_TYPE::PUNCH);
}
void ASuper80sFighterCharacter::PressKick()
{

	AddInput(INPUT_TYPE::KICK);
}
void ASuper80sFighterCharacter::PressHeavy()
{

	AddInput(INPUT_TYPE::HEAVY);
}
void ASuper80sFighterCharacter::PressSpecial()
{

	AddInput(INPUT_TYPE::SPECIAL);
}
AHitbox* ASuper80sFighterCharacter::spawnHitbox(EHITBOX_TYPE type, FVector offset, FVector dimensions, float damage)
{
	FVector tempVec;
	tempVec = GetTransform().GetLocation();
	FRotator rot(GetTransform().GetRotation());
	FActorSpawnParameters sp = FActorSpawnParameters();
	sp.bDeferConstruction = true;

	tempHitbox = GetWorld()->SpawnActor<AHitbox>(AHitbox::StaticClass(), tempVec, rot, sp);
	tempHitbox->GetTransform().SetLocation(tempVec);

	//reenable if we don't want all hitboxes to move with the player
	//if (type == EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX || type == EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX)
	//{
	FAttachmentTransformRules rules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, true);
	tempHitbox->AttachToComponent(RootComponent, rules);
	//}
	tempHitbox->SetHitboxProperties(type, offset, dimensions, damage);

	hitboxes.Add(tempHitbox);
	return tempHitbox;
}
void ASuper80sFighterCharacter::StartCrouch()
{
	isCrouching = true;
}
void ASuper80sFighterCharacter::StopCrouch()
{
	isCrouching = false;
}
#pragma region Jump functions
void ASuper80sFighterCharacter::PressShortHop()
{
	GetCharacterMovement()->JumpZVelocity = CustomShortJumpVelocity;
	PressJump();
}
void ASuper80sFighterCharacter::ReleaseShortHop()
{
	ReleaseJump();
}
void ASuper80sFighterCharacter::PressHighJump()
{
	GetCharacterMovement()->JumpZVelocity = CustomHighJumpVelocity;
	PressJump();
}
void ASuper80sFighterCharacter::ReleaseHighJump()
{
	ReleaseJump();
}
void ASuper80sFighterCharacter::PressNormalJump() {
	GetWorld()->GetTimerManager().SetTimer(JumpTimer, this, &ASuper80sFighterCharacter::JumpReachesThreshold, JumpThreshold);
	HasJumpReachedThreshold = false;



}
void ASuper80sFighterCharacter::ReleaseNormalJump() {

	if (HasJumpReachedThreshold)
	{
		GetCharacterMovement()->JumpZVelocity = CustomHighJumpVelocity;
	}
	else
	{
		GetCharacterMovement()->JumpZVelocity = CustomShortJumpVelocity;
	}
	PressJump();


}
void ASuper80sFighterCharacter::JumpReachesThreshold()
{
	HasJumpReachedThreshold = true;

	ReleaseNormalJump();
}

void ASuper80sFighterCharacter::PressJump()
{
	ACharacter::Jump();
	isHoldingJump = true;
	AddInput(INPUT_TYPE::UP);
}
void ASuper80sFighterCharacter::ReleaseJump()
{
	ACharacter::StopJumping();
	isHoldingJump = false;
}
#pragma endregion
#pragma region Attacks
void ASuper80sFighterCharacter::CheckCommand()
{
	if (last5Attacks.Num() == 0)
		return;

	INPUT_TYPE forward;
	INPUT_TYPE backward;

#pragma region Set "Forward" and "Backward"
	if (EnemyPlayer->GetTransform().GetLocation().Y > GetTransform().GetLocation().Y) {
		forward = INPUT_TYPE::LEFT;
		backward = INPUT_TYPE::RIGHT;
	}
	else
	{
		forward = INPUT_TYPE::RIGHT;
		backward = INPUT_TYPE::LEFT;
	}
#pragma endregion


	if (last5Attacks.Num() == 1)
	{
		switch (last5Attacks[0])
		{
		case ASuper80sFighterCharacter::PUNCH:
			Attack0();
			break;
		case ASuper80sFighterCharacter::KICK:
			Attack1();
			break;
		case ASuper80sFighterCharacter::HEAVY:
			Attack2();
			break;
		case ASuper80sFighterCharacter::SPECIAL:
			Attack3();
			break;
		//These arent moves that, by themselves, do anything
		//case ASuper80sFighterCharacter::LEFT:
		//	break;
		//case ASuper80sFighterCharacter::RIGHT:
		//	break;
		//case ASuper80sFighterCharacter::UP:
		//	break;
		//case ASuper80sFighterCharacter::DOWN:
		//	break;

		default:
			break;
		}
	}

	if (last5Attacks.Num() == 2)
	{
		switch (last5Attacks[1])
		{
		case ASuper80sFighterCharacter::PUNCH:

			break;
		case ASuper80sFighterCharacter::KICK:
			break;
		case ASuper80sFighterCharacter::HEAVY:
			break;
		case ASuper80sFighterCharacter::SPECIAL:
			break;
		case ASuper80sFighterCharacter::LEFT:
			break;
		case ASuper80sFighterCharacter::RIGHT:
			break;
		case ASuper80sFighterCharacter::UP:
			break;
		case ASuper80sFighterCharacter::DOWN:
			break;
		default:
			break;
		}
	}

	if (last5Attacks.Num() == 3)
	{

	}

	if (last5Attacks.Num() == 4)
	{

	}

	if (last5Attacks.Num() == 5)
	{

	}

}
void ASuper80sFighterCharacter::ClearCommands()
{
	while (last5Attacks.Num() != 0)
		last5Attacks.RemoveAt(0);

}
void ASuper80sFighterCharacter::Attack0()
{
	QueStopAttacking();
	isAttacking0 = true;
}
void ASuper80sFighterCharacter::Attack1()
{
	QueStopAttacking();
	isAttacking1 = true;
}
void ASuper80sFighterCharacter::Attack2()
{
	QueStopAttacking();
	isAttacking2 = true;
}
void ASuper80sFighterCharacter::Attack3()
{
	QueStopAttacking();
	isAttacking3 = true;
}
#pragma endregion
void ASuper80sFighterCharacter::FlipCharacter()
{
	FlipCharacter(!IsFacingRight);

}
void ASuper80sFighterCharacter::FlipCharacter(bool forceFaceRight)
{
	if (forceFaceRight)//If we're forcing them to face right, face them right
	{
		//Set the transform scale x component to 1
		FVector trans = GetTransform().GetScale3D();
		trans.X = 1.0f;
		SetActorScale3D(trans);


	}
	else//If we're forcing them to face left, face them left
	{
		//Set the transform scale x component to -1
		FVector trans = GetTransform().GetScale3D();
		trans.X = -1.0f;
		SetActorScale3D(trans);

	}

	IsFacingRight = forceFaceRight;
}

void ASuper80sFighterCharacter::QueStopAttacking() {
	isAttacking0 = false;
	isAttacking1 = false;
	isAttacking2 = false;
	isAttacking3 = false;
}
void ASuper80sFighterCharacter::AddCommand(TArray<INPUT> InputsForCommand, void(ASuper80sFighterCharacter::* functionToCall)())
{
	Command tempCommand;
	tempCommand.functionToCall = functionToCall;
	tempCommand.InputsForCommand = InputsForCommand;
	CommandList.Add(tempCommand);
}
void ASuper80sFighterCharacter::AddInput(INPUT_TYPE incomingAttack)
{
	last5Attacks.Add(incomingAttack);
	if (last5Attacks.Num() > 5)
		last5Attacks.RemoveAt(0);
	CheckCommand();

	GetWorld()->GetTimerManager().SetTimer(AttackTimer, this, &ASuper80sFighterCharacter::ClearCommands, AttackThreshold);

}
void ASuper80sFighterCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void ASuper80sFighterCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}

