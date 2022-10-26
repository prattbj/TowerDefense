#pragma once
#include "../Casting/Cast.h"
#include "Action.h"
//A thing that happens.
class Move : public Action
{
public:
	virtual void execute(Cast* cast);

};