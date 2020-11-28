#include "menu.h"

#include "game_loop.h"

namespace Colortrack
{
	float xPlayButton = 300.0f;
	float yPlayButton = 100.0f;
	float widthPlayButton = 100.0f;
	float heightPlayButton = 50.0f;

	float xTutorialButton = 300.0f;
	float yTutorialButton = 200.0f;
	float widthTutorialButton = 100.0f;
	float heightTutorialButton = 50.0f;

	float xExitButton = 300.0f;
	float yExitButton = 300.0f;
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
		DrawRectangle(_playButton.x, _playButton.y, _playButton.width, _playButton.height, GREEN);
		DrawRectangle(_tutorialButton.x, _tutorialButton.y, _tutorialButton.width, _tutorialButton.height, YELLOW);
		DrawRectangle(_exitButton.x, _exitButton.y, _exitButton.width, _exitButton.height, RED);

		switch (_mouseHoverInButton) {
		case play:
			DrawRectangle(_playButton.x, _playButton.y, _playButton.width, _playButton.height, LIME);
			break;
		case tutorial:
			DrawRectangle(_tutorialButton.x, _tutorialButton.y, _tutorialButton.width, _tutorialButton.height, GOLD);
			break;
		case exit:
			DrawRectangle(_exitButton.x, _exitButton.y, _exitButton.width, _exitButton.height, PINK);
			break;
		case noHover:
			break;
		}
	}
}