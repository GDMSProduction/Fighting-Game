// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#pragma comment(lib, "Super80sFighterCharacter.lib")

#include "CoreMinimal.h"
#include "Super80sFighterCharacter.h"
#include "DebugCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SUPER80SFIGHTER_API ADebugCharacter : public AFighterParent
{
	GENERATED_BODY()


		ADebugCharacter();
	TArray<Command<ADebugCharacter>> CommandList;
	TArray<Command<ADebugCharacter>> AlreadyCalledCommands;
	virtual void PressRight() override;
	void testFunc();
	virtual void CheckCommand()  override;
};
