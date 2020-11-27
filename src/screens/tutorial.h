#ifndef TUTORIAL_H
#define TUTORIAL_H

#include"raylib.h"

#include"screens.h"

namespace Colortrack 
{
	class Tutorial: public Screens
	{
	private:
		Rectangle _backToMenu;
		Vector2 _mouse;
	public:
		Tutorial();
		~Tutorial();
		virtual void Input();
		virtual void Draw();
	};

}

#endif