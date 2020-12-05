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
		Rectangle _playAgain;
		Rectangle _mainMenu;
		Rectangle _exitButton;
		Vector2 _mouse;
		Gameplay* _gameplay;
		enum buttonCreditsHover {
			playAgain,
			mainMenu,
			exitButton,
			noHover
		};
		buttonCreditsHover _mouseHoverInButton;
	public:
		Credits(Gameplay* gameplay);
		~Credits();
		virtual void Input();
		virtual void Draw();
	};
}

#endif