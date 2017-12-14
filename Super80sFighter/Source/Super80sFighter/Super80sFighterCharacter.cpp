// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Super80sFighterCharacter.h"



ASuper80sFighterCharacter::ASuper80sFighterCharacter()
{
	//I love asian qt3.14s
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

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

#pragma region Brennans Variables Init
	CustomHighJumpVelocity = 1000.0f;
	CustomShortJumpVelocity = 700.0f;
	JumpThreshold = 0.1f;
#pragma endregion


	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++) 
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

void ASuper80sFighterCharacter::UpdateCurrentHealth(float Health)
{
	CurrentHealth = CurrentHealth + Health;
}

void ASuper80sFighterCharacter::TakingDamage()
{
	UpdateCurrentStamina((1.0f * -0.01f) * TotalStamina);

	UpdateCurrentHealth((1.0f * -0.01f) * TotalHealth);
}

void ASuper80sFighterCharacter::SuperAbility()
{
	UpdateCurrentStamina((-0.25f) * TotalStamina);

}

void ASuper80sFighterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//////////////////////////////////////////////////////////////////////////
// Input

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


	PlayerInputComponent->BindAction("Attack1", IE_Pressed, this, &ASuper80sFighterCharacter::Attack0);
	PlayerInputComponent->BindAction("Attack2", IE_Pressed, this, &ASuper80sFighterCharacter::Attack1);
	PlayerInputComponent->BindAction("Attack3", IE_Pressed, this, &ASuper80sFighterCharacter::Attack2);
	PlayerInputComponent->BindAction("Attack4", IE_Pressed, this, &ASuper80sFighterCharacter::Attack3);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ASuper80sFighterCharacter::StartCrouch);

	PlayerInputComponent->BindAction("Attack1", IE_Released, this, &ASuper80sFighterCharacter::QueStopAttacking);
	PlayerInputComponent->BindAction("Attack2", IE_Released, this, &ASuper80sFighterCharacter::QueStopAttacking);
	PlayerInputComponent->BindAction("Attack3", IE_Released, this, &ASuper80sFighterCharacter::QueStopAttacking);
	PlayerInputComponent->BindAction("Attack4", IE_Released, this, &ASuper80sFighterCharacter::QueStopAttacking);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &ASuper80sFighterCharacter::StopCrouch);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &ASuper80sFighterCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ASuper80sFighterCharacter::TouchStopped);

	PlayerInputComponent->BindKey(EKeys::P, IE_Pressed, this, &ASuper80sFighterCharacter::TakingDamage);
	PlayerInputComponent->BindKey(EKeys::O, IE_Pressed, this, &ASuper80sFighterCharacter::SuperAbility);
}

void ASuper80sFighterCharacter::MoveRight(float Value)
{
	// add movement in that direction

	AddMovementInput(FVector(0.f, -1.f, 0.f), Value);

	if (Value > 0)//Moving right
		FlipCharacter(true);
	else if (Value < 0)
		FlipCharacter(false);


}
void ASuper80sFighterCharacter::Attack0()
{
	QueStopAttacking();
	isAttacking0 = true;
	AddAttack(ATTACK_TYPE::ATTACK_0);
	//spawnHitbox(EHITBOX_TYPE::VE_HITBOX_STRIKE, FVector(50, 0, 30), FVector(.5f, 1, .25f), 10);
	//rebuild

}
void ASuper80sFighterCharacter::Attack1()
{
	QueStopAttacking();
	isAttacking1 = true;
	AddAttack(ATTACK_TYPE::ATTACK_1);


}
void ASuper80sFighterCharacter::Attack2()
{
	QueStopAttacking();
	isAttacking2 = true;
	AddAttack(ATTACK_TYPE::ATTACK_2);

}
void ASuper80sFighterCharacter::Attack3()
{
	QueStopAttacking();
	isAttacking3 = true;
	AddAttack(ATTACK_TYPE::ATTACK_3);

}
AHitbox* ASuper80sFighterCharacter::spawnHitbox(EHITBOX_TYPE type, FVector offset, FVector dimensions, float damage)
{
	FVector tempVec;
	tempVec = GetTransform().GetLocation();
	FRotator rot(GetTransform().GetRotation());
	FActorSpawnParameters sp = FActorSpawnParameters();
	sp.bDeferConstruction = true;

	tempHitbox = GetWorld()->SpawnActor<AHitbox>(tempVec, rot, sp);
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
	if (HasJumpReachedThreshold) {
		GetCharacterMovement()->JumpZVelocity = CustomHighJumpVelocity;

	}
	else {
		GetCharacterMovement()->JumpZVelocity = CustomShortJumpVelocity;

	}
	PressJump();
}
void ASuper80sFighterCharacter::JumpReachesThreshold()
{
	HasJumpReachedThreshold = true;

	ReleaseJump();
}
void ASuper80sFighterCharacter::PressJump()
{
	ACharacter::Jump();
	isHoldingJump = true;
}
void ASuper80sFighterCharacter::ReleaseJump()
{
	ACharacter::StopJumping();
	isHoldingJump = false;
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
void ASuper80sFighterCharacter::AddAttack(ATTACK_TYPE incomingAttack)
{
	last5Attacks.Add(incomingAttack);
	if (last5Attacks.Num() > 5)
		last5Attacks.RemoveAt(0);
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

