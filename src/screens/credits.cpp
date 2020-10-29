#include "credits.h"

#include "raylib.h"

#include "game_loop.h"
#include"gameplay.h"

namespace Colortrack
{
	static Vector2 mouse;

	static int pointsEarnedPosX = GetScreenWidth() / 4;
	static int pointsEarnedPosY = GetScreenHeight() / 2.5;
	static int pointsFontSize = 20;
	Credits::Credits(Gameplay* gameplay)
	{
		_mainMenu.x = GetScreenWidth() / 2;
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
		mouse = GetMousePosition();

		if (CheckCollisionPointRec(mouse, _mainMenu))
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