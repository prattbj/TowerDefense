#pragma once
#include "Actor.h"
#include "raylib.h"
/*
* A tower.
*/
class Tower : public Actor
{
public:
	Tower();
	//Getters and setters
	int getCooldown() const;

	int getDamage() const;

	int getHealth() const;

	void setCooldown();

	void setHealth(int damage);


	Rectangle getBox();

	//Check if the Tower is attached to the cursor
	bool getAttached() const;

	void setAttached(bool attached);
protected:
	int cooldown;
	int damage;
	int health;
	bool attached;
};
