#include<iostream>
#include "raylib.h"

#include "gameplay.h"
#include "gameobjects/colors.h"

using namespace std;

namespace Colortrack
{
	Gameplay::Gameplay()
	{
		player = NULL;
		rectangleEnemy = NULL;
		circleEnemy = NULL;
		player = new Player(320.0f, 340.0f, 20.0f, 20.0f, 300.0f, 1);
		rectangleEnemy = new RectangleEnemy(100.0f, -100.0f, 50.0f, 50.0f, 100.0f);
		circleEnemy = new CircleEnemy(300.0f, -100.0f, 20.0f, GREEN);
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
		if (circleEnemy != NULL)
		{
			delete circleEnemy;
		}
	}

	void Gameplay::Init()
	{
		InitWindow(640, 480, "Colortrack");
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

		circleEnemy->SetCircleEnemyColors(circleEnemy->circleEnemyColors = Colors::colorGreen);
	}

	void Gameplay::Update()
	{
		player->InitRectanglePlayer();
		rectangleEnemy->InitRectangleEnemy();
		player->SetInputs();
		player->CollisionWindow();
		rectangleEnemy->MoveRectangleEnemy();
		rectangleEnemy->RectangleEnemyOutOfScreen();
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
		}
		if (CheckCollisionCircleRec(circleEnemy->GetPosition(), circleEnemy->GetRadius(), player->rec))
		{
			if (player->playerColors != circleEnemy->circleEnemyColors)
			{
				player->SetLives(0);
				player->SetX(-1000.0f);
			}
		}
	}

	void Gameplay::Draw()
	{		
		DrawRectangleRec(player->rec, player->GetColor());
		DrawRectangleRec(rectangleEnemy->rec, rectangleEnemy->GetColor());
		DrawCircle(static_cast<int>(circleEnemy->GetX()), static_cast<int>(circleEnemy->GetY()), circleEnemy->GetRadius(), circleEnemy->GetColor());
	}
}