#include "Action.h"
#include <iostream>
#include <filesystem>
class Draw : public Action
{
public:
	//Constructor adds all the textures to the textures map
	Draw();
	//Draw everything to the screen
	void execute(Cast* cast);
	
protected:
	std::map<std::string, Texture2D> textures;
};