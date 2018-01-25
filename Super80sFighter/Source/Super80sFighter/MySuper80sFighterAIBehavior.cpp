//Fill out your copyright notice in the Description page of Project Settings.
#include "MySuper80sFighterAIBehavior.h"

//Increment the timer, called every frame.
void AMySuper80sFighterAIBehavior::Do()
{
	Super::PressPunch();
}

void AMySuper80sFighterAIBehavior::Dont(int blarb)
{
	int x = 0;
}

//Increment the timer, called every frame.
void AMySuper80sFighterAIBehavior::Tick(float DeltaTime)
{
	//Increment the timer, called every frame.
	Super::Tick(DeltaTime);

	Do();
}





