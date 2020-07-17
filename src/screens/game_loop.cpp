#include "raylib.h"

#include "game_loop.h"
#include "gameobjects/player.h"
#include "gameobjects/rectangle_enemy.h"
#include "gameplay.h"
#include "menu.h"

namespace Colortrack
{
	Gameplay* gameplay = new Gameplay();
	Menu* menu = new Menu();

	GameState state = GameState::mainmenu;

	void DeleteObjects()
	{
		if (gameplay != NULL)
		{
			delete gameplay;
		}
		if (menu != NULL)
		{
			delete menu;
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
			//Updates
			if (state == GameState::mainmenu)
			{
				menu->Input();
			}
			if (state == GameState::game)
			{
				gameplay->Update();
			}

			//Drawings
			BeginDrawing();
			ClearBackground(BLACK);
			if (state == GameState::mainmenu)
			{
				menu->Draw();
			}
			if (state == GameState::game)
			{
				gameplay->Draw();
			}
			EndDrawing();
		}
		DeleteObjects();
	}

}