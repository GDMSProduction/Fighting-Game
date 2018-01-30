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

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Settings")
	unsigned int num_rounds;
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Game Settings")
	unsigned int rounds_remaining;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stats", Meta = (BlueprintProtected = "true", DisplayName = "Stats"))
		TSubclassOf<class UUserWidget> PlayerHUDClass;

	UPROPERTY()
		class UUserWidget* PlayerWidget;

private:
	class ASuper80sFighterCharacter *Player1, *Player2;
	unsigned int Player1_round_wins;
	unsigned int Player2_round_wins;

	void endRound(bool p1_win);
	void endGame();
};



