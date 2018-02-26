// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "../../Source/Super80sFighter/Super80sFighterGameMode.h"
#include "OverriddenGameViewportClient.generated.h"

/**
 * 
 */
UCLASS()
class SUPER80SFIGHTER_API UOverriddenGameViewportClient : public UGameViewportClient
{
	GENERATED_BODY()
	
	
	
		virtual bool InputKey(FViewport* Viewport, int32 ControllerId, FKey Key, EInputEvent EventType, float AmountDepressed = 1.f, bool bGamepad = false) override;

};
