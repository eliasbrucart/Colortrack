#ifndef CREDITS_H
#define CREDITS_H

#include"raylib.h"

#include"screens.h"

namespace Colortrack
{
	class Credits: public Screens
	{
	private:
		Rectangle _backToMenu;
		Vector2 _mouse;
		enum buttonCreditsHover {
			mainMenu,
			noHover
		};
		buttonCreditsHover _mouseHoverInButton;
	public:
		Credits();
		~Credits();
		virtual void Input();
		virtual void Draw();
	};
}

#endif