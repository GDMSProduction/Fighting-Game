// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Super80sFighterGameMode.h"
#include "ThugClass.h"
#include "UObject/ConstructorHelpers.h"

void ASuper80sFighterGameMode::BeginPlay()
{
	Super::BeginPlay();

	p1_controller = UGameplayStatics::GetPlayerController(this, 0);
	Player1 = Cast<ASuper80sFighterCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	p2_controller = UGameplayStatics::CreatePlayer(this, 1);
	Player2 = Cast<ASuper80sFighterCharacter>(UGameplayStatics::GetPlayerPawn(this, 1));

	//variables required for spawning a character as a different type
	UWorld* const world = GetWorld();
	FActorSpawnParameters spawn_parameters = FActorSpawnParameters();
	FVector pos;
	FRotator rot = FRotator(0, -90, 0);
	ASuper80sFighterCharacter* temp;
	//change player 1
	switch (p1_type)
	{
	case ECharacterEnum::CLASS_DEFAULT:
		//do nothing, characters already spawn as base classes
		break;
	case ECharacterEnum::CLASS_THUG:
		pos = Player1->GetTransform().GetLocation();
		spawn_parameters.bDeferConstruction = true;
		p1_controller->UnPossess();
		Player1->destroy();
		temp = world->SpawnActor<AThugClass>(ThugClass, pos, rot, spawn_parameters);
		UGameplayStatics::FinishSpawningActor(temp, temp->GetTransform());
		Player1 = temp;
		p1_controller->Possess(Player1);
		break;
	default:
		break;
	}
	switch (p2_type)
	{
	case ECharacterEnum::CLASS_DEFAULT:
		//do nothing, this is default pawn
		break;
	case ECharacterEnum::CLASS_THUG:
		pos = Player2->GetTransform().GetLocation();
		spawn_parameters.bDeferConstruction = true;
		p2_controller->UnPossess();
		Player2->destroy();
		temp = world->SpawnActor<AThugClass>(ThugClass, pos, rot, spawn_parameters);
		UGameplayStatics::FinishSpawningActor(temp, temp->GetTransform());
		Player2 = temp;
		p2_controller->Possess(Player2);
		break;
	default:
		break;
	}

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
	first_time = true;
}

void ASuper80sFighterGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (on_death_pause)
	{
		death_timer -= DeltaTime;
		if (death_timer <= 0)
			on_death_pause = false;
	}
	if (Player1->GetCurrentHealth() <= 0)
	{
		Player1->SetDead(true);
		Player2->SetDead(false);
		if (first_time)
		{
			on_death_pause = true;
			death_timer = 3.0f;
			first_time = false;
		}
		if(!on_death_pause)
			endRound(false);
	}
	else if (Player2->GetCurrentHealth() <= 0)
	{
		Player1->SetDead(false);
		Player2->SetDead(true);
		if (first_time)
		{
			on_death_pause = true;
			death_timer = 3.0f;
			first_time = false;
		}
		if (!on_death_pause)
			endRound(true);
	}
	else if (round_draw)
	{
		Player2->SetDead(true);
		Player1->SetDead(true);
		if (first_time)
		{
			on_death_pause = true;
			death_timer = 3;
			first_time = false;
		}
		if (!on_death_pause)
			internal_draw();
	}
	else
	{
		Player2->SetDead(false);
		Player1->SetDead(false);
	}
}

ASuper80sFighterGameMode::ASuper80sFighterGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FObjectFinder<UBlueprint> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/Character/ThugClassBlueprint"));
	PrimaryActorTick.bCanEverTick = true;
	if (PlayerPawnBPClass.Object != NULL)
	{
		ThugClass = (UClass*)PlayerPawnBPClass.Object->GeneratedClass;
	}
	num_rounds = 1;
	rounds_remaining = num_rounds;
}

void ASuper80sFighterGameMode::draw()
{
	round_draw = true;

}

void ASuper80sFighterGameMode::endRound(bool p1_win)
{
	rounds_remaining--;
	if (p1_win)
	{
		Player1_round_wins++;
	}
	else
	{
		Player2_round_wins++;
		
	}
	if (rounds_remaining == 0)
		endGame();

	Player1->SetActorLocation(Player1->startLocation);
	Player1->ResetHealth();
	Player1->ResetStamina();
	Player2->SetActorLocation(Player2->startLocation);
	Player2->ResetHealth();
	Player2->ResetStamina();
	first_time = true;
	on_death_pause = false;

	UE_LOG(LogTemp, Warning, TEXT("%d"), rounds_remaining);
}

void ASuper80sFighterGameMode::internal_draw()
{
	Player1->SetActorLocation(Player1->startLocation);
	Player1->ResetHealth();
	Player1->ResetStamina();
	Player2->SetActorLocation(Player2->startLocation);
	Player2->ResetHealth();
	Player2->ResetStamina();
	first_time = true;
	on_death_pause = false;
	round_draw = false;
}

void ASuper80sFighterGameMode::endGame()
{
	//add buttons to screen for replay, return to character select, back to main menu
	UE_LOG(LogTemp, Error, TEXT("ERRROR: ENDGAME FUNCTION NOT YET IMPLEMENTED YOU IDIOT (not you gracious player but the idiot that developed this)"));
	paused = true;
}
