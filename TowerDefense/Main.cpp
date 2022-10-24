/*
* Runs the game loop
*/
#include "raylib.h"
#include "Game/Scripting/Script.h"
#include "Game/Casting/Cast.h"
#include "Game/Scripting/Draw.h"
#include <filesystem>
#include <string>

void runGame(Cast* cast, Script* script);

int main()
{
	//Run the game loop
	const int screenWidth = 1280;
	const int screenHeight = 720;
	Cast cast = Cast();
	Script script = Script();
	Draw draw = Draw();
	std::cout << "Success0";
	script.addAction("Output", &draw);
	std::cout << "Success";
	
	InitWindow(screenWidth, screenHeight, "Tower Defense");

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	while (!WindowShouldClose())
	{
		runGame(&cast, &script);//&cast, &script);
	}
}



//Run the game
void runGame(Cast* cast, Script* script)
{
	//Run Input Scripts
	for (auto& action : script->getActions("Input"))
	{
		action->execute(cast);
	}
	//Run Update Scripts
	for (auto& action : script->getActions("Update"))
	{
		action->execute(cast);
	}
	//Run Output Scripts
	for (auto& action : script->getActions("Output"))
	{
		action->execute(cast);
	}
}