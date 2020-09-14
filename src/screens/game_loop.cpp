#include "raylib.h"

#include "game_loop.h"
#include "gameobjects/player.h"
#include "gameobjects/rectangle_enemy.h"
#include "gameplay.h"
#include "menu.h"
#include "tutorial.h"

namespace Colortrack
{
	Gameplay* gameplay;
	Menu* menu;
	Tutorial* tutorial;

	int minScreenWidth = 0;
	int minScreenHeight = 0;
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
		if (tutorial != NULL)
		{
			delete tutorial;
		}
	}

	void Unload()
	{

	}

	void Loop()
	{
		InitWindow(640, 480, "Colortrack");
		gameplay = new Gameplay();
		menu = new Menu();
		tutorial = new Tutorial();
		gameplay->Init();
		while (!WindowShouldClose())
		{
			//Updates
			if (state == GameState::mainmenu)
			{
				menu->Input();
			}
			if (state == GameState::tutorialscreen)
			{
				tutorial->Input();
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
			if (state == GameState::tutorialscreen)
			{
				tutorial->Draw();
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