// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

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
#include "Super80sFighterCharacter.generated.h"

UCLASS(config = Game)
class ASuper80sFighterCharacter : public ACharacter
{
	GENERATED_BODY()

		/** Side view camera */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

protected:

	UFUNCTION(BlueprintCallable, Category = "Hellothere")
	AHitbox* spawnHitbox(EHITBOX_TYPE type, FVector offset, FVector dimensions, float damage);
	class AHitbox* tempHitbox;

	/** Called for side to side input */
	void MoveRight(float Val);

#pragma region Brennans Functions
	void Attack0();
	void Attack1();
	void Attack2();
	void Attack3();
	void QueStopAttacking();

	void StartCrouch();
	void StopCrouch();

	void PressShortHop();
	void ReleaseShortHop();
	void PressHighJump();
	void ReleaseHighJump();
	void PressNormalJump();
	void ReleaseNormalJump();

	void PressJump();
	void ReleaseJump();
	void JumpReachesThreshold();

	//Mirrors the character to face the other direction, keeping their front facing the players
	void FlipCharacter();
	void FlipCharacter(bool forceFaceRight);

	enum ATTACK_TYPE
	{
		ATTACK_0,
		ATTACK_1,
		ATTACK_2,
		ATTACK_3,
		NUM_ATTACKS
	};
	void AddAttack(ATTACK_TYPE incomingAttack);
#pragma endregion
	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

private:
	/**Player Total Stamina*/
	UPROPERTY(EditAnywhere, Category = "Stats")
	float TotalStamina;

	/**Player Current Stamina*/
	UPROPERTY(EditAnywhere, Category = "Stats")
	float CurrentStamina;

	/**Player Total Health*/
	UPROPERTY(EditAnywhere, Category = "Stats")
	float TotalHealth;

	/**Player Current Health*/
	UPROPERTY(EditAnywhere, Category = "Stats")
	float CurrentHealth;

	UPROPERTY(VisibleAnywhere, Category= "Hitboxes")
	TArray<AHitbox*> hitboxes;

	UPROPERTY(VisibleAnywhere, Category = "Orientation")
	bool IsFacingRight;

public:
	ASuper80sFighterCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

#pragma region Controlling Variables
	//Attacking variables
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	bool isAttacking0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isAttacking1;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isAttacking2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isAttacking3;



	//Movement Variables
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	bool isCrouching;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	bool isHoldingJump;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		float CustomHighJumpVelocity;//Demo jump velocity was 1000.0f
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		float CustomShortJumpVelocity;

	
#pragma region Jumping Variables
	FTimerHandle JumpTimer;
	bool HasJumpReachedThreshold;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float JumpThreshold;
#pragma endregion

#pragma region Combo variables


	TArray<ATTACK_TYPE> last5Attacks;
#pragma endregion


#pragma endregion

	/**Accessor function for Total Stamina*/
	UFUNCTION(BlueprintPure, Category = "Stats")
	float GetTotalStamina();

	/**Accessor function for Current Stamina*/
	UFUNCTION(BlueprintPure, Category = "Stats")
	float GetCurrentStamina();

	/**Updates the Players Current Stamina
	* @param Stamina Amount to change Stamina by(Posivive or Negative).
	*/
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void UpdateCurrentStamina(float Stamina);

	/**Accessor function for Total Health*/
	UFUNCTION(BlueprintPure, Category = "Stats")
	float GetTotalHealth();

	/**Accessor function for Current Health*/
	UFUNCTION(BlueprintPure, Category = "Stats")
	float GetCurrentHealth();

	

	/**Updates the Players Current Stamina
	* @param Health Amount to change Stamina by(Posivive or Negative).
	*/
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void UpdateCurrentHealth(float Health);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void TakingDamage();

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SuperAbility();

	virtual void Tick(float DeltaTime) override;
};
