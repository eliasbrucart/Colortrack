#include "screens/game_loop.h"

using namespace Colortrack;

int main() 
{
	Loop();

	return 0;
	/*InitWindow(640, 480, "Colortrack");
	Rectangle player;
	player.x = 200.0f;
	player.y = 200.0f;
	player.width = 30.0f;
	player.height = 30.0f;
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		if (IsKeyDown(KEY_A))
		{
			player.x -= 600.0f * GetFrameTime();
		}
		if (IsKeyDown(KEY_D))
		{
			player.x += 600.0f * GetFrameTime();
		}
		
		DrawRectangle(player.x, player.y, player.width, player.height, WHITE);
		EndDrawing();
	}*/

}