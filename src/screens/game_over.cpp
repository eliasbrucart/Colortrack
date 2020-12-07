#include"game_over.h"

#include"raylib.h"

#include "game_loop.h"
#include"gameplay.h"

namespace Colortrack 
{
	static const int pointsEarnedPosX = 2;
	static const int pointsEarnedPosY = 1;
	static const int pointsFontSize = 40;

	static const float buttonsX = 270.0f;
	static const float buttonsWidth = 100.0f;
	static const float buttonsHeight = 50.0f;

	static const float playAgainY = 200.0f;

	static const float mainMenuY = 300.0f;

	static const float exitButtonY = 400.0f;

	GameOver::GameOver(Gameplay* gameplay)
	{
		_playAgain.x = buttonsX;
		_playAgain.y = playAgainY;
		_playAgain.width = buttonsWidth;
		_playAgain.height = buttonsHeight;

		_mainMenu.x = buttonsX;
		_mainMenu.y = mainMenuY;
		_mainMenu.width = buttonsWidth;
		_mainMenu.height = buttonsHeight;

		_exitButton.x = buttonsX;
		_exitButton.y = exitButtonY;
		_exitButton.width = buttonsWidth;
		_exitButton.height = buttonsHeight;
		_gameplay = gameplay;

		_gameOverSprite = LoadTexture("assets/textures/gameOverSprite.png");
		_playButtonSprite = LoadTexture("assets/textures/playButtonSprite.png");
		_menuButtonSprite = LoadTexture("assets/textures/menuButtonSprite.png");
		_exitButtonSprite = LoadTexture("assets/textures/exitButtonSprite.png");
	}

	GameOver::~GameOver()
	{
		UnloadTexture(_gameOverSprite);
		UnloadTexture(_playButtonSprite);
		UnloadTexture(_menuButtonSprite);
		UnloadTexture(_exitButtonSprite);
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
		DrawTexture(_gameOverSprite, 0, 0, WHITE);
		DrawText(TextFormat("Points Earned: %i", _gameplay->GetPoints()), pointsEarnedPosX, pointsEarnedPosY, pointsFontSize, BLACK);

		DrawTexture(_playButtonSprite, buttonsX, playAgainY, WHITE);
		DrawTexture(_menuButtonSprite, buttonsX, mainMenuY, WHITE);
		DrawTexture(_exitButtonSprite, buttonsX, exitButtonY, WHITE);

		switch (_mouseHoverInButton)
		{
		case playAgain:
			DrawTexture(_playButtonSprite, buttonsX, playAgainY, LIME);
			break;
		case mainMenu:
			DrawTexture(_menuButtonSprite, buttonsX, mainMenuY, LIME);
			break;
		case exitButton:
			DrawTexture(_exitButtonSprite, buttonsX, exitButtonY, PINK);
			break;
		case noHover:
			break;
		default:
			break;
		}
	}
}

