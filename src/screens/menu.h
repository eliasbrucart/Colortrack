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
		Texture2D _menuSprite;
		Texture2D _playButtonSprite;
		Texture2D _tutorialButtonSprite;
		Texture2D _creditsButtonSprite;
		Texture2D _exitButtonSprite;
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