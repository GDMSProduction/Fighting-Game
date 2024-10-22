//Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "Runtime/Engine/Classes/Animation/AnimNode_StateMachine.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/InputSettings.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerState.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerInput.h"
#include "Runtime/Engine/Classes/Animation/AnimInstance.h"
#include <typeinfo>
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
#include "../Core/Public/HAL/FileManager.h"
#include "../Core/Public/HAL/PlatformFilemanager.h"
#include "../Core/Public/HAL/UnrealMemory.h"
#include "Super80sFighterCharacter.generated.h"

#pragma region Score
//The scoring system for end-match results.
USTRUCT(BlueprintType)
struct FScoreSystem
{
	GENERATED_USTRUCT_BODY()

	//The total score of the match for the player.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	int totalScore;

	//The amount of time remaining after each round.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float timeRemaining;

	//The amount of health remaining after each round.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float healthRemaining;

	//The number of landed punches and kicks throughout the match.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float numHits;

	//The number of landed heavy attacks throughout the match.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float numHeavyHits;

	//The number of landed special attacks throughout the match.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float numSpecialHits;

	//The number of landed special attacks throughout the match.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float numTaunts;

	//The amount of blocked attacks after each round.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float numAttacksBlocked;

	//Was the round a perfect round for the player?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	bool perfectRound;

	//Was the game a win-perfect game for the player?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	bool winPerfectGame;

	//Was the round won with a special finish?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	bool specialFinish;
};
#pragma endregion

UCLASS(config = Game)
class AFighterParent : public ACharacter
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
		AHitbox* spawnHitbox(EHITBOX_TYPE type, FVector offset, FVector dimensions, float damage, float stamina_cost, bool visible = true);
	UPROPERTY()
		class AHitbox* tempHitbox;
#pragma endregion
#pragma region Input

	virtual void PressRight();
	virtual void PressLeft();
	virtual void ReleaseRight();
	virtual void ReleaseLeft();

	virtual void PressPunch();
	virtual void PressKick();
	virtual void PressHeavy();
	virtual void PressSpecial();

	void PressPunchAndKick();
	void PressKickAndSpecial();

	virtual void ReleasePunch();
	virtual void ReleaseKick();
	virtual void ReleaseHeavy();
	virtual void ReleaseSpecial();

	void ReleasePunchAndKick();
	void ReleaseKickAndSpecial();

	virtual void StartCrouch();
	virtual void StopCrouch();

	void PressShortHop();
	void ReleaseShortHop();
	void PressHighJump();
	void ReleaseHighJump();
	void PressNormalJump();
	void ReleaseNormalJump();

	virtual void PressJump();
	virtual	void ReleaseJump();
	template <class C>
	void PressUp()
	{
		AddInput<C>(INPUT_TYPE::UP, true, FApp::GetCurrentTime());
	};
	template <class C>
	void ReleaseUp()
	{
		AddInput<C>(INPUT_TYPE::UP, false, FApp::GetCurrentTime());
	};

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

	virtual void QueStopAttacking();
	void JumpReachesThreshold();
	//Call this every time a new input is given. 
	//This will go through the command list (the inputs list) and check to see if there is a matching command. 
	//If there is, it calls the appropriate function to indicate that the player controller wishes to use the set command. 
	//The animation and event graphs will manage these commands to know how to deal with those commands

	virtual void CheckCommand();
	//This clears the list of inputs. Its called when an attack isn't input for a certain amount of time.
	virtual void ClearCommands();

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
	template <class C>
	struct Command
	{
		TArray<ButtonSet> InputsForCommand;

		void (C::*functionToCall)();

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

	TArray<Command<AFighterParent>> CommandList;
	template <class C>
	void AddCommand(TArray<Command<C>> &CommandListToModify, TArray<ButtonSet> InputsForCommand, void(C::*functionToCall)()) {
		Command<C> tempCommand;
		tempCommand.functionToCall = functionToCall;
		tempCommand.InputsForCommand = InputsForCommand;
		CommandListToModify.Add(tempCommand);
	};
	template <class C>
	void AddInput(INPUT_TYPE incomingAttack, bool wasPressed, double timeOfPress)
	{
		ButtonBufferInput tempInput;
		tempInput.Buttons = incomingAttack;
		tempInput.isPress = wasPressed;
		tempInput.timeOfInput = timeOfPress;
		buttonBuffer.Add(tempInput);
		if (buttonBuffer.Num() > 10)
			buttonBuffer.RemoveAt(buttonBuffer.Num() - 1);
		CheckCommand();

		GetWorld()->GetTimerManager().SetTimer(AttackTimer, this, &AFighterParent::ClearCommands, AttackThreshold);
	};
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
	AFighterParent* EnemyPlayer;
protected:
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

	UPROPERTY(BlueprintReadWrite, Category = "Orientation")
		bool IsFacingRight;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		int initialSelector;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		int initialCounter;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		int initial2Counter;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		int initial3Counter;

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

	////testing shit
	//int total_memory_cost = 0;

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
	TArray<Command<AFighterParent>> AlreadyCalledCommands;
	FTimerHandle AttackTimer;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	int comboCounter;

protected:
	float AttackThreshold;
	float BlockThreshold;
	double lastHit;
	double samePressThreshold;//Used to determine if two button presses should be considered simultaneous
#pragma endregion

#pragma region AI
public:
	bool what_is_my_purpose = false;

	//variables for getting data out of hitboxes
	bool save_hitbox_data = false;
	bool first_save = true;
	int attack_saved_bool_32 = INT_MAX;

	//index of the last called function
	int last_called_attack_index = -1;


	//notification functions for attacks
	virtual void notify_incoming_attack(int attack_index);
	virtual void notify_attack_ending();

protected:
	enum PlayerState : uint32
	{
		NEUTRAL   = (1 << 0),
		JUMPING   = (1 << 1),
		CROUCHING = (1 << 2),
		BLOCKING  = (1 << 3),
		ATTACKING = (1 << 4),
		STUNNED   = (1 << 5)
	};
	struct save_cast
	{
		double a, b;
	};
	struct Move_Data
	{
		int command_list_index;
		int combo_potential;
		int damage;
		int past_success;
		int past_attempt;
		int stamina_cost;
		int timeframe_cost;
	};
	struct Player_Data
	{
		PlayerState PlayerState;
		TArray<Move_Data> Move_Data;
	};

	//movement variables
	FVector enemy_previous_location;
	float prev_distance = 0;
	float curr_distance = 0;
	FVector left_boundary;
	FVector right_boundary;
	bool attack_incoming = false;

	void decide();
	virtual void initialize_move_data(); //change file path and move data templated type
	virtual void decide_movement();

	//overridable functions for saving out the data
	virtual void deleteOldSaveData(IPlatformFile& PlatformFile); //children should change the file name but otherwise do the function exactly the same
	virtual void saveHitboxData(float stamina_cost); //children should change the file path
	virtual void set_last_called_attack_index(int _index);

	float distance(FVector a, FVector b);
	float fast_sqrt(float num);
#pragma endregion

protected:
	//attack data and locations
	Player_Data my_player_data;

public:
#pragma region Camera Set-Up
	AFighterParent();

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

	void SetOtherPlayer(AFighterParent* OtherPlayer);

	float Block(float _damage);
	float CrouchBlock(float _damage);

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
	//Creates an event that fires off in blueprints.
	UFUNCTION(BlueprintImplementableEvent, Category = "Hitboxes")
		void TakeDamageBlueprintEvent();

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




