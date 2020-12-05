#include "menu.h"

#include "game_loop.h"

namespace Colortrack
{
	float xPlayButton = 270.0f;
	float yPlayButton = 190.0f;
	float widthPlayButton = 100.0f;
	float heightPlayButton = 50.0f;

	float xTutorialButton = 270.0f;
	float yTutorialButton = 270.0f;
	float widthTutorialButton = 100.0f;
	float heightTutorialButton = 50.0f;

	float xCreditsButton = 270.0f;
	float yCreditsButton = 350.0f;
	float widthCreditsButton = 100.0f;
	float heightCreditsButton = 50.0f;

	float xExitButton = 270.0f;
	float yExitButton = 430.0f;
	float widthExitButton = 100.0f;
	float heightExitButton = 50.0f;

	Menu::Menu()
	{
		_playButton.x = xPlayButton;
		_playButton.y = yPlayButton;
		_playButton.width = widthPlayButton;
		_playButton.height = heightPlayButton;

		_tutorialButton.x = xTutorialButton;
		_tutorialButton.y = yTutorialButton;
		_tutorialButton.width = widthTutorialButton;
		_tutorialButton.height = heightTutorialButton;

		_creditsButton.x = xCreditsButton;
		_creditsButton.y = yCreditsButton;
		_creditsButton.width = widthCreditsButton;
		_creditsButton.height = heightCreditsButton;

		_exitButton.x = xExitButton;
		_exitButton.y = yExitButton;
		_exitButton.width = widthExitButton;
		_exitButton.height = heightExitButton;
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