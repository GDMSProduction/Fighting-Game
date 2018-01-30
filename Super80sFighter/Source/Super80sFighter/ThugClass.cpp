//Fill out your copyright notice in the Description page of Project Settings.
#include "ThugClass.h"

//Set up the thug's functionality.
void AThugClass::SetUpThug()
{
	//Add the default inputs for every thug.
	inputsToUse.Add(MOVEFORWARD);
	inputsToUse.Add(MOVEBACKWARD);
	inputsToUse.Add(HOP);
	inputsToUse.Add(JUMP);
	inputsToUse.Add(CROUCH);
	inputsToUse.Add(PUNCH);
	inputsToUse.Add(KICK);

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
		_inputsToUse.Add(SPECIAL1);
		break;

	case 3:
		break;

	case 4:
		_inputsToUse.Add(SPECIAL1);
		_inputsToUse.Add(SPECIAL2);
		break;

	case 5:
		break;

	case 6:
		_inputsToUse.Add(SPECIAL1);
		_inputsToUse.Add(SPECIAL2);
		_inputsToUse.Add(SPECIAL3);
		break;

	case 7:
		_inputsToUse.Add(SPECIAL1);
		_inputsToUse.Add(SPECIAL2);
		_inputsToUse.Add(SPECIAL3);
		_inputsToUse.Add(SPECIAL4);
		break;
	}
}

//Increment the timer, called every frame.
void AThugClass::Tick(float _deltaTime)
{
	//Use the parent's timer to perform the tick.
	Super::Tick(_deltaTime);

	spawnHitbox(EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX, FVector(0, 0, -80), FVector(.5f, .5f, 1.5f), 0);
	spawnHitbox(EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX, FVector(0, 0, -60), FVector(.35f, .35f, 1.25f), 0);
}





