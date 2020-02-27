#include "screens.h"

namespace Colortrack 
{

	Screens::Screens()
	{
		_gamestate = menu;
	}

	Screens::~Screens()
	{

	}

	void Screens::SetState(GameState gamestate)
	{
		_gamestate = gamestate;
	}

	Screens::GameState Screens::GetState()
	{
		return _gamestate;
	}

}