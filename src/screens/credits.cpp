#include "credits.h"

#include "raylib.h"

#include "game_loop.h"

namespace Colortrack
{
	static const float backToMenuX = 270.0f;
	static const float backToMenuY = 320.0f;
	static const float backToMenuWidth = 100.0f;
	static const float backToMenuHeight = 50.0f;
	Credits::Credits()
	{
		_backToMenu.x = backToMenuX;
		_backToMenu.y = backToMenuY;
		_backToMenu.width = backToMenuWidth;
		_backToMenu.height = backToMenuHeight;
	}

	Credits::~Credits()
	{
	}

	void Credits::Input()
	{
		_mouse = GetMousePosition();

		if (CheckCollisionPointRec(_mouse, _backToMenu))
		{
			_mouseHoverInButton = mainMenu;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				state = GameState::mainmenu;
			}
		}
		else
			_mouseHoverInButton = noHover;
	}

	void Credits::Draw()
	{
 		DrawRectangleRec(_backToMenu, YELLOW);

		switch (_mouseHoverInButton)
		{
		case mainMenu:
			DrawRectangleRec(_backToMenu, GOLD);
			break;
		case noHover:
			break;
		default:
			break;
		}
	}
}