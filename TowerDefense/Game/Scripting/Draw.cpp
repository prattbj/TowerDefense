#include "Draw.h"
#include "../Casting/Player.h"
#include "../Casting/Tower.h"
//Constructer
Draw::Draw()
{
	std::filesystem::path path{ "Game/Assets/" };
	for (auto& file : std::filesystem::directory_iterator(path))
	{
		//Load the texture from the path
		//We add 12 to the char* so that we don't create a key with "Game/Assets/" at the beginning of it
		//Results in a key that is named like "Board.png"
		textures[file.path().string().c_str() + 12] = LoadTexture(file.path().string().c_str());
	}
}

//Draw everything to the screen
void Draw::execute(Cast* cast)
{
	//Draw the background 
	DrawTexture(textures["Board.png"], 0, 0, WHITE);
	
	Player* player = (Player*)* cast->getActors("Player").begin();
	//Draw the player's money
	DrawText(TextFormat("$ %i", player->getMoney()), 1100, 687, 20, DARKGREEN);
	//Draw the player's health
	DrawRectangle(900, 687, player->getHealth() / 110, 20, RED);
	//Draw the enemies
	for (auto actor : cast->getActors("Enemies"))
	{
		DrawTexture(textures[actor->getFile()], actor->getPoint().x, actor->getPoint().y, WHITE);
	}
	//Draw the towers and their health bars
	for (auto actor : cast->getActors("Towers"))
	{
		DrawTexture(textures[actor->getFile()], actor->getPoint().x, actor->getPoint().y, WHITE);
		Tower* tower = (Tower*)actor;
		DrawRectangle(actor->getPoint().x, actor->getPoint().y - 5, tower->getHealth() / 2.5, 2, RED);
	}
	//Draw the buttons
	for (auto actor : cast->getActors("Buttons"))
	{
		DrawTexture(textures[actor->getFile()], actor->getPoint().x, actor->getPoint().y, WHITE);
	}
	
}
