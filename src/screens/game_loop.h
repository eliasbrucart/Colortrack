#ifndef GAME_LOOP_H
#define GAME_LOOP_H

namespace Colortrack 
{

	void Init();
	void DeleteObjects();
	void Update();
	void Draw();
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