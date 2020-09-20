#include<iostream>
#include "raylib.h"

#include "gameplay.h"
#include "gameobjects/colors.h"

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
		player = new Player(320.0f, 340.0f, 20.0f, 20.0f, 300.0f, 1);
		rectangleEnemy = new RectangleEnemy(0.0f, -100.0f, GetScreenWidth()/2, 50.0f, 100.0f);
		rectangleEnemy2 = new RectangleEnemy(GetScreenWidth() / 2, -100.0f, GetScreenWidth() / 2 - 0.5f, 50.0f, 100.0f);
		circleEnemy = new CircleEnemy(300.0f, -100.0f, 20.0f, GREEN);
		_time = 0.0f;
		_points = 0;
	}

	Gameplay::~Gameplay()
	{
		if (player != NULL)
		{
			delete player;
		}
		if (rectangleEnemy != NULL)
		{
			delete rectangleEnemy;
		}
		if (rectangleEnemy2 != NULL)
		{
			delete rectangleEnemy2;
		}
		if (circleEnemy != NULL)
		{
			delete circleEnemy;
		}
	}

	void Gameplay::Init()
	{
		static int randomColorPlayer = GetRandomValue(1, 5);
		static int randomColorRectangleEnemy = GetRandomValue(1, 5);
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
		rectangleEnemy2->SetRectangleEnemyColors(rectangleEnemy2->rectangleEnemyColors = Colors::colorOrange);
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
	}
	
	void Gameplay::CollisionsGame()
	{
		if (CheckCollisionRecs(player->rec, rectangleEnemy->rec))
		{
			if (player->playerColors != rectangleEnemy->rectangleEnemyColors)
			{
				player->SetLives(0);
				player->SetX(-1000.0f);
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
				player->SetX(-1000.0f);
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
				player->SetX(-1000.0f);
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

	void Gameplay::Draw()
	{
		DrawRectangleRec(player->rec, player->GetColor());
		DrawRectangleRec(rectangleEnemy->rec, rectangleEnemy->GetColor());
		DrawRectangleRec(rectangleEnemy2->rec, rectangleEnemy2->GetColor());
		DrawCircle(static_cast<int>(circleEnemy->GetX()), static_cast<int>(circleEnemy->GetY()), circleEnemy->GetRadius(), circleEnemy->GetColor());
		DrawText(TextFormat("Points: %i", _points), 2, 2, 20, WHITE);
	}
}