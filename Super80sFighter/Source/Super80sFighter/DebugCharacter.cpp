// Fill out your copyright notice in the Description page of Project Settings.

#include "DebugCharacter.h"

ADebugCharacter::ADebugCharacter() 
{



#pragma region Adding in commands for attacks
	TArray<ButtonSet> tempCommand;
	ButtonSet buttonSet;
	ButtonInput button1;

	button1.button = PUNCH;
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

void ADebugCharacter::testFunc()
{
	int x = 0;
	return;
}
