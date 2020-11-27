#ifndef CREDITS_H
#define CREDITS_H

#include"raylib.h"

#include "gameplay.h"
#include"screens.h"

namespace Colortrack
{
	class Credits: public Screens
	{
	private:
		Rectangle _mainMenu;
		Rectangle _playAgain;
		Rectangle _exitButton;
		Gameplay* _gameplay;
	public:
		Credits(Gameplay* gameplay);
		~Credits();
		virtual void Input();
		virtual void Draw();
	};
}

#endif