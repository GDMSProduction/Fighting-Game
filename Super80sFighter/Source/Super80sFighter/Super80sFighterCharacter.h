//Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "Runtime/Engine/Classes/Animation/AnimNode_StateMachine.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/InputSettings.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerState.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerInput.h"
#include "Runtime/Engine/Classes/Animation/AnimInstance.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "GameFramework/SpringArmComponent.h"
#include "../Source/Super80sFighter/Hitbox.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "EngineGlobals.h"
#include "EngineUtils.h"
#include "CoreMinimal.h"
#include "Super80sFighterCharacter.generated.h"

#pragma region Score
//The scoring system for end-match results.
USTRUCT(BlueprintType)
struct FScoreSystem
{
	GENERATED_USTRUCT_BODY()

	//The average number of landed attacks throughout the match.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float numHitsAverage;

	//The average amount of time remaining after each round.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float timeRemainingAverage;

	//The average amount of damage performed per attack.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float damageDealtAverage;

	//The average amount of damage received after each round.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float damageTakenAverage;

	//The average amount of blocked damage after each round.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float damageBlockedAverage;
};
#pragma endregion

UCLASS(config = Game)
class ASuper80sFighterCharacter : public ACharacter
{
#pragma region Blueprint Defaults
	GENERATED_BODY()

		/** Side view camera */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

protected:

	UFUNCTION(BlueprintCallable, Category = "Hitboxes")
		AHitbox* spawnHitbox(EHITBOX_TYPE type, FVector offset, FVector dimensions, float damage, bool visible = true);
	UPROPERTY()
		class AHitbox* tempHitbox;
#pragma endregion
#pragma region Input

	void PressRight();
	void PressLeft();
	void ReleaseRight();
	void ReleaseLeft();

	void PressPunch();
	void PressKick();
	void PressHeavy();
	void PressSpecial();

	void ReleasePunch();
	void ReleaseKick();
	void ReleaseHeavy();
	void ReleaseSpecial();

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

	//Count the current combo for the fighter.
	void ComboCounter();

	/** Called for side to side input */
	void MoveRight(float Val);
	void MoveLeft(float Val);

	FKey LastPressedKey;
	UFUNCTION(BlueprintCallable, Category = "Controls")
		void SetLastPressedKey(FKey inKey);

	UFUNCTION(BlueprintCallable, Category = "Controls")
		FKey GetLastPressedKey();
#pragma region Command System
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

	//These are the wrapper for various inputs used to makeup a command. They are a input type, and if it should be held or not
	struct ButtonInput 
	{
		INPUT_TYPE button;
		bool wasHeld;

		bool operator ==(const ButtonInput& test) {
			if (test.button != button)
				return false;
			if (test.wasHeld != wasHeld)
				return false;

			return true;
		}
	};
	struct ButtonSet {
		TArray<ButtonInput> inputs;
		bool operator==(const ButtonSet& test) {
			if (test.inputs.Num() != inputs.Num())
				return false;

			for (int i = 0; i < inputs.Num(); i++)
			{
				bool found = false;
				for (int j = 0; j < test.inputs.Num(); j++)
				{
					if (inputs[i] == test.inputs[j])
						found = true;
				}
				if (!found)
					return false;
			}



			return true;
		}
		bool operator !=(const ButtonSet& test) {
			return !(*this == test);
		}
		void Clear() {
			while (inputs.Num() > 0)
				inputs.RemoveAt(0);
		}
	};
	//This is for input buffer, which is used to determine if inputs are held or tapped
	struct ButtonBufferInput {
		INPUT_TYPE Buttons;
		bool isPress;
		double timeOfInput;
	};
	struct Command
	{
		TArray<ButtonSet> InputsForCommand;
		void(ASuper80sFighterCharacter::*functionToCall)();

		bool operator==(const Command &test) {
			if (InputsForCommand.Num() != test.InputsForCommand.Num())
				return false;
			for (int i = 0; i < InputsForCommand.Num(); i++)
				if (InputsForCommand[i] != test.InputsForCommand[i])
					return false;
			if (functionToCall != test.functionToCall)
				return false;

			return true;

		}
	};
	TArray<Command> CommandList;
	void AddCommand(TArray<ButtonSet> InputsForCommand, void(ASuper80sFighterCharacter::*functionToCall)());
	void AddInput(INPUT_TYPE incomingAttack, bool wasPressed, double timeOfPress);
#pragma endregion
#pragma endregion
#pragma region Attacks
	void Attack0();
	void Attack1();
	void Attack2();
	void Attack3();
	void AttackTaunt();
#pragma endregion
#pragma region Initialization and Defaults
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

	APlayerController* GetPlayerController();

