// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Core.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "Super80sFighterGameMode.generated.h"

UCLASS(minimalapi)
class ASuper80sFighterGameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:
	ASuper80sFighterGameMode();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stats", Meta = (BlueprintProtected = "true", DisplayName = "Stats"))
		TSubclassOf<class UUserWidget> PlayerHUDClass;

	UPROPERTY()
		class UUserWidget* PlayerWidget;
};



