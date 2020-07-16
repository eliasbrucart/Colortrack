#ifndef MENU_H
#define MENU_H

#include "raylib.h"

namespace Colortrack 
{
	class Menu
	{
	private:
		Rectangle _playButton;
		Rectangle _tutorialButton;
		Rectangle _exitButton;
	public:
		Menu();
		~Menu();
		void Draw();
		void Input();
	};

}

#endif