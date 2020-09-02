#ifndef CIRCLE_ENEMY_H
#define CIRCLE_ENEMY_H

#include "raylib.h"

namespace Colortrack 
{
	class CircleEnemy
	{
	private:
		float _x;
		float _y;
		float _radius;
		Vector2 _center;
		Color _color;
	public:
		CircleEnemy();
		CircleEnemy(float x, float y, float radius, Vector2 center, Color color);
		~CircleEnemy();
		void SetX(float x);
		float GetX();
		void SetY(float y);
		float GetY();
		void SetRadius(float radius);
		float GetRadius();
		void SetCenter(Vector2 center);
		Vector2 GetCenter();
		void SetColor(Color color);
		Color GetColor();
		void MoveCircleEnemy();
		void InitCircleEnemy();
		void CircleEnemyOutOfScreen();
	};
}

#endif