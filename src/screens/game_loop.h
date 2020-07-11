#ifndef GAME_LOOP_H
#define GAME_LOOP_H

namespace Colortrack 
{
	void DeleteObjects();
	void Unload();
	void Loop();

	static int minScreenWidth = 0;
	static int minScreenHeight = 0;

	enum GameState
	{
		menu,
		instructions,
		game,
		credits
	};
}

#endif