#include "Move.h"
#include "raylib.h"
#include "../Casting/Tower.h"
#include "raymath.h"
#include <iostream>
void Move::execute(Cast* cast)
{
	//Make sure that the tower is placed on a grid and
	//that it can't exit the play area.
	for (auto actor : cast->getActors("Towers"))
	{
		int x = actor->getPoint().x;
		int y = actor->getPoint().y;

		x = x - x % 40;

		y = y - y % 40;
		if (x < 0)
		{
			x = 0;
		}
		if (x > 1240)
		{
			x = 1240;
		}
		if (y < 0)
		{
			y = 0;
		}
		if (y >= 680)
		{
			y = 640;
		}
		actor->setPoint(Vector2(x, y));
	}
	//Move all of the enemies
	for (auto enemy : cast->getActors("Enemies"))
	{
		Vector2 direction = Vector2(-2, 0);
		for (auto pTower: cast->getActors("Towers"))
		{
			//If the enemy is close to a tower, it will go towards that tower
			Vector2 enemyVector = Vector2(enemy->getPoint().x, enemy->getPoint().y);
			Vector2 towerVector = Vector2(pTower->getPoint().x, pTower->getPoint().y);
			Tower* tower = (Tower*)pTower;
			if (CheckCollisionCircleRec(enemy->getPoint(), 200, tower->getBox()) && !tower->getAttached())
			{
				direction = Vector2Scale(Vector2Normalize(Vector2Subtract(towerVector, enemyVector)), 2);
			}
		}
		//Move the enemy
		enemy->setPoint(Vector2(enemy->getPoint().x + direction.x, enemy->getPoint().y + direction.y));
	}
}