#include "raylib.h"

#include "game_loop.h"
#include "menu.h"
#include "tutorial.h"
#include "gameplay.h"
#include "credits.h"

namespace Colortrack
{
	int minScreenWidth = 0;
	int minScreenHeight = 0;
	GameState state = GameState::mainmenu;
	GameLoop::GameLoop() 
	{
		_menu = new Menu();
		_tutorial = new Tutorial();
		_gameplay = new Gameplay();
		_credits = new Credits(_gameplay);

	}

	GameLoop::~GameLoop() 
	{
		if (_gameplay != NULL)
		{
			delete _gameplay;
			_gameplay = NULL;
		}
		if (_menu != NULL)
		{
			delete _menu;
			_menu = NULL;
		}
		if (_tutorial != NULL)
		{
			delete _tutorial;
			_tutorial = NULL;
		}
		if (_credits != NULL)
		{
			delete _credits;
			_credits = NULL;
		}

		CloseWindow();
	}

	void GameLoop::Loop()
	{
		InitWindow(640, 480, "Colortrack");
		//Las screens se estan creando al iniciar y no cuando se los pide, crearlas cuando se las pide.
		_gameplay->Init();
		while (!WindowShouldClose())
		{
			//Updates
			if (state == GameState::mainmenu)
			{
				if(_menu != NULL)
					_menu->Input();
			}
			if (state == GameState::tutorialscreen)
			{
				if(_tutorial != NULL)
					_tutorial->Input();
			}
			if (state == GameState::game)
			{
				if(_gameplay != NULL)
					_gameplay->Update();
			}
			if (state == GameState::creditsScreen)
			{
				if(_credits != NULL)
					_credits->Input();
			}

			//Drawings
			BeginDrawing();
			ClearBackground(BLACK);
			if (state == GameState::mainmenu)
			{
				if(_menu != NULL)
					_menu->Draw();
			}
			if (state == GameState::tutorialscreen)
			{
				if(_tutorial != NULL)
					_tutorial->Draw();
			}
			if (state == GameState::game)
			{
				if(_gameplay != NULL)
					_gameplay->Draw();
			}
			if (state == GameState::creditsScreen)
			{
				if(_credits != NULL)
					_credits->Draw();
			}
			EndDrawing();
		}
	}

}