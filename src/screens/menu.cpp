#include "menu.h"

namespace Colortrack
{
	static float xPlayButton = 200.0f;
	static float yPlayButton = 150.0f;
	static float widthPlayButton = 100.0f;
	static float heightPlayButton = 50.0f;

	static float xTutorialButton = 300.0f;
	static float yTutorialButton = 250.0f;
	static float widthTutorialButton = 100.0f;
	static float heightTutorialButton = 50.0f;

	static float xExitButton = 400.0f;
	static float yExitButton = 350.0f;
	static float widthExitButton = 100.0f;
	static float heightExitButton = 50.0f;
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

	}

	void Menu::Input()
	{

	}
}