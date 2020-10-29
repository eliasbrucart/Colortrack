#include<iostream>
#include "raylib.h"

#include "gameplay.h"
#include "game_loop.h"
#include "gameobjects/colors.h"
#include "credits.h"

#include "gameobjects/player.h"
#include "gameobjects/circle_enemy.h"
#include "gameobjects/rectangle_enemy.h"

using namespace std;

namespace Colortrack
{
	static int flag = 1;
	Gameplay::Gameplay()
	{
		player = NULL;
		rectangleEnemy = NULL;
		rectangleEnemy2 = NULL;
		circleEnemy = NULL;
		player = new Player(320.0f, 340.0f, 20.0f, 20.0f, 300.0f, 1, false);
		rectangleEnemy = new RectangleEnemy(0.0f, -100.0f, static_cast<float>(GetScreenWidth() / 2), 50.0f, 100.0f);
		rectangleEnemy2 = new RectangleEnemy(static_cast<float>(GetScreenWidth() / 2), -100.0f, static_cast<float>(GetScreenWidth() / 2) - 0.5f, 50.0f, 100.0f);
		circleEnemy = new CircleEnemy(300.0f, -100.0f, 20.0f, GREEN);
		_time = 0.0f;
		_points = 0;
	}

	Gameplay::~Gameplay()
	{
		if (player != NULL)
		{
			delete player;
			player = NULL;
		}
		if (rectangleEnemy != NULL)
		{
			delete rectangleEnemy;
			rectangleEnemy = NULL;
		}
		if (rectangleEnemy2 != NULL)
		{
			delete rectangleEnemy2;
			rectangleEnemy2 = NULL;
		}
		if (circleEnemy != NULL)
		{
			delete circleEnemy;
			circleEnemy = NULL;
		}
	}

	void Gameplay::SetEnemiesColors()
	{
		static int randomColorPlayer = GetRandomValue(1, 5);
		static int randomColorRectangleEnemy = GetRandomValue(1, 5);
		static int randomColorRectangleEnemy2 = GetRandomValue(1, 5);
		static int randomColorCircleEnemy = GetRandomValue(1, 5);
		switch (randomColorPlayer)
		{
		case 1:
			player->SetPlayerColors(player->playerColors = Colors::colorGreen);
			break;
		case 2:
			player->SetPlayerColors(player->playerColors = Colors::colorRed);
			break;
		case 3:
			player->SetPlayerColors(player->playerColors = Colors::colorYellow);
			break;
		case 4:
			player->SetPlayerColors(player->playerColors = Colors::colorBlue);
			break;
		case 5:
			player->SetPlayerColors(player->playerColors = Colors::colorOrange);
			break;
		default:
			break;
		}

		switch (randomColorRectangleEnemy)
		{
		case 1:
			rectangleEnemy->SetRectangleEnemyColors(rectangleEnemy->rectangleEnemyColors = Colors::colorGreen);
			break;
		case 2:
			rectangleEnemy->SetRectangleEnemyColors(rectangleEnemy->rectangleEnemyColors = Colors::colorRed);
			break;
		case 3:
			rectangleEnemy->SetRectangleEnemyColors(rectangleEnemy->rectangleEnemyColors = Colors::colorYellow);
			break;
		case 4:
			rectangleEnemy->SetRectangleEnemyColors(rectangleEnemy->rectangleEnemyColors = Colors::colorBlue);
			break;
		case 5:
			rectangleEnemy->SetRectangleEnemyColors(rectangleEnemy->rectangleEnemyColors = Colors::colorOrange);
			break;
		default:
			break;
		}

		switch (randomColorCircleEnemy)
		{
		case 1:
			circleEnemy->SetCircleEnemyColors(circleEnemy->circleEnemyColors = Colors::colorGreen);
			break;
		case 2:
			circleEnemy->SetCircleEnemyColors(circleEnemy->circleEnemyColors = Colors::colorRed);
			break;
		case 3:
			circleEnemy->SetCircleEnemyColors(circleEnemy->circleEnemyColors = Colors::colorYellow);
			break;
		case 4:
			circleEnemy->SetCircleEnemyColors(circleEnemy->circleEnemyColors = Colors::colorBlue);
			break;
		case 5:
			circleEnemy->SetCircleEnemyColors(circleEnemy->circleEnemyColors = Colors::colorOrange);
			break;
		default:
			break;
		}

		switch (randomColorRectangleEnemy2)
		{
		case 1:
			rectangleEnemy2->SetRectangleEnemyColors(rectangleEnemy2->rectangleEnemyColors = Colors::colorGreen);
			break;
		case 2:
			rectangleEnemy2->SetRectangleEnemyColors(rectangleEnemy2->rectangleEnemyColors = Colors::colorRed);
			break;
		case 3:
			rectangleEnemy2->SetRectangleEnemyColors(rectangleEnemy2->rectangleEnemyColors = Colors::colorYellow);
			break;
		case 4:
			rectangleEnemy2->SetRectangleEnemyColors(rectangleEnemy2->rectangleEnemyColors = Colors::colorBlue);
			break;
		case 5:
			rectangleEnemy2->SetRectangleEnemyColors(rectangleEnemy2->rectangleEnemyColors = Colors::colorOrange);
			break;
		default:
			break;
		}
	}

