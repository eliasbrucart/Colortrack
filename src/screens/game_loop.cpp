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
		_menu = NULL;
		_tutorial = NULL;
		_gameplay = NULL;
		_credits = NULL;
		_gameOver = NULL;
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
		if (_gameOver != NULL)
		{
			delete _gameOver;
			_gameOver = NULL;
		}

		CloseWindow();
	}

	void GameLoop::Loop()
	{
		InitWindow(640, 480, "Colortrack");
		while (!WindowShouldClose() && state != GameState::close)
		{
			//Updates
			if (state == GameState::mainmenu)
			{
				if (_tutorial != NULL) 
				{
					delete _tutorial;
					_tutorial = NULL;
				}
				if (_gameplay != NULL) 
				{
					delete _gameplay;
					_gameplay = NULL;
				}
				if (_credits != NULL) 
				{
					delete _credits;
					_credits = NULL;
				}
				if (_gameOver != NULL) 
				{
					delete _gameOver;
					_gameOver = NULL;
				}
				if (_menu == NULL)
					_menu = new Menu();
				if(_menu != NULL)
					_menu->Input();
			}
			if (state == GameState::tutorialscreen)
			{
				if (_menu != NULL) 
				{
					delete _menu;
					_menu = NULL;
				}
				if (_gameplay != NULL) 
				{
					delete _gameplay;
					_gameplay = NULL;
				}
				if (_credits != NULL) 
				{
					delete _credits;
					_credits = NULL;
				}
				if (_tutorial == NULL)
					_tutorial = new Tutorial();
				if(_tutorial != NULL)
					_tutorial->Input();
			}
			if (state == GameState::game)
			{
				if (_tutorial != NULL) 
				{
					delete _tutorial;
					_tutorial = NULL;
				}
				if (_menu != NULL) 
				{
					delete _menu;
					_menu = NULL;
				}
				if (_credits != NULL) 
				{
					delete _credits;
					_credits = NULL;
				}
				if (_gameOver != NULL) 
				{
					delete _gameOver;
					_gameOver = NULL;
				}
				if (_gameplay == NULL)
					_gameplay = new Gameplay();
				if(_gameplay != NULL)
					_gameplay->Update();
			}
			if (state == GameState::creditsScreen)
			{
				if (_tutorial != NULL)
				{
					delete _tutorial;
					_tutorial = NULL;
				}
				if (_gameplay != NULL)
				{
					delete _gameplay;
					_gameplay = NULL;
				}
				if (_credits != NULL)
				{
					delete _gameOver;
					_gameOver = NULL;
				}
				if (_credits == NULL)
					_credits = new Credits();
				if (_credits != NULL)
					_credits->Input();
			}
			if (state == GameState::gameOverScreen)
			{
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
				if (_gameOver == NULL)
					_gameOver = new GameOver(_gameplay);
				if(_gameOver != NULL)
					_gameOver->Input();
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
			if (state == GameState::gameOverScreen)
			{
				if (_gameOver != NULL)
					_gameOver->Draw();
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