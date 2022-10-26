#include "Tower.h"
//Construct it with some default values
Tower::Tower()
{
	cooldown = 60;
	damage = 100;
	health = 100;
	attached = false;
}
//Getters and setters
int Tower::getCooldown() const
{
	return cooldown;
}

int Tower::getDamage() const
{
	return damage;
}

int Tower::getHealth() const
{
	return health;
}
//If cooldown goes below 0, it goes back to 60.
void Tower::setCooldown()
{
	cooldown--;
	if (cooldown < 0)
	{
		cooldown = 60;
	}
}
//The tower takes damage
void Tower::setHealth(int damage)
{
	health -= damage;
}

//The rectangle of the tower
Rectangle Tower::getBox()
{
	return Rectangle(point.x, point.y, 40, 40);
}

//Check if the Tower is attached to the cursor
bool Tower::getAttached() const
{
	return attached;
}
//Set if the tower is attached to the cursor
void Tower::setAttached(bool attached)
{
	this->attached = attached;
}

