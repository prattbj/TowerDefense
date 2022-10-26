#pragma once

#include "../Casting/Cast.h"
#include "raylib.h"
#include "Action.h"
//A thing that happens.
class Attack : public Action
{
public:
	virtual void execute(Cast* cast);

};