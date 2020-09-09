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
		enemy = NULL;
		circleEnemy = NULL;
		player = new Player(320.0f, 340.0f, 20.0f, 20.0f, 300.0f, 1);
		enemy = new RectangleEnemy(100.0f, -100.0f, 50.0f, 50.0f, 100.0f);
		circleEnemy = new CircleEnemy(300.0f, -100.0f, 20.0f, GREEN);
	}

	Gameplay::~Gameplay()
	{
		if (player != NULL)
		{
			delete player;
		}
		if (enemy != NULL)
		{
			delete enemy;
		}
		if (circleEnemy != NULL)
		{
			delete circleEnemy;
		}
	}

	void Gameplay::Init()
	{
		InitWindow(640, 480, "Colortrack");
		player->SetPlayerColors(player->playerColors);
		enemy->SetRectangleEnemyColors(enemy->rectangleEnemyColors);
	}

	void Gameplay::Update()
	{
		player->SetInputs();
		player->CollisionWindow();
		enemy->MoveRectangleEnemy();
		enemy->RectangleEnemyOutOfScreen();
		circleEnemy->MoveCircleEnemy();
		circleEnemy->CircleEnemyOutOfScreen();
		CollisionsGame();
		_time += GetFrameTime();
	}

	void Gameplay::CollisionsGame()
	{
		player->InitRectanglePlayer();
		enemy->InitRectangleEnemy();
		if (player->playerColors == Colors::colorGreen && enemy->rectangleEnemyColors == Colors::colorGreen)
		{
			if (CheckCollisionRecs(player->rec, enemy->rec))
			{
				player->SetPlayerColors(player->playerColors = Colors::colorBlue);
			}
		}
		if (CheckCollisionCircleRec(circleEnemy->GetPosition(), circleEnemy->GetRadius(), player->rec))
		{
			player->SetPlayerColors(player->playerColors = Colors::colorBlue);
		}
	}

	void Gameplay::Draw()
	{		
		DrawRectangleRec(player->rec, player->GetColor());
		DrawRectangleRec(enemy->rec, enemy->GetColor());
		DrawCircle(static_cast<int>(circleEnemy->GetX()), static_cast<int>(circleEnemy->GetY()), circleEnemy->GetRadius(), circleEnemy->GetColor());
	}
}