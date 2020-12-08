#ifndef GAME_LOOP_H
#define GAME_LOOP_H
#include"screens.h"
#include "menu.h"
#include "tutorial.h"
#include "gameplay.h"
#include "credits.h"
#include "game_over.h"

namespace Colortrack 
{
	class GameLoop {
	private:
		Screens* _menu;
		Screens* _tutorial;
		Gameplay* _gameplay;
		Screens* _gameOver;
		Screens* _credits;
		Music _bgMusic;
	public:
		GameLoop();
		~GameLoop();
		void Loop();
		void Init();
	};

	extern int minScreenWidth;
	extern int minScreenHeight;

	enum GameState
	{
		mainmenu,
		tutorialscreen,
		game,
		creditsScreen,
		gameOverScreen,
		close
	};

	extern GameState state;
}

#endif