//Fill out your copyright notice in the Description page of Project Settings.
#include "ThugClass.h"

//The default constructor.
AThugClass::AThugClass()
{
	
}

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
	DetermineMoveSet(inputsToUse, difficultyLevel);
}

//Determine the moves the thug will have available to them.
void AThugClass::DetermineMoveSet(TArray<short>& _inputsToUse, short _difficultyLevel)
{
	//Get the random moveset for the thug to use.
	movesetNumber = rand() % TOTALMOVESETS;

	switch (movesetNumber)
	{
	case 0:
		isAttacking[0] = true;
		isAttacking[1] = true;
		isAttacking[2] = true;
		isAttacking[3] = true;
		isAttacking[4] = false;
		isAttacking[5] = false;
		isAttacking[6] = false;
		isAttacking[7] = false;
		break;

	case 1:
		isAttacking[0] = false;
		isAttacking[1] = false;
		isAttacking[2] = false;
		isAttacking[3] = false;
		isAttacking[4] = true;
		isAttacking[5] = true;
		isAttacking[6] = true;
		isAttacking[7] = true;
		break;
	}

	//Determine the stage the player is on.
	switch (_difficultyLevel)
	{
	//Easy difficulty.
	case 0:
		_inputsToUse.Add(SPECIAL1);
		break;

	//Medium difficulty.
	case 1:
		_inputsToUse.Add(SPECIAL1);
		_inputsToUse.Add(SPECIAL2);
		_inputsToUse.Add(SPECIAL3);
		break;

	//Hard difficulty.
	case 2:
		_inputsToUse.Add(SPECIAL1);
		_inputsToUse.Add(SPECIAL2);
		_inputsToUse.Add(SPECIAL3);
		_inputsToUse.Add(SPECIAL4);
		break;

	//No difficulty.
	default:
		break;
	}
}

//Choose the next move for the thug to perform.
void AThugClass::ChooseNextMove()
{

}

//Increment the timer, called every frame.
void AThugClass::Tick(float _deltaTime)
{
	//Use the parent's timer to perform the tick.
	Super::Tick(_deltaTime);
}





