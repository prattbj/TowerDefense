#pragma once
#ifndef ACTION_H
#define ACTION_H
#include "../Casting/Cast.h"
#include "raylib.h"
//A thing that happens.
class Action
{
public:
	virtual void execute(Cast* cast) {};
};

#endif