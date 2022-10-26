#include "DestroyActors.h"
#include "../Casting/Tower.h"
#include "../Casting/Enemy.h"
#include "../Casting/Player.h"
#include "raylib.h"
#include <iostream>
//Destroy actors that shouldn't exist any more.
void DestroyActors::execute(Cast* cast)
{
	//check if towers are destroyed
	for (auto actor : cast->getActors("Towers"))
	{
		Tower* tower = (Tower*)actor;
		if (tower->getHealth() <= 0)
		{
			cast->destroyActor("Towers", actor);
		}
	}
	auto pPlayer = *cast->getActors("Player").begin();
	Player* player = (Player*)pPlayer;
	//Check if enemies are destroyed or are at the exit
	for (auto& actor : cast->getActors("Enemies"))
	{
		Enemy* enemy = (Enemy*)actor;
		if (enemy->getHealth() <= 0)
		{
			cast->destroyActor("Enemies", actor);
			*player += 10;
		}
		//if the enemy reaches the exit
		if (enemy->getPoint().x < 0)
		{
			//the enemy is destroyed
			cast->destroyActor("Enemies", actor);
			//The player loses HP
			player->setHealth(enemy->getHealth());
		}
	}
}