#include<iostream>
#include "raylib.h"

#include "gameplay.h"

using namespace std;

namespace Colortrack
{
	Gameplay::Gameplay()
	{
		player = NULL;
		enemy = NULL;
		circleEnemy = NULL;
		player = new Player(320.0f, 340.0f, 10.0f, 10.0f, 300.0f, 1);
		enemy = new RectangleEnemy(100.0f, 100.0f, 50.0f, 50.0f, 100.0f);
		circleEnemy = new CircleEnemy(300.0f, 200.0f, 20.0f, GREEN);
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
		player->SetPlayerColors(player->playerGreen);
		enemy->SetRectangleEnemyColors(enemy->rectangleEnemyGreen);
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
	}

	void Gameplay::CollisionsGame()
	{
		player->InitRectanglePlayer();
		enemy->InitRectangleEnemy();
		if (player->playerColors == player->playerGreen && enemy->rectangleEnemyColors == enemy->rectangleEnemyGreen)
		{
			if (CheckCollisionRecs(player->rec, enemy->rec))
			{
				player->SetPlayerColors(player->playerBlue);
			}
		}
		if (CheckCollisionCircleRec(circleEnemy->GetPosition(), circleEnemy->GetRadius(), player->rec))
		{
			player->SetPlayerColors(player->playerBlue);
		}
	}

	void Gameplay::Draw()
	{		
		DrawRectangleRec(player->rec, player->GetColor());
		DrawRectangleRec(enemy->rec, enemy->GetColor());
		DrawCircle(static_cast<int>(circleEnemy->GetX()), static_cast<int>(circleEnemy->GetY()), circleEnemy->GetRadius(), circleEnemy->GetColor());
	}
}