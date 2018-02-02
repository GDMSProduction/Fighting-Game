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




	CustomHighJumpVelocity = 1000.0f;
	CustomShortJumpVelocity = 700.0f;
	JumpThreshold = 0.1f;
	AttackThreshold = 0.2f;

	holdThreshold = 0.13;
	samePressThreshold = 1.0 / 60.0;//framecount / 60.0 for how many frames leneancy to give them
#pragma region Adding in commands for attacks
	TArray<ButtonSet> tempCommand;
	ButtonSet buttonSet;
	ButtonInput button1;

	button1.button = PUNCH;
	button1.wasHeld = false;
	buttonSet.inputs.Add(button1);
	tempCommand.Push(buttonSet);
	AddCommand(tempCommand, &ASuper80sFighterCharacter::Attack0);


	button1.button = KICK;
	button1.wasHeld = false;
	buttonSet.Clear();
	buttonSet.inputs.Add(button1);
	tempCommand.Push(buttonSet);
	AddCommand(tempCommand, &ASuper80sFighterCharacter::Attack2);

	while (tempCommand.Num() > 0)
		tempCommand.RemoveAt(0);


	buttonSet.Clear();
	button1.button = HEAVY;
	buttonSet.inputs.Add(button1);
	tempCommand.Add(buttonSet);



	buttonSet.Clear();
	button1.button = RIGHT;
	buttonSet.inputs.Add(button1);
	tempCommand.Add(buttonSet);

	buttonSet.Clear();
	button1.button = DOWN;
	buttonSet.inputs.Add(button1);
	tempCommand.Add(buttonSet);


	AddCommand(tempCommand, &ASuper80sFighterCharacter::Attack3);


	while (tempCommand.Num() > 0)
		tempCommand.RemoveAt(0);

	buttonSet.Clear();
	button1.button = PUNCH;
	button1.wasHeld = true;
	buttonSet.inputs.Add(button1);
	button1.button = KICK;
	button1.wasHeld = false;
	buttonSet.inputs.Add(button1);

	tempCommand.Add(buttonSet);
	AddCommand(tempCommand, &ASuper80sFighterCharacter::Attack3);

