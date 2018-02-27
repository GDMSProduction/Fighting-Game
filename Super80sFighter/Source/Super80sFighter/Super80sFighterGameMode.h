//Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "Core.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "Super80sFighterCharacter.h"
#include "Super80sFighterGameMode.generated.h"

#pragma region Defines
#define SRANK 12000
#define ARANK 10000
#define BRANK 8000
#define CRANK 5000
#pragma endregion

UENUM(BlueprintType)
enum class ECharacterEnum : uint8
{
	CLASS_DEFAULT		UMETA(DisplayName = "Base"),
	CLASS_THUG			UMETA(DisplayName = "Thug"),
	CLASS_TOBY			UMETA(DisplayName = "Toby")
};

UENUM(BlueprintType)
enum class EMenuState : uint8
{
	STATE_SPLASH		UMETA(DisplayName = "Splash"),
	STATE_MENU			UMETA(DisplayName = "Menu"),
	STATE_CHAR_SELECT	UMETA(DisplayName = "Character Select")
};

UENUM(BlueprintType)
enum class EInputTypes : uint8
{
	JUMP,
	CROUCH,
	LEFT,
	RIGHT,
	ATT1,
	ATT2,
	ATT3,
	ATT4,
	PUNCHANDKICK,
	KICKANDSPECIAL,
	NUMOFINPUTTYPES
};

USTRUCT(BlueprintType)
struct FHighScore
{
	GENERATED_USTRUCT_BODY()

	FString playerName;

	int score;

	UENUM(BlueprintType)
	enum class ERank : uint8
	{
		SRank			UMETA(DisplayName = "S-Rank"),
		ARank			UMETA(DisplayName = "A-Rank"),
		BRank			UMETA(DisplayName = "B-Rank"),
		CRank			UMETA(DisplayName = "C-Rank"),
		DRank			UMETA(DisplayName = "D-Rank"),
	} playerRank;
};

UCLASS(minimalapi)
class ASuper80sFighterGameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	ASuper80sFighterGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pause")
		bool paused;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rounds")
		int num_rounds = 3;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rounds")
		int rounds_remaining;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Characters")
		ECharacterEnum p1_type = ECharacterEnum::CLASS_DEFAULT;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Characters")
		ECharacterEnum p2_type = ECharacterEnum::CLASS_DEFAULT;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menu")
		EMenuState current_menu_state = EMenuState::STATE_SPLASH;



#pragma region Controls 
	UFUNCTION(BlueprintCallable, Category = "Controls")
		void OverrideKeyInput(FKey inputKey, FString InputName);

	UFUNCTION(BlueprintCallable, Category = "Controls")
		void OverrideAxisInput(FKey inputKey, FString InputName, float axisScaler, bool shouldWeErase);
	UFUNCTION(BlueprintCallable, Category = "Controls")
		FString ConvertKeyToString(FKey inKey);



	UFUNCTION(BlueprintCallable, Category = "Controls")
		FKey GetBindingKey(EInputTypes m_Type, bool isPlayer1);

	bool isKeyboardMode = false;
	UFUNCTION(BlueprintCallable, Category = "Controls")
		bool GetIsKeyboardMode();
	UFUNCTION(BlueprintCallable, Category = "Controls")
		void SetIsKeyboardMode(bool m_SetKeyboardMode);

#pragma region Console Commands
	UFUNCTION(Exec, Category = "Controls")
		void ResetInputs();
	UFUNCTION(BlueprintCallable, Category = "Controls")
		void ResetInputsWrapper();
#pragma endregion  
#pragma endregion


protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stats", Meta = (BlueprintProtected = "true", DisplayName = "Stats"))
		TSubclassOf<class UUserWidget> PlayerHUDClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Players", Meta = (BlueprintProtected = "true", DisplayName = "Players"))
		TSubclassOf<class ASuper80sFighterCharacter> ThugClass;

	UPROPERTY()
		class UUserWidget* PlayerWidget;

	UFUNCTION(BlueprintCallable, Category = "Rounds")
		void draw();

private:
	class ASuper80sFighterCharacter *Player1, *Player2;
	APlayerController *p1_controller, *p2_controller;

	FHighScore currentEntry;
	FHighScore highScores[10];

	int lastHighScoreEntryIndex = sizeof(highScores) / sizeof(highScores[0]);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rounds", Meta = (AllowPrivateAccess = "true"))
		int Player1_round_wins;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rounds", Meta = (AllowPrivateAccess = "true"))
		int Player2_round_wins;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rounds", Meta = (AllowPrivateAccess = "true"))
		bool on_death_pause;

	bool first_time;
	bool round_draw;
	float death_timer;

	void endRound(bool p1_win);
	void internal_draw();
	void endGame();
	void DetermineRank(int& _player1Score);
	void DetermineScoreboardPlacement(FHighScore& _currentPlayerEntry);
};