	public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	FScoreSystem playerScore;
#pragma endregion

private:
#pragma region Main Health and Stamina Variables
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

	UPROPERTY(VisibleAnywhere, Category = "Hitboxes")
		TArray<AHitbox*> hitboxes;

	UPROPERTY(VisibleAnywhere, Category = "Orientation")
		bool IsFacingRight;

	ASuper80sFighterCharacter* EnemyPlayer;

	FTimerHandle BlockTimer;
#pragma endregion
#pragma region Physics and Forces
	/**dave cranes private physics variables, if they're screwy, its entirely his fault*/
	UPROPERTY(VisibleAnywhere, Category = "Physics")
	bool grounded;
	bool lock_grounded;
	bool isDead;
	FVector grounded_forces;
	FVector non_grounded_forces;
	FVector absolute_forces;

	bool landedEffect;
	bool jumpEffect;

	//internal stamina variables
	float CurrentMaxStamina;
	bool regen_stamina;
	int health_tier;
	int stamina_tier;
#pragma endregion
#pragma region Combo Variables
	TArray<ButtonBufferInput> buttonBuffer;
	TArray<Command> AlreadyCalledCommands;
	FTimerHandle AttackTimer;

	public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	int comboCounter;

	private:
	float AttackThreshold;
	float BlockThreshold;
	double lastHit;
	double samePressThreshold;//Used to determine if two button presses should be considered simultaneous
#pragma endregion

public:
#pragma region Camera Set-Up
	ASuper80sFighterCharacter();

	FVector startLocation;

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
#pragma endregion
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
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isAttackingTaunt;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isBlocking = false;

	//Movement Variables
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isCrouching;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isHoldingJump;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		float CustomHighJumpVelocity;//Demo jump velocity was 1000.0f
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		float CustomShortJumpVelocity;

	double holdThreshold;//Time you have to hold for before a button is considered a hold-down instead of a tap

#pragma region Jumping Variables
	FTimerHandle JumpTimer;
	bool HasJumpReachedThreshold;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		float JumpThreshold;
#pragma endregion




#pragma endregion
#pragma region Main Health and Stamina Functions
	bool GetDead();
	void SetDead(bool willBeDead);

	void SetOtherPlayer(ASuper80sFighterCharacter* OtherPlayer);

	float Block(float _damage);

	void StopBlocking();

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

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void ResetHealth();
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void ResetStamina();

	UFUNCTION(BlueprintCallable, Category = "Collision")
		void onHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	/**Updates the Players Current Stamina
	* @param Health Amount to change Stamina by(Posivive or Negative).
	*/

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void UpdateCurrentHealth(float Health);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void takeDamage(float damage);
#pragma endregion
#pragma region Blueprint Events
	UFUNCTION(BlueprintImplementableEvent, Category = "Hitboxes")
		void TakeDamageBlueprintEvent();//Creates an event that fires off in blueprints

	UFUNCTION(BlueprintImplementableEvent, Category = "AttackEffects")
		void FirstAttackEffectBlueprintEvent();

	UFUNCTION(BlueprintImplementableEvent, Category = "AttackEffects")
		void SecondAttackEffectBlueprintEvent();

	UFUNCTION(BlueprintImplementableEvent, Category = "AttackEffects")
		void ThirdAttackEffectBlueprintEvent();

	UFUNCTION(BlueprintImplementableEvent, Category = "AttackEffects")
		void FourthAttackEffectBlueprintEvent();

	UFUNCTION(BlueprintImplementableEvent, Category = "MovementEffects")
		void JumpEffectBlueprintEvent();

	UFUNCTION(BlueprintImplementableEvent, Category = "MovementEffects")
		void HighJumpEffectBlueprintEvent();

	UFUNCTION(BlueprintImplementableEvent, Category = "MovementEffects")
		void LandEffectBlueprintEvent();

	UFUNCTION(BlueprintImplementableEvent, Category = "MovementEffects")
		void DashEffectBlueprintEvent();

	UFUNCTION(BlueprintImplementableEvent, Category = "HealthEffects")
		void BlockEffectBlueprintEvent();

	UFUNCTION(BlueprintImplementableEvent, Category = "HealthEffects")
		void DeathEffectBlueprintEvent();



#pragma endregion

#pragma region Fighter Regeneration and Abilities
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SuperAbility();

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SetStaminaRegen(bool tf);

	UFUNCTION(BlueprintCallable, Category = "Yo Mamma")
		void TauntStaminaRegen();

	UFUNCTION(BlueprintCallable, Category = "Destroying")
		virtual void destroy();
#pragma endregion
#pragma region Update
	virtual void Tick(float DeltaTime) override;
#pragma endregion
};
