//Fill out your copyright notice in the Description page of Project Settings.
#include "ThugClass.h"

//Set up the thug's functionality.
void AThugClass::SetUpThug()
{
	//Add the default inputs for every thug.
	inputsToUse.Add(0);
	inputsToUse.Add(1);
	inputsToUse.Add(2);
	inputsToUse.Add(3);
	inputsToUse.Add(4);
	inputsToUse.Add(5);
	inputsToUse.Add(6);

	//Determine the moves the thug will have available to them.
	DetermineMoveSet(inputsToUse, stageNumber);
}

//Determine the moves the thug will have available to them.
void AThugClass::DetermineMoveSet(TArray<short>& _inputsToUse, short _stage)
{
	//Determine the stage the player is on.
	switch (_stage)
	{
	case 0:
		break;

	case 1:
		break;

	case 2:
		break;

	case 3:
		break;

	case 4:
		break;

	case 5:
		break;

	case 6:
		break;

	case 7:
		break;
	}
}

//Increment the timer, called every frame.
void AThugClass::Tick(float _deltaTime)
{
	//Use the parent's timer to perform the tick.
	Super::Tick(_deltaTime);
}





