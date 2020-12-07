#include "credits.h"

#include "raylib.h"

#include "game_loop.h"

namespace Colortrack
{
	static const float backToMenuX = 15.0f;
	static const float backToMenuY = 420.0f;
	static const float backToMenuWidth = 100.0f;
	static const float backToMenuHeight = 50.0f;
	Credits::Credits()
	{
		_backToMenu.x = backToMenuX;
		_backToMenu.y = backToMenuY;
		_backToMenu.width = backToMenuWidth;
		_backToMenu.height = backToMenuHeight;

		_creditsSprite = LoadTexture("assets/textures/creditsSprite.png");
		_menuButtonSprite = LoadTexture("assets/textures/menuButtonSprite.png");
	}

	Credits::~Credits()
	{
		UnloadTexture(_creditsSprite);
		UnloadTexture(_menuButtonSprite);
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
		DrawTexture(_creditsSprite, 0, 0, WHITE);
		DrawTexture(_menuButtonSprite, backToMenuX, backToMenuY, WHITE);

		switch (_mouseHoverInButton)
		{
		case mainMenu:
			DrawTexture(_menuButtonSprite, backToMenuX, backToMenuY, LIME);
			break;
		case noHover:
			break;
		default:
			break;
		}
	}
}