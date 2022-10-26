#pragma once

#include "../Casting/Cast.h"
#include "Action.h"
//A thing that happens.
class CreateEnemies : public Action
{
public:
	CreateEnemies();
	virtual void execute(Cast* cast);
private:
	unsigned long level;
	unsigned int numEnemies;
	unsigned int enemyLevel;
};