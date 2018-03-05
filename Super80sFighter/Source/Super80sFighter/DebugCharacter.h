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


	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;


#pragma region Input Functions
	virtual void PressRight() override;
	virtual void PressLeft() override;
	virtual void ReleaseRight() override;
	virtual void ReleaseLeft() override;

	virtual void PressPunch() override;
	virtual void PressKick() override;
	virtual void PressHeavy() override;
	virtual void PressSpecial() override;



	virtual void ReleasePunch() override;
	virtual void ReleaseKick() override;
	virtual void ReleaseHeavy() override;
	virtual void ReleaseSpecial() override;


	virtual void StartCrouch() override;
	virtual void StopCrouch() override;

	virtual void PressJump() override;
	virtual	void ReleaseJump() override;
#pragma endregion
#pragma region Attacks
#pragma region Attack Boolean
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool is_mid_jab;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool is_low_heel_kick;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool is_high_cross_punch;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool is_high_strong_uppercut;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool is_mid_cross_punch;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool is_mid_chasing_uppercut;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool is_mid_alt_hook;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool is_low_hook;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool is_high_lazy_overhead;
#pragma endregion


	void mid_jab();
	void low_heel_kick();
	void high_cross_punch();
	void high_strong_uppercut();
	void mid_cross_punch();
	void mid_chasing_uppercut();
	void mid_alt_hook();
	void low_hook();
	void high_lazy_overhead();

	virtual void QueStopAttacking() override;
#pragma endregion


	void testFunc();
	virtual void CheckCommand()  override;
};
