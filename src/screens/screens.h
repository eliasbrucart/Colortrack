#ifndef SCREENS_H 
#define SCREENS_H

namespace Colortrack
{

	class Screens
	{
	public:
		enum GameState 
		{
			menu,
			controls,
			gameplay,
			credits
		};
		GameState _gamestate;
		Screens();
		~Screens();
		void SetState(GameState gamestate);
		GameState GetState();
	};

}

#endif