#include "raylib.h"

#include "game_loop.h"
#include "gameobjects/player.h"
#include "gameobjects/rectangle_enemy.h"
#include "gameplay.h"

namespace Colortrack
{
	Gameplay* gameplay = new Gameplay();

	void DeleteObjects()
	{
		if (gameplay != NULL)
		{
			delete gameplay;
		}
	}

	void Unload()
	{

	}

	void Loop()
	{
		gameplay->Init();
		while (!WindowShouldClose())
		{
			gameplay->Update();
			BeginDrawing();
			gameplay->Draw();
			ClearBackground(BLACK);
			EndDrawing();
		}
		DeleteObjects();
	}

}