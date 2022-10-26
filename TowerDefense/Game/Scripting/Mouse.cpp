#include "Mouse.h"
#include "../Casting/Tower.h"
#include "raylib.h"
#include "../Casting/Button.h"
#include "../Casting/Player.h"
#include <iostream>
//Let the mouse do things
void Mouse::execute(Cast* cast)
{
	//Mouse position
	Vector2 pos = GetMousePosition();
	Player* player = (Player*)*cast->getActors("Player").begin();
	//Check each tower
	for (auto& pTower : cast->getActors("Towers"))
	{
		
		//Downcast the parent of Tower to a tower.
		Tower* tower = (Tower*)pTower;
		Rectangle box = tower->getBox();
		//If the tower is attached to the cursor, set its point to the same as the cursor's point
		if (tower->getAttached())
		{
			tower->setPoint(pos);
		}
		//If the left button is released, the tower is no longer attached and the player loses 100 money
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && tower->getAttached())
		{
			tower->setAttached(false);
			*player += -100;
		}
	}
	//For each button
	for (auto pButton : cast->getActors("Buttons"))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			
			Button* button = (Button*)pButton;
			//Check if the mouse is inside of the button's rectangle
			if (CheckCollisionPointRec(Vector2(pos.x, pos.y), button->getBox()) && player->getMoney() >= 100)
			{
				//Create a new tower and assign it to the type
				//according to the button
				Tower * tower = new Tower();
				std::string file = button->getFile();
				if (file == "Shock.png")
				{
					tower = new Shock();
					
				}
				tower->setPoint(pos);
				tower->setAttached(true);
				//Add the tower to the cast
				cast->addActor("Towers", tower);
			}
			
		}

	}
}