#include"game_over.h"

#include"raylib.h"

#include "game_loop.h"
#include"gameplay.h"

namespace Colortrack 
{
	int pointsEarnedPosX = GetScreenWidth() / 2;
	int pointsEarnedPosY = GetScreenHeight() / 2.5;
	int pointsFontSize = 40;

	float playAgainX = 270.0f;
	float playAgainY = 220.0f;
	float playAgainWidth = 100.0f;
	float playAgainHeight = 50.0f;

	float mainMenuX = 270.0f;
	float mainMenuY = 320.0f;
	float mainMenuWidth = 100.0f;
	float mainMenuHeight = 50.0f;

	float exitButtonX = 270.0f;
	float exitButtonY = 420.0f;
	float exitButtonWidth = 100.0f;
	float exitButtonHeight = 50.0f;
	GameOver::GameOver(Gameplay* gameplay)
	{
		_playAgain.x = playAgainX;
		_playAgain.y = playAgainY;
		_playAgain.width = playAgainWidth;
		_playAgain.height = playAgainHeight;

		_mainMenu.x = mainMenuX;
		_mainMenu.y = mainMenuY;
		_mainMenu.width = mainMenuWidth;
		_mainMenu.height = mainMenuHeight;

		_exitButton.x = exitButtonX;
		_exitButton.y = exitButtonY;
		_exitButton.width = exitButtonWidth;
		_exitButton.height = exitButtonHeight;
		_gameplay = gameplay;
	}

	GameOver::~GameOver()
	{
	}

	void GameOver::Input()
	{
		_mouse = GetMousePosition();

		if (CheckCollisionPointRec(_mouse, _playAgain))
		{
			_mouseHoverInButton = playAgain;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				_gameplay->Init();
				state = GameState::game;
			}
		}
		else if (CheckCollisionPointRec(_mouse, _mainMenu))
		{
			_mouseHoverInButton = mainMenu;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				state = GameState::mainmenu;
			}
		}
		else if (CheckCollisionPointRec(_mouse, _exitButton))
		{
			_mouseHoverInButton = exitButton;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				state = GameState::close;
			}
		}
		else
			_mouseHoverInButton = noHover;
	}

	void GameOver::Draw()
	{
		DrawText(TextFormat("Points Earned: %i", _gameplay->GetPoints()), pointsEarnedPosX, pointsEarnedPosX, pointsFontSize, WHITE);
		DrawRectangleRec(_playAgain, GREEN);
		DrawRectangleRec(_mainMenu, YELLOW);
		DrawRectangleRec(_exitButton, RED);

		switch (_mouseHoverInButton)
		{
		case playAgain:
			DrawRectangleRec(_playAgain, LIME);
			break;
		case mainMenu:
			DrawRectangleRec(_mainMenu, GOLD);
			break;
		case exitButton:
			DrawRectangleRec(_exitButton, PINK);
			break;
		case noHover:
			break;
		default:
			break;
		}
	}
}