	void Gameplay::SetPlayerColors()
	{
		Colors rectangleEnemyColor = rectangleEnemy->GetColors();
		Colors rectangleEnemyColor2 = rectangleEnemy2->GetColors();
		Colors circleEnemyColor = circleEnemy->GetColors();
		static int rand = GetRandomValue(1, 2);
		switch (rand)
		{
		case 1:
			player->SetPlayerColors(player->playerColors = rectangleEnemyColor);
			break;
		case 2:
			player->SetPlayerColors(player->playerColors = rectangleEnemyColor2);
			break;
		}
	}

	void Gameplay::Init()
	{

		player = NULL;
		rectangleEnemy = NULL;
		rectangleEnemy2 = NULL;
		circleEnemy = NULL;
		player = new Player(320.0f, 340.0f, 20.0f, 20.0f, 300.0f, 1, false);
		rectangleEnemy = new RectangleEnemy(0.0f, -100.0f, static_cast<float>(GetScreenWidth() / 2), 50.0f, 100.0f);
		rectangleEnemy2 = new RectangleEnemy(static_cast<float>(GetScreenWidth() / 2), -100.0f, static_cast<float>(GetScreenWidth() / 2) - 0.5f, 50.0f, 100.0f);
		circleEnemy = new CircleEnemy(300.0f, -100.0f, 20.0f, GREEN);
		_time = 0.0f;
		_points = 0;

		SetEnemiesColors();
		SetPlayerColors();

		if (rectangleEnemy->GetColors() == rectangleEnemy2->GetColors() && rectangleEnemy->GetColors() == circleEnemy->GetColors() && rectangleEnemy2->GetColors() == circleEnemy->GetColors() && player->GetColors() != rectangleEnemy->GetColors() && player->GetColors() != rectangleEnemy2->GetColors() && player->GetColors() != circleEnemy->GetColors())
		{
			SetEnemiesColors();
			SetPlayerColors();
		}
	}

	void Gameplay::CollisionsGame()
	{
		if (CheckCollisionRecs(player->rec, rectangleEnemy->rec))
		{
			if (player->playerColors != rectangleEnemy->rectangleEnemyColors)
			{
				player->SetLives(0);
			}
			else if (flag != 0)
			{
				_points += 100;
				flag = 0;
			}
		}
		else if (CheckCollisionRecs(player->rec, rectangleEnemy2->rec))
		{
			if (player->playerColors != rectangleEnemy2->rectangleEnemyColors)
			{
				player->SetLives(0);
			}
			else if (flag != 0)
			{
				_points += 100;
				flag = 0;
			}
		}
		else if (CheckCollisionCircleRec(circleEnemy->GetPosition(), circleEnemy->GetRadius(), player->rec))
		{
			if (player->playerColors != circleEnemy->circleEnemyColors)
			{
				player->SetLives(0);
			}
			else if (flag != 0)
			{
				_points += 100;
				flag = 0;
			}
		}
		else
		{
			flag = 1;
		}
	}

	void Gameplay::CheckPlayerAlive()
	{
		if (player->IsDead())
		{
			state = GameState::creditsScreen;
			//primero unload de todo, despues destruir en el loop.
		}
	}

