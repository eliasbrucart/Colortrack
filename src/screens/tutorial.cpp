#include "tutorial.h"

#include"raylib.h"

#include"game_loop.h"

namespace Colortrack
{
	Tutorial::Tutorial()
	{
		_backToMenu.x = 300.0f;
		_backToMenu.y = 400.0f;
		_backToMenu.width = 100.0f;
		_backToMenu.height = 50.0f;
	}

	Tutorial::~Tutorial()
	{

	}

	void Tutorial::Input()
	{
		_mouse = GetMousePosition();
		if (CheckCollisionPointRec(_mouse, _backToMenu))
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				state = GameState::mainmenu;
		}
	}

	void Tutorial::Draw()
	{
		DrawRectangleRec(_backToMenu, WHITE);
	}
}