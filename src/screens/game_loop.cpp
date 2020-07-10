#include "raylib.h"

#include "game_loop.h"
#include "gameobjects/player.h"
#include "gameobjects/rectangle_enemy.h"

namespace Colortrack
{

	Player* player = new Player();
	RectangleEnemy* enemy = new RectangleEnemy();

	void Init() 
	{
		InitWindow(640, 480, "Colortrack");
	}

	void DeleteObjects()
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

	void Update()
	{
		player->SetInputs();
		player->CollisionWindow();
		enemy->MoveRectangleEnemy();
		enemy->RectangleEnemyOutOfScreen();
	}

	void Draw()
	{
		DrawRectangle(player->GetX(), player->GetY(), player->GetWidth(), player->GetHeight(), WHITE);
		DrawRectangle(enemy->GetX(), enemy->GetY(), enemy->GetWidth(), enemy->GetHeight(), GREEN);
	}

	void Unload()
	{

	}

	void Loop()
	{
		Init();
		while (!WindowShouldClose())
		{
			Update();
			BeginDrawing();
			ClearBackground(BLACK);
			Draw();
			EndDrawing();
		}
		DeleteObjects();
	}

}