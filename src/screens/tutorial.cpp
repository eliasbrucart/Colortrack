#include "tutorial.h"

#include"raylib.h"

#include"game_loop.h"

namespace Colortrack
{
	static const float backToMenuX = 2.0f;
	static const float backToMenuY = 420.0f;
	static const float backToMenuWidth = 100.0f;
	static const float backToMenuHeight = 50.0f;

	Tutorial::Tutorial()
	{
		_backToMenu.x = backToMenuX;
		_backToMenu.y = backToMenuY;
		_backToMenu.width = backToMenuWidth;
		_backToMenu.height = backToMenuHeight;

		_tutorialSprite = LoadTexture("assets/textures/tutorialSprite.png");
		_menuButtonSprite = LoadTexture("assets/textures/menuButtonSprite.png");
	}

	Tutorial::~Tutorial()
	{
		UnloadTexture(_tutorialSprite);
		UnloadTexture(_menuButtonSprite);
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
		DrawTexture(_tutorialSprite, 0, 0, WHITE);
		DrawTexture(_menuButtonSprite, backToMenuX, backToMenuY, WHITE);
		switch (_mouseHoverInButton)
		{
		case backToMenu:
			DrawTexture(_menuButtonSprite, backToMenuX, backToMenuY, LIME);
			break;
		case noHover:
			break;
		default:
			break;
		}
	}
}