//Fill out your copyright notice in the Description page of Project Settings.
#pragma region Includes
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Source/Super80sFighter/Hitbox.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/Animation/AnimInstance.h"
#include "Runtime/Engine/Classes/Animation/AnimNode_StateMachine.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include <vector.h>
#include "EngineUtils.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerState.h"
#include "EngineGlobals.h"
#include "Super80sFighterCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "ThugClass.generated.h"
#pragma endregion

UCLASS()
class SUPER80SFIGHTER_API AThugClass : public AFighterParent
{
	GENERATED_BODY()

private:
#pragma region Ability Variables
	//The attack/movement statuses.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove2;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove3;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove4;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove5;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove6;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove7;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove8;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove9;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove10;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove11;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove12;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove13;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove14;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove15;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove16;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove17;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove18;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove19;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove20;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove21;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove22;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove23;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove24;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove25;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isMove26;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isCrouched;
#pragma endregion

#pragma region Random
	//The total number of movesets.
	const short TOTALMOVESETS = 3;

	//The total number of moves for the current moveset.
	const short TOTALMOVES = 9;

	//The current difficulty level.
	short difficultyLevel = 0;

	//The randomly chosen moveset.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		int movesetNumber;

	//The array of inputs for the thug to use.
	TArray<short> inputsToUse;
#pragma endregion

protected:
#pragma region AI Set-Up
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
#pragma endregion

public:
#pragma region Construction
	//The default constructor for the thug.
	AThugClass();
#pragma endregion

#pragma region Update
	//Increment the timer, called every frame.
	virtual void Tick(float _deltaTime) override;
#pragma endregion
};
