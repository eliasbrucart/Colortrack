#ifndef GAME_LOOP_H
#define GAME_LOOP_H
#include "menu.h"
#include "tutorial.h"
#include "gameplay.h"
#include "credits.h"

namespace Colortrack 
{
	class GameLoop {
	private:
		Menu* _menu;
		Tutorial* _tutorial;
		Gameplay* _gameplay;
		Credits* _credits;
	public:
		GameLoop();
		~GameLoop();
		void Loop();
	};

	extern int minScreenWidth;
	extern int minScreenHeight;

	enum GameState
	{
		mainmenu,
		tutorialscreen,
		game,
		creditsScreen
	};

	extern GameState state;
}

#endif