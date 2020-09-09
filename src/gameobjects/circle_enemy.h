#ifndef CIRCLE_ENEMY_H
#define CIRCLE_ENEMY_H

#include "raylib.h"
#include "colors.h"

namespace Colortrack 
{
	class CircleEnemy
	{
	private:
		float _x;
		float _y;
		float _radius;
		Color _color;
	public:
		CircleEnemy();
		CircleEnemy(float x, float y, float radius, Color color);
		~CircleEnemy();
		void SetX(float x);
		float GetX();
		void SetY(float y);
		float GetY();
		void SetRadius(float radius);
		float GetRadius();
		Vector2 GetPosition();
		void SetColor(Colors color);
		Color GetColor();
		void MoveCircleEnemy();
		void InitCircleEnemy();
		void CircleEnemyOutOfScreen();
		Colors circleEnemyColors;
		void SetCircleEnemyColors(Colors color);
	};
}

#endif