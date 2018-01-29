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
#include "EngineUtils.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerState.h"
#include "EngineGlobals.h"
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

	UFUNCTION(BlueprintCallable, Category = "Hitboxes")
	AHitbox* spawnHitbox(EHITBOX_TYPE type, FVector offset, FVector dimensions, float damage);
	UPROPERTY()
	class AHitbox* tempHitbox;

	/** Called for side to side input */
	void MoveRight(float Val);



#pragma region Input Functions



	void PressPunch();
	void PressKick();
	void PressHeavy();
	void PressSpecial();
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
#pragma region Variable Manipulation in relation to inputs
	void QueStopAttacking();
	void JumpReachesThreshold();
	//Call this every time a new input is given. 
	//This will go through the command list (the inputs list) and check to see if there is a matching command. 
	//If there is, it calls the appropriate function to indicate that the player controller wishes to use the set command. 
	//The animation and event graphs will manage these commands to know how to deal with those commands
	void CheckCommand();
	//This clears the list of inputs. Its called when an attack isn't input for a certain amount of time.
	void ClearCommands();

	enum INPUT_TYPE
	{
		PUNCH,
		KICK,
		HEAVY,
		SPECIAL,
		LEFT,
		RIGHT,
		UP,
		DOWN,
		NUM_ATTACKS
	};
	struct INPUT {
		INPUT_TYPE inputType;
		bool wasHeld;
		 bool operator==(const INPUT& test, const INPUT& test2) {
			if (test.inputType != this->inputType)
				return false;
			if (test.wasHeld != this->wasHeld)
				return false;

			return true;
		}
		bool operator !=(const INPUT& test) {
			return !(test == *this);
		}
	};

	struct Command
	{
		TArray<INPUT> InputsForCommand;
		void(ASuper80sFighterCharacter::*functionToCall)();

		
	};
	TArray<Command> CommandList;
	void AddCommand(TArray<INPUT> InputsForCommand, void(ASuper80sFighterCharacter::*functionToCall)());
	void AddInput(INPUT_TYPE incomingAttack, bool wasHeld);
#pragma endregion
#pragma endregion
#pragma region Attacks
	void Attack0();
	void Attack1();
	void Attack2();
	void Attack3();
#pragma endregion


	//Mirrors the character to face the other direction, keeping their front facing the players
	void FlipCharacter();
	//Sets their direction, regardless of their previous orientation. 
	//Args:
	//forceFaceRight - Set this to true if they should face right, or false to face left
	void FlipCharacter(bool forceFaceRight);



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

	ASuper80sFighterCharacter* EnemyPlayer;

	/**dave cranes private physics variables, if they're screwy, its entirely his fault*/
	UPROPERTY(VisibleAnywhere, Category = "Physics")
	bool grounded;
	bool lock_grounded;

	FVector grounded_forces;
	FVector non_grounded_forces;
	FVector absolute_forces;

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
	TArray<INPUT> inputBuffer;
	FTimerHandle AttackTimer;

	float AttackThreshold;
#pragma endregion


#pragma endregion
#pragma region Testing
	void PrintMessage();
#pragma endregion


	void SetOtherPlayer(ASuper80sFighterCharacter* OtherPlayer);

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

	UFUNCTION(BlueprintCallable, Category = "Collision")
	void onHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	/**Updates the Players Current Stamina
	* @param Health Amount to change Stamina by(Posivive or Negative).
	*/
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void UpdateCurrentHealth(float Health);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void TakeDamage(float damage);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SuperAbility();

	virtual void Tick(float DeltaTime) override;
};
