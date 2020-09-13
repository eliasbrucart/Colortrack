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
		RectangleEnemy* rectangleEnemy;
		CircleEnemy* circleEnemy;
		float _time;
		int _points;
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