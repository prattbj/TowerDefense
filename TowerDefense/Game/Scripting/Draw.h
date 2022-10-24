#include "Action.h"
#include <iostream>
#include <filesystem>
class Draw : public Action
{
public:
	//Constructor adds all the textures to the textures map
	Draw()
	{
		for (auto& file : std::filesystem::directory_iterator("Game/Assets/"))
		{
			//Load the texture from the path
			//We add 12 to the char* so that we don't create a key with "Game/Assets/" at the beginning of it
			//Results in a key that is named like "Board.png"
			this->textures[file.path().string().c_str() + 12] = LoadTextureFromImage(LoadImage(file.path().string().c_str()));
		}
	}
	//Draw everything to the screen
	void execute(Cast* cast)
	{
		
		DrawTexture(this->textures["Board.png"], 0, 0, WHITE);
		BeginDrawing();
		EndDrawing();
	}
protected:
	std::map<std::string, Texture2D> textures;
};