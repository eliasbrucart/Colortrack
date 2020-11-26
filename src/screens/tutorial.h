#ifndef TUTORIAL_H
#define TUTORIAL_H

#include"raylib.h"

namespace Colortrack 
{
	class Tutorial
	{
	private:
		Rectangle _backToMenu;
		Vector2 _mouse;
	public:
		Tutorial();
		~Tutorial();
		void Input();
		void Draw();
	};

}

#endif