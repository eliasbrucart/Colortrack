#ifndef GAME_LOOP_H
#define GAME_LOOP_H

namespace Colortrack 
{
	void DeleteObjects();
	void Unload();
	void Loop();

	extern int minScreenWidth;
	extern int minScreenHeight;

	enum GameState
	{
		mainmenu,
		tutorialscreen,
		game,
		credits
	};

	extern GameState state;
}

#endif