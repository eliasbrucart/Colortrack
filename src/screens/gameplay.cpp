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
		static int randomColor = GetRandomValue(1, 5);
		switch (randomColor)
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
		enemy->SetRectangleEnemyColors(enemy->rectangleEnemyColors);
	}

	void Gameplay::Update()
	{
		player->InitRectanglePlayer();
		enemy->InitRectangleEnemy();
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
		if (player->playerColors == Colors::colorBlue && enemy->rectangleEnemyColors == Colors::colorGreen) 
		{
			if (CheckCollisionRecs(player->rec, enemy->rec))
			{
				player->SetLives(0);
				DrawText(TextFormat("Lives: %i", player->GetLives()), player->GetX() + 50.0f, player->GetY(), 20, WHITE);
			}
		}
		if (player->playerColors == Colors::colorGreen && enemy->rectangleEnemyColors == Colors::colorBlue) 
		{
			if (CheckCollisionRecs(player->rec, enemy->rec))
			{
				player->SetLives(0);
				DrawText(TextFormat("Lives: %i", player->GetLives()), player->GetX() + 50.0f, player->GetY(), 20, WHITE);
			}
		}
	}

	void Gameplay::Draw()
	{		
		DrawRectangleRec(player->rec, player->GetColor());
		DrawRectangleRec(enemy->rec, enemy->GetColor());
		DrawCircle(static_cast<int>(circleEnemy->GetX()), static_cast<int>(circleEnemy->GetY()), circleEnemy->GetRadius(), circleEnemy->GetColor());
	}
}