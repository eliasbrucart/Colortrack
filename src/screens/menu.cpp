#include "menu.h"

#include "game_loop.h"

namespace Colortrack
{
	static const float buttonsInX = 270.0f;
	static const float buttonsWidth = 100.0f;
	static const float buttonsHeight = 50.0f;

	static const float playButtonY = 160.0f;

	static const float tutorialButtonY = 240.0f;

	static const float creditsButtonY = 320.0f;

	static const float exitButtonY = 400.0f;

	Menu::Menu()
	{
		_playButton.x = buttonsInX;
		_playButton.y = playButtonY;
		_playButton.width = buttonsWidth;
		_playButton.height = buttonsHeight;

		_tutorialButton.x = buttonsInX;
		_tutorialButton.y = tutorialButtonY;
		_tutorialButton.width = buttonsWidth;
		_tutorialButton.height = buttonsHeight;

		_creditsButton.x = buttonsInX;
		_creditsButton.y = creditsButtonY;
		_creditsButton.width = buttonsWidth;
		_creditsButton.height = buttonsHeight;

		_exitButton.x = buttonsInX;
		_exitButton.y = exitButtonY;
		_exitButton.width = buttonsWidth;
		_exitButton.height = buttonsHeight;
	}

	Menu::~Menu()
	{

	}

	void Menu::Input()
	{
		_mouse = GetMousePosition();

		if (CheckCollisionPointRec(_mouse, _playButton))
		{
			_mouseHoverInButton = play;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				state = GameState::game;
		}
		else if (CheckCollisionPointRec(_mouse, _tutorialButton))
		{
			_mouseHoverInButton = tutorial;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				state = GameState::tutorialscreen;
		}
		else if (CheckCollisionPointRec(_mouse, _creditsButton))
		{
			_mouseHoverInButton = credits;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				state = GameState::creditsScreen;
		}
		else if (CheckCollisionPointRec(_mouse, _exitButton))
		{
			_mouseHoverInButton = exit;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				state = GameState::close;
		}
		else
			_mouseHoverInButton = noHover;
	}

	void Menu::Draw()
	{
		DrawRectangleRec(_playButton, GREEN);
		DrawRectangleRec(_tutorialButton, YELLOW);
		DrawRectangleRec(_creditsButton, PURPLE);
		DrawRectangleRec(_exitButton, RED);

		switch (_mouseHoverInButton) {
		case play:
			DrawRectangleRec(_playButton, LIME);
			break;
		case tutorial:
			DrawRectangleRec(_tutorialButton, GOLD);
			break;
		case credits:
			DrawRectangleRec(_creditsButton, VIOLET);
			break;
		case exit:
			DrawRectangleRec(_exitButton, PINK);
			break;
		case noHover:
			break;
		}
	}
}