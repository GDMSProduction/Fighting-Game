// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AIBase.h"
#include "AIManager.generated.h"

UCLASS()
class SUPER80SFIGHTER_API AAIManager : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Sets default values for this actor's properties
	AAIManager();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	std::vector<AIBase> AIs;
};
