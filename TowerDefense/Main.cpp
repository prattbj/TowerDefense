/*
* Benjamin Pratt's Tower Defense Game
*/
#include "raylib.h"
#include "Game/Scripting/Script.h"
#include "Game/Casting/Cast.h"
#include "Game/Scripting/Draw.h"
#include "Game/Casting/Shock.h"
#include "Game/Scripting/Mouse.h"
#include "Game/Casting/Button.h"
#include "Game/Scripting/Move.h"
#include <string>
#include "Game/Casting/Player.h"
#include "Game/Scripting/CreateEnemies.h"
#include "Game/Scripting/Attack.h"
#include "Game/Scripting/DestroyActors.h"
void runGame(Cast* cast, Script* script);

int main()
{
	//Run the game loop
	const int screenWidth = 1280;
	const int screenHeight = 720;
	Cast cast = Cast();
	Script script = Script();
	
	InitWindow(screenWidth, screenHeight, "Tower Defense");

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	Draw draw = Draw(); //Create the Draw object after initializing the window so that we have an OpenGL context when loading textures
	script.addAction("Output", &draw);
	//Add everything needed when starting the game to the cast and the script
	Mouse mouse = Mouse();
	script.addAction("Input", &mouse);
	Move move = Move();
	script.addAction("Update", &move);
	Button button = Button("Shock.png", Vector2(5, 680));
	cast.addActor("Buttons", &button);
	Player player = Player();
	cast.addActor("Player", &player);
	CreateEnemies createEnemies = CreateEnemies();
	script.addAction("Update", &createEnemies);
	Attack attack = Attack();
	script.addAction("Output", &attack);
	DestroyActors destroy = DestroyActors();
	script.addAction("Update", &destroy);
	//Run the game loop
	while (!WindowShouldClose())
	{
		runGame(&cast, &script);
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
	//Begin drawing now and clear the background so that
	//multiple output scripts don't conflict
	BeginDrawing();
	ClearBackground(WHITE);
	//Run Output Scripts
	for (auto& action : script->getActions("Output"))
	{
		action->execute(cast);
	}
	EndDrawing();
}