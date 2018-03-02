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
	//virtual void PressLeft() override;
	//virtual void ReleaseRight() override;
	//virtual void ReleaseLeft() override;
	//
	//virtual void PressPunch() override;
	//virtual void PressKick() override;
	//virtual void PressHeavy() override;
	//virtual void PressSpecial() override;
	//
	//virtual void PressPunchAndKick() override;
	//virtual void PressKickAndSpecial() override;
	//
	//virtual void ReleasePunch() override;
	//virtual void ReleaseKick() override;
	//virtual void ReleaseHeavy() override;
	//virtual void ReleaseSpecial() override;
	//
	//virtual void ReleasePunchAndKick() override;
	//virtual void ReleaseKickAndSpecial() override;
	//
	//virtual void StartCrouch() override;
	//virtual void StopCrouch() override;
	//
	//virtual void PressShortHop() override;
	//virtual void ReleaseShortHop() override;
	//virtual void PressHighJump() override;
	//virtual void ReleaseHighJump() override;
	//virtual void PressNormalJump() override;
	//virtual void ReleaseNormalJump() override;
	//
	//virtual void PressJump() override;
	//virtual	void ReleaseJump() override;
	void testFunc();
	virtual void CheckCommand()  override;
};
