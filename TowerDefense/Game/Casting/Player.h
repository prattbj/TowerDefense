#include "Actor.h"
//The values the player holds. This is only an actor so that it is 
//convenient for it to be sent with the cast and have its values modified.
class Player : public Actor
{
public:
	Player()
	{
		money = 100;
		health = 10000;
	}
	//Overload the == operator to check if the money is equal to an amount.
	bool operator== (int amount)
	{
		return (money == amount);
	}
	//Increase the amount of money
	Player& operator += (int amount)
	{
		money += amount;
		return *this;
	}
	//Return the current amount of money
	int getMoney() const
	{
		return money;
	}
	//Return the amount of health the player has
	int getHealth() const
	{
		return health;
	}
	//Decrease the player's health
	void setHealth(int amount)
	{
		health -= amount;
	}
private:
	int money;
	int health;
};