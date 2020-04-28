#include "raylib.h"
#include "game_loop.h"

namespace Colortrack
{

	void Init() 
	{
		InitWindow(640, 480, "Colortrack");
	}

	void DeleteObjects()
	{

	}

	void Update()
	{

	}

	void Draw()
	{
		ClearBackground(BLACK);
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
		}
		while (!WindowShouldClose())
		{
			Update();
		}
	}

}