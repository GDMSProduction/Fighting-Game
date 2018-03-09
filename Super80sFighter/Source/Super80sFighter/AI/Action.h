// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <unordered_map>

class SUPER80SFIGHTER_API Action
{

	//variables
private:
	std::unordered_map<std::string, bool> preconditions;
	std::unordered_map<std::string, bool> effects;
protected:


public:
	float cost = 1;

	//functions
private:



protected:



public:
	Action();
	~Action();

	virtual void reset();
	virtual bool is_done();
	virtual bool check_procedural_condition();
	virtual bool perform_action();
	virtual bool in_range();


	void add_precondition(std::string key, bool value);
	void remove_precondition(std::string key);
	void add_effect(std::string key, bool value);
	void remove_effect(std::string key);

	std::unordered_map<std::string, bool> get_preconditions() { return preconditions; }
	std::unordered_map<std::string, bool> get_effects() { return effects; }
};
