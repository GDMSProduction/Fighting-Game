// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Core.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "Super80sFighterCharacter.h"
#include "Super80sFighterGameMode.generated.h"

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

#pragma region Console Commands
	UFUNCTION(Exec, Category = "Stats")
		void ResetInputs();
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
};



