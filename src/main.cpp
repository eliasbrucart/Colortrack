#include "screens/game_loop.h"
using namespace Colortrack;

int main(void) 
{
	GameLoop* gl = new GameLoop();
	if (gl != NULL)
		gl->Loop();
	if (gl != NULL) {
		delete gl;
		gl = NULL;
	}
}