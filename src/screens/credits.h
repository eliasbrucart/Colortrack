#ifndef CREDITS_H
#define CREDITS_H

#include"raylib.h"

#include "gameplay.h"

namespace Colortrack
{
	class Credits
	{
	private:
		Rectangle _mainMenu;
		Rectangle _playAgain;
		Rectangle _exitButton;
		Gameplay* _gameplay;
	public:
		Credits(Gameplay* gameplay);
		~Credits();
		void Input();
		void Draw();
	};
}

#endif