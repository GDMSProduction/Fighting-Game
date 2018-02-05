// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Core.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "Super80sFighterCharacter.h"
#include "Super80sFighterGameMode.generated.h"

UCLASS(minimalapi)
class ASuper80sFighterGameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	ASuper80sFighterGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pause")
	bool victory;

	unsigned int num_rounds;
	unsigned int rounds_remaining;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stats", Meta = (BlueprintProtected = "true", DisplayName = "Stats"))
		TSubclassOf<class UUserWidget> PlayerHUDClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Players", Meta = (BlueprintProtected = "true", DisplayName = "Players"))
		TSubclassOf<class ASuper80sFighterCharacter> ThugClass;

	UPROPERTY()
		class UUserWidget* PlayerWidget;

private:
	class ASuper80sFighterCharacter *Player1, *Player2;
	APlayerController *p1_controller, *p2_controller;
	unsigned int Player1_round_wins;
	unsigned int Player2_round_wins;
	bool on_death_pause;
	bool first_time;
	float death_timer;

	void endRound(bool p1_win);
	void endGame();
};



