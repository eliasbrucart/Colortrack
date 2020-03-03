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
			instructions,
			gameplay,
			credits
		};
		GameState _gamestate;
		Screens();
		~Screens();
		void SetState(GameState gamestate);
		GameState GetState();
		void UpdateMenu();
		void DrawMenu();
		void UpdateInstructions();
		void DrawInstructions();
		void UpdateCredits();
		void DrawCredits();
	};

}

#endif