	void Gameplay::GenerateShapes()
	{
		int randomShape = GetRandomValue(1, 5);
		switch (randomShape)
		{
		case 1:
			rectangleEnemy->SetWidth(320.0f);
			rectangleEnemy->SetHeight(30.0f);
			rectangleEnemy->SetChangedShape(true);
			rectangleEnemy2->SetWidth(320.0f);
			rectangleEnemy2->SetX(321.0f);
			rectangleEnemy2->SetHeight(30.0f);
			rectangleEnemy2->SetChangedShape(true);
			break;
		case 2:
			rectangleEnemy->SetWidth(150.0f);
			rectangleEnemy->SetHeight(20.0f);
			rectangleEnemy->SetChangedShape(true);
			rectangleEnemy2->SetWidth(150.0f);
			rectangleEnemy2->SetX(151.0f);
			rectangleEnemy2->SetHeight(20.0f);
			rectangleEnemy2->SetChangedShape(true);
			break;
		case 3:
			rectangleEnemy->SetWidth(200.0f);
			rectangleEnemy->SetHeight(50.0f);
			rectangleEnemy->SetChangedShape(true);
			rectangleEnemy2->SetWidth(200.0f);
			rectangleEnemy2->SetX(201.0f);
			rectangleEnemy2->SetHeight(50.0f);
			rectangleEnemy2->SetChangedShape(true);
			break;
		case 4:
			rectangleEnemy->SetWidth(500.0f);
			rectangleEnemy->SetHeight(70.0f);
			rectangleEnemy->SetChangedShape(true);
			rectangleEnemy2->SetWidth(500.0f);
			rectangleEnemy2->SetX(501.0f);
			rectangleEnemy2->SetHeight(70.0f);
			rectangleEnemy2->SetChangedShape(true);
			break;
		case 5:
			rectangleEnemy->SetWidth(90.0f);
			rectangleEnemy->SetHeight(45.0f);
			rectangleEnemy->SetChangedShape(true);
			rectangleEnemy2->SetWidth(90.0f);
			rectangleEnemy2->SetX(91.0f);
			rectangleEnemy2->SetHeight(45.0f);
			rectangleEnemy2->SetChangedShape(true);
			break;
		default:
			break;
		}
	}

	void Gameplay::Update()
	{
		player->InitRectanglePlayer();
		rectangleEnemy->InitRectangleEnemy();
		rectangleEnemy2->InitRectangleEnemy();
		player->SetInputs();
		player->CollisionWindow();
		rectangleEnemy->MoveRectangleEnemy();
		rectangleEnemy->RectangleEnemyOutOfScreen();
		rectangleEnemy2->MoveRectangleEnemy();
		rectangleEnemy2->RectangleEnemyOutOfScreen();
		circleEnemy->MoveCircleEnemy();
		circleEnemy->CircleEnemyOutOfScreen();
		CollisionsGame();
		CheckPlayerAlive();
		if (rectangleEnemy->GetOutOfScreen() == 1)
		{
			if(!rectangleEnemy->GetChangedShape())
				GenerateShapes();
		}
		else if (rectangleEnemy2->GetOutOfScreen() == 1) 
		{
			if (!rectangleEnemy2->GetChangedShape())
				GenerateShapes();
		}
	}

	int Gameplay::GetPoints()
	{
		return _points;
	}

	void Gameplay::Draw()
	{
		ClearBackground(BLACK);
		DrawRectangleRec(player->rec, player->GetColor());
		DrawRectangleRec(rectangleEnemy->rec, rectangleEnemy->GetColor());
		DrawRectangleRec(rectangleEnemy2->rec, rectangleEnemy2->GetColor());
		DrawCircle(static_cast<int>(circleEnemy->GetX()), static_cast<int>(circleEnemy->GetY()), circleEnemy->GetRadius(), circleEnemy->GetColor());
		DrawText(TextFormat("Points: %i", _points), 2, 2, 20, WHITE);
		if (player->IsDead())
		{
			DrawText("You Lose!", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2, 50, WHITE);
		}
	}

	void Gameplay::Unload() 
	{
		_time = 0.0f;
		_points = 0;
	}
}