#include "raylib.h"

#include "game_loop.h"
#include "gameobjects/player.h"
#include "gameobjects/rectangle_enemy.h"
#include "gameplay.h"
#include "menu.h"
#include "tutorial.h"
#include "credits.h"

namespace Colortrack
{
	Gameplay* gameplay;
	Menu* menu;
	Tutorial* tutorial;
	Credits* credits;

	int minScreenWidth = 0;
	int minScreenHeight = 0;
	GameState state = GameState::mainmenu;

	void DeleteObjects()
	{
		if (gameplay != NULL)
		{
			delete gameplay;
			gameplay = NULL;
		}
		if (menu != NULL)
		{
			delete menu;
			menu = NULL;
		}
		if (tutorial != NULL)
		{
			delete tutorial;
			tutorial = NULL;
		}
		if (credits != NULL)
		{
			delete credits;
			credits = NULL;
		}
	}

	void Unload()
	{

	}

	void Loop()
	{
		InitWindow(640, 480, "Colortrack");
		//Las screens se estan creando al iniciar y no cuando se los pide, crearlas cuando se las pide.
		gameplay = new Gameplay();
		menu = new Menu();
		tutorial = new Tutorial();
		credits = new Credits(gameplay);
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
			if (state == GameState::creditsScreen)
			{
				credits->Input();
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
			if (state == GameState::creditsScreen)
			{
				credits->Draw();
			}
			EndDrawing();
		}
		DeleteObjects();
	}

}