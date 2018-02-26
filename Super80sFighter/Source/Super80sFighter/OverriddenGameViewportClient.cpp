// Fill out your copyright notice in the Description page of Project Settings.

#include "OverriddenGameViewportClient.h"

bool UOverriddenGameViewportClient::InputKey(FViewport* Viewport, int32 ControllerId, FKey Key, EInputEvent EventType, float AmountDepressed, bool bGamepad)
{
	ASuper80sFighterGameMode* gameMode = (ASuper80sFighterGameMode*)GetWorld()->GetAuthGameMode();

	if (!gameMode->GetIsKeyboardMode()) {
		return Super::InputKey(Viewport, ControllerId, Key, EventType, AmountDepressed, bGamepad);
	} else {
		if (IgnoreInput() || bGamepad || Key.IsMouseButton())
		{
			return Super::InputKey(Viewport, ControllerId, Key, EventType, AmountDepressed, bGamepad);
		}
		else
		{
			// Propagate keyboard events to all players
			UEngine* const Engine = GetOuterUEngine();
			int32 const NumPlayers = Engine ? Engine->GetNumGamePlayers(this) : 0;//Another one of those Error but not really errors
			bool bRetVal = false;
			for (int32 i = 0; i < NumPlayers; i++)
			{
				bRetVal = Super::InputKey(Viewport, i, Key, EventType, AmountDepressed, bGamepad) || bRetVal;
			}

			return bRetVal;
		}
	}
}
