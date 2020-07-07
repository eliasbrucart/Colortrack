#include "raylib.h"

#include "game_loop.h"
#include "screens.h"
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
		player->CollisionWindow();
	}

	void Draw()
	{
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
			Update();
			BeginDrawing();
			ClearBackground(BLACK);
			Draw();
			EndDrawing();
		}
		DeleteObjects();
	}

}