#ifndef MENU_H
#define MENU_H

#include "raylib.h"

#include"screens.h"

namespace Colortrack 
{
	class Menu: public Screens
	{
	private:
		Rectangle _playButton;
		Rectangle _tutorialButton;
		Rectangle _creditsButton;
		Rectangle _exitButton;
		Vector2 _mouse;
		enum buttonMenuHover {
			play,
			tutorial,
			credits,
			exit,
			noHover
		};
		buttonMenuHover _mouseHoverInButton;
	public:
		Menu();
		~Menu();
		virtual void Input();
		virtual void Draw();
	};

}

#endif