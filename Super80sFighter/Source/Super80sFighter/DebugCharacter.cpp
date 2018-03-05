// Fill out your copyright notice in the Description page of Project Settings.

#include "DebugCharacter.h"

ADebugCharacter::ADebugCharacter()
{



#pragma region Adding in commands for attacks
	TArray<ButtonSet> tempCommand;
	ButtonSet buttonSet;
	ButtonInput button1;

	button1.button = RIGHT;
	button1.wasHeld = false;
	buttonSet.inputs.Add(button1);
	tempCommand.Push(buttonSet);
	AddCommand<ADebugCharacter>(CommandList, tempCommand, &ADebugCharacter::testFunc);
#pragma endregion
}
void ADebugCharacter::SetupPlayerInputComponent(UInputComponent * InputComponent)

{
	int id = -1;

#pragma region Get Id
	if (GetPlayerController() != nullptr)
		id = GetPlayerController()->GetLocalPlayer()->GetControllerId();//My intellisense says its bad but it compiles and works. Fuck you VS
#pragma endregion

	if (id == 0)
	{

		InputComponent->BindAction("HighJump_P1", IE_Pressed, this, &ADebugCharacter::PressHighJump);
		InputComponent->BindAction("HighJump_P1", IE_Released, this, &ADebugCharacter::ReleaseHighJump);
		InputComponent->BindAction("ShortHop_P1", IE_Pressed, this, &ADebugCharacter::PressShortHop);
		InputComponent->BindAction("ShortHop_P1", IE_Released, this, &ADebugCharacter::ReleaseShortHop);
		InputComponent->BindAction("Jump_P1", IE_Pressed, this, &ADebugCharacter::PressNormalJump);
		InputComponent->BindAction("Jump_P1", IE_Released, this, &ADebugCharacter::ReleaseNormalJump);
		InputComponent->BindAction("PressRight_P1", IE_Pressed, this, &ADebugCharacter::PressRight);
		InputComponent->BindAction("PressRight_P1", IE_Released, this, &ADebugCharacter::ReleaseRight);
		InputComponent->BindAction("PressLeft_P1", IE_Pressed, this, &ADebugCharacter::PressLeft);
		InputComponent->BindAction("PressLeft_P1", IE_Released, this, &ADebugCharacter::ReleaseLeft);
		InputComponent->BindAxis("MoveRight_P1", this, &ADebugCharacter::MoveRight);
		InputComponent->BindAxis("MoveLeft_P1", this, &ADebugCharacter::MoveLeft);
		InputComponent->BindAction("Attack1_P1", IE_Pressed, this, &ADebugCharacter::PressPunch);
		InputComponent->BindAction("Attack2_P1", IE_Pressed, this, &ADebugCharacter::PressKick);
		InputComponent->BindAction("Attack3_P1", IE_Pressed, this, &ADebugCharacter::PressHeavy);
		InputComponent->BindAction("Attack4_P1", IE_Pressed, this, &ADebugCharacter::PressSpecial);
		InputComponent->BindAction("Attack1_P1", IE_Released, this, &ADebugCharacter::ReleasePunch);
		InputComponent->BindAction("Attack2_P1", IE_Released, this, &ADebugCharacter::ReleaseKick);
		InputComponent->BindAction("Attack3_P1", IE_Released, this, &ADebugCharacter::ReleaseHeavy);
		InputComponent->BindAction("Attack4_P1", IE_Released, this, &ADebugCharacter::ReleaseSpecial);
		InputComponent->BindAction("Crouch_P1", IE_Pressed, this, &ADebugCharacter::StartCrouch);
		InputComponent->BindAction("Crouch_P1", IE_Released, this, &ADebugCharacter::StopCrouch);
		InputComponent->BindAction("PunchKick_P1", IE_Pressed, this, &ADebugCharacter::PressPunchAndKick);
		InputComponent->BindAction("PunchKick_P1", IE_Released, this, &ADebugCharacter::ReleasePunchAndKick);
		InputComponent->BindAction("KickSpecial_P1", IE_Pressed, this, &ADebugCharacter::PressKickAndSpecial);
		InputComponent->BindAction("KickSpecial_P1", IE_Released, this, &ADebugCharacter::ReleaseKickAndSpecial);

	}
	else if (id == 1)
	{
		InputComponent->BindAction("HighJump_P2", IE_Pressed, this, &ADebugCharacter::PressHighJump);
		InputComponent->BindAction("HighJump_P2", IE_Released, this, &ADebugCharacter::ReleaseHighJump);
		InputComponent->BindAction("ShortHop_P2", IE_Pressed, this, &ADebugCharacter::PressShortHop);
		InputComponent->BindAction("ShortHop_P2", IE_Released, this, &ADebugCharacter::ReleaseShortHop);
		InputComponent->BindAction("Jump_P2", IE_Pressed, this, &ADebugCharacter::PressNormalJump);
		InputComponent->BindAction("Jump_P2", IE_Released, this, &ADebugCharacter::ReleaseNormalJump);
		InputComponent->BindAction("PressRight_P2", IE_Pressed, this, &ADebugCharacter::PressRight);
		InputComponent->BindAction("PressRight_P2", IE_Released, this, &ADebugCharacter::ReleaseRight);
		InputComponent->BindAction("PressLeft_P2", IE_Pressed, this, &ADebugCharacter::PressLeft);
		InputComponent->BindAction("PressLeft_P2", IE_Released, this, &ADebugCharacter::ReleaseLeft);
		InputComponent->BindAxis("MoveRight_P2", this, &ADebugCharacter::MoveRight);
		InputComponent->BindAxis("MoveLeft_P2", this, &ADebugCharacter::MoveLeft);
		InputComponent->BindAction("Attack1_P2", IE_Pressed, this, &ADebugCharacter::PressPunch);
		InputComponent->BindAction("Attack2_P2", IE_Pressed, this, &ADebugCharacter::PressKick);
		InputComponent->BindAction("Attack3_P2", IE_Pressed, this, &ADebugCharacter::PressHeavy);
		InputComponent->BindAction("Attack4_P2", IE_Pressed, this, &ADebugCharacter::PressSpecial);
		InputComponent->BindAction("Attack1_P2", IE_Released, this, &ADebugCharacter::ReleasePunch);
		InputComponent->BindAction("Attack2_P2", IE_Released, this, &ADebugCharacter::ReleaseKick);
		InputComponent->BindAction("Attack3_P2", IE_Released, this, &ADebugCharacter::ReleaseHeavy);
		InputComponent->BindAction("Attack4_P2", IE_Released, this, &ADebugCharacter::ReleaseSpecial);
		InputComponent->BindAction("Crouch_P2", IE_Pressed, this, &ADebugCharacter::StartCrouch);
		InputComponent->BindAction("Crouch_P2", IE_Released, this, &ADebugCharacter::StopCrouch);
		InputComponent->BindAction("PunchKick_P2", IE_Pressed, this, &ADebugCharacter::PressPunchAndKick);
		InputComponent->BindAction("PunchKick_P2", IE_Released, this, &ADebugCharacter::ReleasePunchAndKick);
		InputComponent->BindAction("KickSpecial_P2", IE_Pressed, this, &ADebugCharacter::PressKickAndSpecial);
		InputComponent->BindAction("KickSpecial_P2", IE_Released, this, &ADebugCharacter::ReleaseKickAndSpecial);

	}



	//spawn a hitbox on the player that can be hit and attacked
	spawnHitbox(EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX, FVector(0, 0, -80), FVector(.5f, .5f, 1.5f), 0, false);
	spawnHitbox(EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX, FVector(0, 0, -60), FVector(.35f, .35f, 1.25f), 0, false);

	//add onHit to capsule component
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &AFighterParent::onHit);

	//set startLocation
	startLocation = GetTransform().GetLocation();
	//set starting max stam stams
	stamina_tier = 3;
	health_tier = 3;
	regen_stamina = true;
	CurrentMaxStamina = TotalStamina;



}
#pragma region Input Functions
void ADebugCharacter::PressRight()
{
	AddInput<ADebugCharacter>(RIGHT, true, FApp::GetCurrentTime());
}
void ADebugCharacter::PressLeft()
{
	AddInput<ADebugCharacter>(LEFT, true, FApp::GetCurrentTime());
}
void ADebugCharacter::ReleaseRight()
{
	AddInput<ADebugCharacter>(RIGHT, false, FApp::GetCurrentTime());
}
void ADebugCharacter::ReleaseLeft()
{
	AddInput<ADebugCharacter>(LEFT, false, FApp::GetCurrentTime());
}
void ADebugCharacter::PressPunch()
{
	AddInput<ADebugCharacter>(INPUT_TYPE::PUNCH, true, FApp::GetCurrentTime());
}
void ADebugCharacter::PressKick()
{

	AddInput<ADebugCharacter>(INPUT_TYPE::KICK, true, FApp::GetCurrentTime());
}
void ADebugCharacter::PressHeavy()
{

	AddInput<ADebugCharacter>(INPUT_TYPE::HEAVY, true, FApp::GetCurrentTime());
}
void ADebugCharacter::PressSpecial()
{

	AddInput<ADebugCharacter>(INPUT_TYPE::SPECIAL, true, FApp::GetCurrentTime());
}
void ADebugCharacter::ReleasePunch()
{
	AddInput<ADebugCharacter>(INPUT_TYPE::PUNCH, false, FApp::GetCurrentTime());
}
void ADebugCharacter::ReleaseKick()
{

	AddInput<ADebugCharacter>(INPUT_TYPE::KICK, false, FApp::GetCurrentTime());
}
void ADebugCharacter::ReleaseHeavy()
{

	AddInput<ADebugCharacter>(INPUT_TYPE::HEAVY, false, FApp::GetCurrentTime());
}
void ADebugCharacter::ReleaseSpecial()
{

	AddInput<ADebugCharacter>(INPUT_TYPE::SPECIAL, false, FApp::GetCurrentTime());
}
void ADebugCharacter::StartCrouch()
{
	isCrouching = true;
	AddInput<ADebugCharacter>(DOWN, true, FApp::GetCurrentTime());
}
void ADebugCharacter::StopCrouch()
{
	isCrouching = false;
	AddInput<ADebugCharacter>(DOWN, false, FApp::GetCurrentTime());
}
void ADebugCharacter::PressJump()
{
	if (!isDead)
	{
		ACharacter::Jump();
		if (jumpEffect)
		{
			JumpEffectBlueprintEvent();
			jumpEffect = false;
		}
	}

	isHoldingJump = true;
	PressUp<ADebugCharacter>();
}
void ADebugCharacter::ReleaseJump()
{
	ACharacter::StopJumping();
	ReleaseUp<ADebugCharacter>();
	isHoldingJump = false;
	ReleaseUp<ADebugCharacter>();
}
#pragma endregion
#pragma region Attacks
void ADebugCharacter::high_cross_punch()
{
	QueStopAttacking();
	is_high_cross_punch = true;
}
void ADebugCharacter::high_strong_uppercut()
{
	QueStopAttacking();
	is_high_strong_uppercut = true;
}
void ADebugCharacter::mid_cross_punch()
{
	QueStopAttacking();
	is_mid_cross_punch = true;
}
void ADebugCharacter::mid_chasing_uppercut()
{
	QueStopAttacking();
	is_mid_chasing_uppercut = true;
}
void ADebugCharacter::mid_alt_hook()
{
	QueStopAttacking();
	is_mid_alt_hook = true;
}
void ADebugCharacter::low_hook()
{
	QueStopAttacking();
	is_low_hook = true;
}
void ADebugCharacter::high_lazy_overhead()
{
	QueStopAttacking();
	is_high_lazy_overhead = true;
}
void ADebugCharacter::mid_jab()
{
	QueStopAttacking();
	is_mid_jab = true;
}
void ADebugCharacter::low_heel_kick()
{
	QueStopAttacking();
	is_low_heel_kick = true;
}
void ADebugCharacter::QueStopAttacking()
{
	is_mid_jab = false;
	is_low_heel_kick = false;
	is_high_cross_punch = false;
	is_high_strong_uppercut = false;
	is_mid_cross_punch = false;
	is_mid_chasing_uppercut = false;
	is_mid_alt_hook = false;
	is_low_hook = false;
	is_high_lazy_overhead = false;
}
#pragma endregion
void ADebugCharacter::testFunc()
{
	int x = 0;
	return;
}
void ADebugCharacter::CheckCommand()
{
	if (isDead)
		return;

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

		if (!test.isPress)
		{
			//If its a release
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

			if (!found)
			{
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


	TArray<Command<ADebugCharacter>> CommandCopy;

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

