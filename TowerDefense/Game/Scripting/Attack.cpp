#include "Attack.h"
#include "../Casting/Tower.h"
#include "../Casting/Enemy.h"
#include "raylib.h"
#include <iostream>
//Towers and enemies attack
void Attack::execute(Cast* cast)
{
	//For each tower
	for (auto actor : cast->getActors("Towers"))
	{
		Tower* tower = (Tower*)actor;
		//Set the cooldown
		tower->setCooldown();
		//If it is able to attack
		if (tower->getCooldown() == 0 && !tower->getAttached())
		{
			Rectangle rec = tower->getBox();
			Vector2 attack = Vector2((rec.x + rec.width/2) , (rec.y + rec.height / 2));
			//Draw a circle showing the attack
			DrawCircleV(attack, 150, WHITE);
			for (auto pEnemy : cast->getActors("Enemies"))
			{
				Enemy* enemy = (Enemy*)pEnemy;
				//If an enemy collides with the circle
				if (CheckCollisionCircleRec(attack, 150, enemy->getBox()))
				{
					//Decrease its health
					enemy->decreaseHealth(5);
				}
			}
		}
		//For each enemy
		for (auto pEnemy : cast->getActors("Enemies"))
		{
			Enemy* enemy = (Enemy*)pEnemy;
			//If it collides with the tower
			if (CheckCollisionRecs(enemy->getBox(), tower->getBox()) && !tower->getAttached())
			{
				//The tower takes damage equal to the enemy's health
				tower->setHealth(enemy->getHealth());
				//And the enemy loses health equal to 100
				enemy->decreaseHealth(100);
			}
		}
	}
}
