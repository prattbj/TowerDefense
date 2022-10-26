#include "CreateEnemies.h"
#include "../Casting/Enemy.h"
#include <iostream>
//Create enemies to fight
CreateEnemies::CreateEnemies()
{
	level = 0;
	numEnemies = 1;
	enemyLevel = 1;
}
void CreateEnemies::execute(Cast* cast)
{
	//Increase the level (this is a big number that goes up each frame)
	this->level++;
	//every 20 seconds, number of enemies per frame increases
	if (level % (20 * 60) == 0)
	{
		numEnemies += 1;
	}
	//every 60 seconds, the enemy's levels go up by 1
	if (level % (60 * 60) == 0)
	{
		enemyLevel += 1;
	}
	//Every second
	if (level % 60 == 0)
	{ 
		//create a batch of enemies
		for (unsigned int i = 0; i < numEnemies; i++)
		{
			Enemy* enemy = new Enemy();
			enemy->setHealth(enemyLevel);
			cast->addActor("Enemies", enemy);
		}
	}
}
