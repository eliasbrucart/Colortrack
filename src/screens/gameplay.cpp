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
		player = new Player();
		enemy = new RectangleEnemy();
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
	}

	void Gameplay::Init()
	{
		InitWindow(640, 480, "Colortrack");
	}

	void Gameplay::Update()
	{
		player->SetInputs();
		player->CollisionWindow();
		enemy->MoveRectangleEnemy();
		enemy->RectangleEnemyOutOfScreen();
		CollisionsGame();
	}

	void Gameplay::CollisionsGame()
	{
		player->InitRectanglePlayer();
		enemy->InitRectangleEnemy();
		player->SetPlayerColors(player->playerGreen);
		enemy->SetRectangleEnemyColors(enemy->rectangleEnemyGreen);
		if (player->playerColors == player->playerGreen && enemy->rectangleEnemyColors == enemy->rectangleEnemyGreen)
		{
			if (CheckCollisionRecs(player->rec, enemy->rec))
			{
				player->SetPlayerColors(player->playerBlue);
			}
		}
	}

	void Gameplay::Draw()
	{		
		DrawRectangleRec(player->rec, player->GetColor());
		DrawRectangleRec(enemy->rec, enemy->GetColor());
	}
}