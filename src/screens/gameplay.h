#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "gameobjects/player.h"
#include "gameobjects/rectangle_enemy.h"

namespace Colortrack
{
	class Gameplay
	{
	private:
		Player* player;
		RectangleEnemy* enemy;
	public:
		Gameplay();
		~Gameplay();
		void Init();
		void Update();
		void Draw();
	};
}

#endif