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
	enum Moves
	{
		MOVE,
		JUMP,
		CROUCH,
		PUNCH,
		KICK
	};

protected:
	//The array of inputs for the thug to use.
	TArray<short> inputsToUse;

	//Determine the moves the thug will have available to them.
	void DetermineMoveSet(TArray<short>& _inputsToUse, short _stage);

public:
	//Increment the timer, called every frame.
	virtual void Tick(float _deltaTime) override;
};
