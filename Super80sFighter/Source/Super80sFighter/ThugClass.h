//Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Super80sFighterCharacter.h"
#include "ThugClass.generated.h"

UCLASS()
class SUPER80SFIGHTER_API AThugClass : public ASuper80sFighterCharacter
{
	GENERATED_BODY()

private:
	//The current difficulty level.
	short difficultyLevel = 0;

	//The randomly chosen moveset.
	short movesetNumber = 0;

	//The array of inputs for the thug to use.
	TArray<short> inputsToUse;

protected:
	enum Moves
	{
		MOVEFORWARD,
		MOVEBACKWARD,
		HOP,
		JUMP,
		CROUCH,
		PUNCH,
		KICK,
		SPECIAL1,
		SPECIAL2,
		SPECIAL3,
		SPECIAL4
	};

	//Set up the thug's functionality.
	void SetUpThug();

	//Determine the moves the thug will have available to them.
	void DetermineMoveSet(TArray<short>& _inputsToUse, short _difficultyLevel);

	//Choose the next move for the thug to perform.
	void ChooseNextMove();

public:
	//Increment the timer, called every frame.
	virtual void Tick(float _deltaTime) override;
};
