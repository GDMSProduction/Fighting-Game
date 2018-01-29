//Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Super80sFighterCharacter.h"
#include "MySuper80sFighterAIBehavior.generated.h"

UCLASS()
class SUPER80SFIGHTER_API AMySuper80sFighterAIBehavior : public ASuper80sFighterCharacter
{	
	
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Do")
		void Do();
	UFUNCTION(BlueprintCallable, Category = "Do")
		void Dont(int blarb);

	//Increment the timer, called every frame.
	virtual void Tick(float DeltaTime) override;
};
