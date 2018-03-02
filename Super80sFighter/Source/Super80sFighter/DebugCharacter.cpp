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

	
		//
		//
		//	button1.button = KICK;
		//	button1.wasHeld = false;
		//	buttonSet.Clear();
		//	buttonSet.inputs.Add(button1);
		//	tempCommand.Push(buttonSet);
		//	AddCommand(tempCommand, &ADebugCharacter::testFunc);
		//
		//	while (tempCommand.Num() > 0)
		//		tempCommand.RemoveAt(0);
		//
		//
		//	buttonSet.Clear();
		//	button1.button = HEAVY;
		//	buttonSet.inputs.Add(button1);
		//	tempCommand.Add(buttonSet);
		//
		//	buttonSet.Clear();
		//	button1.button = RIGHT;
		//	buttonSet.inputs.Add(button1);
		//	tempCommand.Add(buttonSet);
		//
		//	buttonSet.Clear();
		//	button1.button = DOWN;
		//	buttonSet.inputs.Add(button1);
		//	tempCommand.Add(buttonSet);
		//
		//	AddCommand(tempCommand, &ADebugCharacter::testFunc);
		//
		//
		//	while (tempCommand.Num() > 0)
		//		tempCommand.RemoveAt(0);
		//
		//	buttonSet.Clear();
		//	button1.button = PUNCH;
		//	button1.wasHeld = true;
		//	buttonSet.inputs.Add(button1);
		//	button1.button = KICK;
		//	button1.wasHeld = false;
		//	buttonSet.inputs.Add(button1);
		//
		//	tempCommand.Add(buttonSet);
		//	AddCommand(tempCommand, &ADebugCharacter::testFunc);
		//
		//	while (tempCommand.Num() > 0)
		//		tempCommand.RemoveAt(0);
		//
		//	buttonSet.Clear();
		//	button1.button = HEAVY;
		//	button1.wasHeld = false;
		//	buttonSet.inputs.Add(button1);
		//	button1.button = SPECIAL;
		//	buttonSet.inputs.Add(button1);
		//
		//	tempCommand.Add(buttonSet);
		//	AddCommand(tempCommand, &AFighterParent::AttackTaunt);
#pragma endregion
}

void ADebugCharacter::PressRight()
{
	AddInput<ADebugCharacter>(RIGHT, true, FApp::GetCurrentTime());
}

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