#pragma endregion


	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++) 
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


	PlayerInputComponent->BindAction("PressRight", IE_Pressed, this, &ASuper80sFighterCharacter::PressRight);
	PlayerInputComponent->BindAction("PressRight", IE_Released, this, &ASuper80sFighterCharacter::ReleaseRight);

	PlayerInputComponent->BindAction("PressLeft", IE_Pressed, this, &ASuper80sFighterCharacter::PressLeft);
	PlayerInputComponent->BindAction("PressLeft", IE_Released, this, &ASuper80sFighterCharacter::ReleaseLeft);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASuper80sFighterCharacter::MoveRight);




	PlayerInputComponent->BindAction("Attack1", IE_Pressed, this, &ASuper80sFighterCharacter::PressPunch);
	PlayerInputComponent->BindAction("Attack2", IE_Pressed, this, &ASuper80sFighterCharacter::PressKick);
	PlayerInputComponent->BindAction("Attack3", IE_Pressed, this, &ASuper80sFighterCharacter::PressHeavy);
	PlayerInputComponent->BindAction("Attack4", IE_Pressed, this, &ASuper80sFighterCharacter::PressSpecial);

	PlayerInputComponent->BindAction("Attack1", IE_Released, this, &ASuper80sFighterCharacter::ReleasePunch);
	PlayerInputComponent->BindAction("Attack2", IE_Released, this, &ASuper80sFighterCharacter::ReleaseKick);
	PlayerInputComponent->BindAction("Attack3", IE_Released, this, &ASuper80sFighterCharacter::ReleaseHeavy);
	PlayerInputComponent->BindAction("Attack4", IE_Released, this, &ASuper80sFighterCharacter::ReleaseSpecial);


	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ASuper80sFighterCharacter::StartCrouch);


	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &ASuper80sFighterCharacter::StopCrouch);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &ASuper80sFighterCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ASuper80sFighterCharacter::TouchStopped);

	PlayerInputComponent->BindKey(EKeys::O, IE_Pressed, this, &ASuper80sFighterCharacter::SuperAbility);


	//spawn a hitbox on the player that can be hit and attacked
	spawnHitbox(EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX, FVector(0, 0, -80), FVector(.5f, .5f, 1.5f), 0);
	spawnHitbox(EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX, FVector(0, 0, -60), FVector(.35f, .35f, 1.25f), 0);

	//add onHit to capsule component
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &ASuper80sFighterCharacter::onHit);

	//set startLocation
	startLocation = GetTransform().GetLocation();
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
void ASuper80sFighterCharacter::ResetHealth()
{
	CurrentHealth = TotalHealth;
}
void ASuper80sFighterCharacter::ResetStamina()
{
	CurrentStamina = TotalStamina;
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
	if (!lock_grounded)
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


	if (grounded && EnemyPlayer->grounded) {
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





void ASuper80sFighterCharacter::MoveRight(float Value)
{

	// add movement in that direction
	if (grounded)
		ControlInputVector += (FVector(0, -1.f, 0) * Value);



}

void ASuper80sFighterCharacter::PressRight()
{
	AddInput(RIGHT, true, FApp::GetCurrentTime());
}
void ASuper80sFighterCharacter::PressLeft()
{
	AddInput(LEFT, true, FApp::GetCurrentTime());
}
void ASuper80sFighterCharacter::ReleaseRight()
{
	AddInput(RIGHT, false, FApp::GetCurrentTime());
}
void ASuper80sFighterCharacter::ReleaseLeft()
{
	AddInput(LEFT, false, FApp::GetCurrentTime());
}

void ASuper80sFighterCharacter::PressPunch()
{
	AddInput(INPUT_TYPE::PUNCH, true, FApp::GetCurrentTime());
}
void ASuper80sFighterCharacter::PressKick()
{

	AddInput(INPUT_TYPE::KICK, true, FApp::GetCurrentTime());
}
void ASuper80sFighterCharacter::PressHeavy()
{

	AddInput(INPUT_TYPE::HEAVY, true, FApp::GetCurrentTime());
}
void ASuper80sFighterCharacter::PressSpecial()
{

	AddInput(INPUT_TYPE::SPECIAL, true, FApp::GetCurrentTime());
}

void ASuper80sFighterCharacter::ReleasePunch()
{
	AddInput(INPUT_TYPE::PUNCH, false, FApp::GetCurrentTime());
}
void ASuper80sFighterCharacter::ReleaseKick()
{

	AddInput(INPUT_TYPE::KICK, false, FApp::GetCurrentTime());
}
void ASuper80sFighterCharacter::ReleaseHeavy()
{

	AddInput(INPUT_TYPE::HEAVY, false, FApp::GetCurrentTime());
}
void ASuper80sFighterCharacter::ReleaseSpecial()
{

	AddInput(INPUT_TYPE::SPECIAL, false, FApp::GetCurrentTime());
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
	AddInput(DOWN, true, FApp::GetCurrentTime());
}
void ASuper80sFighterCharacter::StopCrouch()
{
	isCrouching = false;
	AddInput(DOWN, false, FApp::GetCurrentTime());
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
	AddInput(INPUT_TYPE::UP, true, FApp::GetCurrentTime());
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

	TArray<ButtonSet> tempCommandBuffer;

#pragma region Create the temporary CommandBuffer
	TArray<ButtonBufferInput> bufferCopy;
	for (int cur = 0; cur < buttonBuffer.Num(); cur++) bufferCopy.Add(buttonBuffer[cur]);//Inline explicit copy


	ButtonSet currentButtonSet;

	ButtonBufferInput previousTest = bufferCopy.Last();

	int a = bufferCopy.Num();

	while (bufferCopy.Num() > 0) {
		ButtonBufferInput test = bufferCopy.Last();
		double testint = test.timeOfInput - previousTest.timeOfInput;
		if (previousTest.timeOfInput - test.timeOfInput > samePressThreshold) {//If the next button was pressed at a different time than the others
			tempCommandBuffer.Add(currentButtonSet);
			currentButtonSet.Clear();
		}

		if (!test.isPress) {//If its a release
			bool found = false;
			for (int i = bufferCopy.Num() - 2; i >= 0; i--)//starting from the next button press, going down
			{
				if (bufferCopy[i].isPress && bufferCopy[i].Buttons == test.Buttons) {//If its a press and its the same input type
					found = true;
					bool held = (bufferCopy[i].timeOfInput - test.timeOfInput >= holdThreshold);

					ButtonInput tempButton;
					tempButton.button = test.Buttons;
					tempButton.wasHeld = held;
					currentButtonSet.inputs.Push(tempButton);

					bufferCopy.RemoveAt(i);
					break;
				}

			}
			if (!found) {
				ButtonInput tempButton;
				tempButton.button = test.Buttons;
				tempButton.wasHeld = true;
				currentButtonSet.inputs.Push(tempButton);
			}
			bufferCopy.RemoveAt(bufferCopy.Num() - 1);
		}
		else //If its a press
		{
			ButtonInput tempButton;
			tempButton.button = test.Buttons;
			tempButton.wasHeld = false;
			currentButtonSet.inputs.Push(tempButton);

			bufferCopy.RemoveAt(bufferCopy.Num() - 1);
		}

		previousTest = test;
	}
	tempCommandBuffer.Push(currentButtonSet);
#pragma endregion






	if (tempCommandBuffer.Num() == 0)
		return;


	TArray<Command> CommandCopy;
	for (int cur = 0; cur < CommandList.Num(); cur++) CommandCopy.Add(CommandList[cur]);//Create a copy of the commandlist
	//For each item in the AlreadyCalledCommands:
	//Remove it from the copy of commandList
	for (int cur = 0; cur < AlreadyCalledCommands.Num(); ++cur) {
		QueStopAttacking();
		CommandCopy.Remove(AlreadyCalledCommands[cur]);
	};


#pragma region Set "Forward" and "Backward"
	INPUT_TYPE forward;
	INPUT_TYPE backward;
	if (EnemyPlayer->GetTransform().GetLocation().Y > GetTransform().GetLocation().Y) {
		forward = INPUT_TYPE::LEFT;
		backward = INPUT_TYPE::RIGHT;
	}
	else
	{
		forward = INPUT_TYPE::RIGHT;
		backward = INPUT_TYPE::LEFT;
	}
	for (int i = 0; i < CommandCopy.Num(); i++)
	{
		for (int j = 0; j < CommandCopy[i].InputsForCommand.Num(); j++)
		{
			for (int k = 0; k < CommandCopy[i].InputsForCommand[j].inputs.Num(); k++)
			{
				if (CommandCopy[i].InputsForCommand[j].inputs[k].button == RIGHT)
					CommandCopy[i].InputsForCommand[j].inputs[k].button = forward;
				else if (CommandCopy[i].InputsForCommand[j].inputs[k].button == LEFT)
					CommandCopy[i].InputsForCommand[j].inputs[k].button = backward;
			}
		}
	}
#pragma endregion
	int x = tempCommandBuffer.Num();

	for (int currentCommand = 0; currentCommand < CommandCopy.Num(); currentCommand++)
	{
		for (int i = 0; i < tempCommandBuffer.Num() && i + CommandCopy[currentCommand].InputsForCommand.Num() <= tempCommandBuffer.Num(); i++)
		{
			if (tempCommandBuffer[i] == CommandCopy[currentCommand].InputsForCommand[0]) {
				bool same = true;
				for (int j = i; j < CommandCopy[currentCommand].InputsForCommand.Num() + i; j++)
				{
					if (tempCommandBuffer[j] != CommandCopy[currentCommand].InputsForCommand[j - i]) {
						same = false;
						break;
					}
				}
				if (same) {
					(this->*CommandCopy[currentCommand].functionToCall)();
					AlreadyCalledCommands.Add(CommandCopy[currentCommand]);
				}
			}
		}
	}


}
void ASuper80sFighterCharacter::ClearCommands()
{
	while (buttonBuffer.Num() != 0)
		buttonBuffer.RemoveAt(0);
	while (AlreadyCalledCommands.Num() != 0)
		AlreadyCalledCommands.RemoveAt(0);

	QueStopAttacking();

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
void ASuper80sFighterCharacter::AddCommand(TArray<ButtonSet> InputsForCommand, void(ASuper80sFighterCharacter::*functionToCall)())
{
	Command tempCommand;
	tempCommand.functionToCall = functionToCall;
	tempCommand.InputsForCommand = InputsForCommand;
	CommandList.Add(tempCommand);
}
void ASuper80sFighterCharacter::AddInput(INPUT_TYPE incomingAttack, bool wasPressed, double timeOfPress)
{
	ButtonBufferInput tempInput;
	tempInput.Buttons = incomingAttack;
	tempInput.isPress = wasPressed;
	tempInput.timeOfInput = timeOfPress;
	buttonBuffer.Add(tempInput);
	if (buttonBuffer.Num() > 10)
		buttonBuffer.RemoveAt(buttonBuffer.Num() - 1);
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

