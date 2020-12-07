#include "menu.h"

#include"raylib.h"

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

		_menuSprite = LoadTexture("assets/textures/menuSprite.png");
		_playButtonSprite = LoadTexture("assets/textures/playButtonSprite.png");
		_tutorialButtonSprite = LoadTexture("assets/textures/tutorialButtonSprite.png");
		_creditsButtonSprite = LoadTexture("assets/textures/creditsButtonSprite.png");
		_exitButtonSprite = LoadTexture("assets/textures/exitButtonSprite.png");

	}

	Menu::~Menu()
	{
		UnloadTexture(_menuSprite);
		UnloadTexture(_playButtonSprite);
		UnloadTexture(_tutorialButtonSprite);
		UnloadTexture(_creditsButtonSprite);
		UnloadTexture(_exitButtonSprite);
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

	Texture2D Menu::GetMenuSprite()
	{
		return _menuSprite;
	}

	void Menu::Draw()
	{
		ClearBackground(BLACK);
		DrawTexture(_menuSprite, 0, 0, WHITE);
		DrawTexture(_playButtonSprite, buttonsInX, playButtonY, WHITE);
		DrawTexture(_tutorialButtonSprite, buttonsInX, tutorialButtonY, WHITE);
		DrawTexture(_creditsButtonSprite, buttonsInX, creditsButtonY, WHITE);
		DrawTexture(_exitButtonSprite, buttonsInX, exitButtonY, WHITE);
		//DrawRectangleRec(_playButton, GREEN);
		//DrawRectangleRec(_tutorialButton, YELLOW);
		//DrawRectangleRec(_creditsButton, PURPLE);
		//DrawRectangleRec(_exitButton, RED);

		switch (_mouseHoverInButton) {
		case play:
			DrawTexture(_playButtonSprite, buttonsInX, playButtonY, LIME);
			break;
		case tutorial:
			DrawTexture(_tutorialButtonSprite, buttonsInX, tutorialButtonY, GOLD);
			break;
		case credits:
			DrawTexture(_creditsButtonSprite, buttonsInX, creditsButtonY, VIOLET);
			break;
		case exit:
			DrawTexture(_exitButtonSprite, buttonsInX, exitButtonY, PINK);
			break;
		case noHover:
			break;
		}
		//DrawTexture(_menuSprite, 0, 0, WHITE);
	}
}