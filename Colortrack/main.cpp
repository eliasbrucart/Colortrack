#include <iostream>
#include "raylib.h"

void main() 
{
	InitWindow(480, 640, "Colortrack");
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		EndDrawing();
	}

}