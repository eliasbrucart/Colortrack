#include "raylib.h"

#include "game_loop.h"
#include "gameobjects/player.h"

namespace Colortrack
{

	Player* player = new Player();

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
	}

	void Update()
	{
		player->SetInputs();
	}

	void Draw()
	{
		ClearBackground(BLACK);
		DrawRectangle(player->GetX(), player->GetY(), player->GetWidth(), player->GetHeight(), WHITE);
	}

	void Unload()
	{

	}

	void Loop()
	{
		Init();
		while (!WindowShouldClose())
		{
			BeginDrawing();
			Draw();
			EndDrawing();
		}
		while (!WindowShouldClose())
		{
			Update();
		}
	}

}