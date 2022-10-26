#include "Actor.h"
#include <random>
class Enemy : public Actor
{
public:
	Enemy()
	{
		file = "Enemy.png";
		//A random y position and an x position starting all the way to the right
		point = Vector2(1280, std::rand() % 675 + 5);
		health = 10;
	}
	//When the level increases, the health of the enemies increases
	void setHealth(int value)
	{
		health *= value;
	}
	//When the enemy is hit, its health decreases
	void decreaseHealth(int value)
	{
		health -= value;
		if (health < 0)
		{
			health = 0;
		}
	}
	//Return the health
	int getHealth() const
	{
		return health;
	}
	//Rectangle of the enemy
	Rectangle getBox()
	{
		return Rectangle(point.x, point.y, 20, 20);
	}
protected:
	int health;
};