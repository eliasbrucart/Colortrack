#include <iostream>
#include "raylib.h"

void main() 
{
	InitWindow(640, 480, "Colortrack");
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawRectangle(200, 200, 30, 30, WHITE);
		EndDrawing();
	}

}