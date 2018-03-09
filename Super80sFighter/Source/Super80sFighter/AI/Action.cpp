// Fill out your copyright notice in the Description page of Project Settings.

#include "Action.h"

using namespace std;

Action::Action()
{
	preconditions = new unordered_map<string, bool>();
	effects = new unordered_map<string, bool>();
}

Action::~Action()
{
	for (auto itr = preconditions.begin(); itr != preconditions.end(); itr++)
	{
		itr->first.clear();
	}
	preconditions.clear();
	for (auto itr = effects.begin(); itr != effects.end(); itr++)
	{
		itr->first.clear();
	}
	effects.clear();
}

void Action::reset()
{
}

bool Action::is_done()
{
	return false;
}

bool Action::check_procedural_condition()
{
	return false;
}

bool Action::perform_action()
{
	return false;
}

bool Action::in_range()
{
	return false;
}

void Action::add_precondition(string key, bool value)
{
	preconditions.insert(key, value);
}

void Action::remove_precondition(string key)
{
	preconditions.erase(key);
}

void Action::add_effect(string key, bool value)
{
	effects.insert(key, value);
}

void Action::remove_effect(string key)
{
	effects.erase(key);
}
