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
		float _rotation;
		Vector2 mouse;
		Rectangle _pauseRec;
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
		int GetPoints();
		void PowerUp();
		void PopUp();
		void Update();
		void Draw();
		void Unload();
	};
}

#endif