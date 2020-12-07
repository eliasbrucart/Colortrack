#include "tutorial.h"

#include"raylib.h"

#include"game_loop.h"

namespace Colortrack
{
	static const float backToMenuX = 270.0f;
	static const float backToMenuY = 400.0f;
	static const float backToMenuWidth = 100.0f;
	static const float backToMenuHeight = 50.0f;

	Tutorial::Tutorial()
	{
		_backToMenu.x = backToMenuX;
		_backToMenu.y = backToMenuY;
		_backToMenu.width = backToMenuWidth;
		_backToMenu.height = backToMenuHeight;
	}

	Tutorial::~Tutorial()
	{

	}

	void Tutorial::Input()
	{
		_mouse = GetMousePosition();
		if (CheckCollisionPointRec(_mouse, _backToMenu))
		{
			_mouseHoverInButton = backToMenu;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				state = GameState::mainmenu;
		}
		else
			_mouseHoverInButton = noHover;
	}

	void Tutorial::Draw()
	{
		DrawRectangleRec(_backToMenu, WHITE);
		switch (_mouseHoverInButton)
		{
		case backToMenu:
			DrawRectangleRec(_backToMenu, GRAY);
			break;
		case noHover:
			break;
		default:
			break;
		}
	}
}