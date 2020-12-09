#include "screens/game_loop.h"
using namespace Colortrack;

int main() 
{
	GameLoop* gl = new GameLoop();
	if (gl != NULL)
	{
		gl->Loop();
		delete gl;
		gl = NULL;
	}
	return 0;
}