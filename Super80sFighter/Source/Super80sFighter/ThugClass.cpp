#pragma region Initialize
//Fill out your copyright notice in the Description page of Project Settings.
#include "ThugClass.h"

//The default constructor.
AThugClass::AThugClass()
{
	//Set up the Thug's functionality.
	SetUpThug();
}

//Set up the Thug's functionality.
void AThugClass::SetUpThug()
{
	//Add the default inputs for every Thug.
	inputsToUse.Add(MOVEFORWARD);
	inputsToUse.Add(MOVEBACKWARD);
	inputsToUse.Add(HOP);
	inputsToUse.Add(JUMP);
	inputsToUse.Add(CROUCH);
	inputsToUse.Add(PUNCH);
	inputsToUse.Add(KICK);

	//Determine the moves the Thug will have available to them.
	DetermineMoveSet(inputsToUse, difficultyLevel);
}

//Determine the moves the Thug will have available to them.
void AThugClass::DetermineMoveSet(TArray<short>& _inputsToUse, short _difficultyLevel)
{
	//Get the random moveset for the Thug to use.
	movesetNumber = rand() % TOTALMOVESETS;

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
#pragma endregion

#pragma region AIMoves
//Choose the next move for the Thug to perform.
void AThugClass::ChooseNextMove()
{
	//Get the random move for the Thug to use.
	int randomMove = rand() % TOTALMOVES;

	//Set the available moves to the Thug.
	switch (randomMove)
	{
	case 0:
		if (movesetNumber == 0)
		{
			isMove0 = true;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
		}

		else if (movesetNumber == 1)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = true;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
		}
		break;

	case 1:
		if (movesetNumber == 0)
		{
			isMove0 = false;
			isMove1 = true;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
		}

		else if (movesetNumber == 1)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = true;
			isMove6 = false;
			isMove7 = false;
		}
		break;

	case 2:
		if (movesetNumber == 0)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = true;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
		}

		else if (movesetNumber == 1)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = true;
			isMove7 = false;
		}
		break;

	case 3:
		if (movesetNumber == 0)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = true;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
		}

		else if (movesetNumber == 1)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = true;
		}
		break;

	default:
		break;
	}
}
#pragma endregion

#pragma region Update
//Increment the timer, called every frame.
void AThugClass::Tick(float _deltaTime)
{
	//Use the parent's timer to perform the tick.
	Super::Tick(_deltaTime);

	//Choose the next move for the Thug to perform.
	ChooseNextMove();
}
#pragma endregion




