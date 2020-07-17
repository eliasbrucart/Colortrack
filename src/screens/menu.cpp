#include "menu.h"

namespace Colortrack
{
	static float xPlayButton = 300.0f;
	static float yPlayButton = 100.0f;
	static float widthPlayButton = 100.0f;
	static float heightPlayButton = 50.0f;

	static float xTutorialButton = 300.0f;
	static float yTutorialButton = 200.0f;
	static float widthTutorialButton = 100.0f;
	static float heightTutorialButton = 50.0f;

	static float xExitButton = 300.0f;
	static float yExitButton = 300.0f;
	static float widthExitButton = 100.0f;
	static float heightExitButton = 50.0f;

	static Vector2 mouse;
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

	void Menu::Draw()
	{
		DrawRectangle(_playButton.x, _playButton.y, _playButton.width, _playButton.height, GREEN);
		DrawRectangle(_tutorialButton.x, _tutorialButton.y, _tutorialButton.width, _tutorialButton.height, YELLOW);
		DrawRectangle(_exitButton.x, _exitButton.y, _exitButton.width, _exitButton.height, RED);
	}

	void Menu::Input()
	{
		mouse = GetMousePosition();
	}
}