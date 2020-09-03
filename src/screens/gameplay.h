#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "gameobjects/player.h"
#include "gameobjects/circle_enemy.h"
#include "gameobjects/rectangle_enemy.h"

namespace Colortrack
{
	class Gameplay
	{
	private:
		Player* player;
		RectangleEnemy* enemy;
		CircleEnemy* circleEnemy;
		float _time;
	public:
		Gameplay();
		~Gameplay();
		void Init();
		void Update();
		void CollisionsGame();
		void Draw();
	};
}

#endif