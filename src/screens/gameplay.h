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
		RectangleEnemy* rectangleEnemy2;
		CircleEnemy* circleEnemy;
		float _time;
		int _points;
		bool _pause;
	public:
		Gameplay();
		~Gameplay();
		void Init();
		void SetEnemiesColors();
		void SetPlayerColors();
		bool CheckEnemiesColors();
		bool CheckEnemiesPlayerColors();
		void CollisionsGame();
		void CheckPlayerAlive();
		void GenerateShapes();
		void SetPause();
		void Update();
		int GetPoints();
		void Draw();
		void Unload();
	};
}

#endif