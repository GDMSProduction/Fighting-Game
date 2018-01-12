// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Super80sFighterGameMode.h"
#include "Super80sFighterCharacter.h"
#include "UObject/ConstructorHelpers.h"

void ASuper80sFighterGameMode::BeginPlay()
{
	Super::BeginPlay();

	ASuper80sFighterCharacter* Player1 = Cast<ASuper80sFighterCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	ASuper80sFighterCharacter* Player2 = Cast<ASuper80sFighterCharacter>(UGameplayStatics::CreatePlayer(this, 1));
	Player2 = Cast<ASuper80sFighterCharacter>(UGameplayStatics::GetPlayerPawn(this, 1));

	Player1->SetOtherPlayer(Player2);
	Player2->SetOtherPlayer(Player1);

	//if (PlayerHUDClass != nullptr)
	//{
	//	PlayerWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHUDClass);
	//
	//	if (PlayerWidget != nullptr)
	//	{
	//		PlayerWidget->AddToViewport();
	//	}
	//}
}

ASuper80sFighterGameMode::ASuper80sFighterGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
