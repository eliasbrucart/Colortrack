#include "credits.h"

#include "raylib.h"

#include "game_loop.h"
#include"gameplay.h"

namespace Colortrack
{
	int pointsEarnedPosX = GetScreenWidth() / 4;
	int pointsEarnedPosY = GetScreenHeight() / 2.5;
	int pointsFontSize = 20;
	Credits::Credits(Gameplay* gameplay)
	{
		_mainMenu.x = GetScreenWidth() / 2 - 75;
		_mainMenu.y = GetScreenHeight() / 3;
		_mainMenu.width = 150;
		_mainMenu.height = 50;
		_gameplay = gameplay;
	}

	Credits::~Credits()
	{
	}

	void Credits::Input()
	{
		_mouse = GetMousePosition();

		if (CheckCollisionPointRec(_mouse, _mainMenu))
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				_gameplay->Init();
				state = GameState::game;
			}
		}
	}

	void Credits::Draw()
	{
		DrawText(TextFormat("Points Earned: %i", _gameplay->GetPoints()), pointsEarnedPosX, pointsEarnedPosX, pointsFontSize, WHITE);
 		DrawRectangle(_mainMenu.x, _mainMenu.y, _mainMenu.width, _mainMenu.height, GREEN);
	}
}