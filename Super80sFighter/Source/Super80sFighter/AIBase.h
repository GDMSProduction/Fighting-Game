// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>



/**
 * 
 */
class SUPER80SFIGHTER_API AIBase
{
public:
	std::vector<void * > moves;


	AIBase();
	~AIBase();

	
	 virtual void decide() = 0;


	 virtual void decideAttack() = 0;


	
};
