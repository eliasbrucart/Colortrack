#include "raylib.h"

#include "gameplay.h"

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
	}

	void Gameplay::Draw()
	{
		DrawRectangle(player->GetX(), player->GetY(), player->GetWidth(), player->GetHeight(), GREEN);
		DrawRectangle(enemy->GetX(), enemy->GetY(), enemy->GetWidth(), enemy->GetHeight(), YELLOW);
	}
}