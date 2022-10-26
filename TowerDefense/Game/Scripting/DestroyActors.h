#pragma once
#include "../Casting/Cast.h"
#include "Action.h"
//A thing that happens.
class DestroyActors : public Action
{
public:
	virtual void execute(Cast* cast);

};