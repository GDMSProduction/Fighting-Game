// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Super80sFighterGameMode.h"
#include "Super80sFighterCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASuper80sFighterGameMode::ASuper80sFighterGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
