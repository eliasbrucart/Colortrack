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
		Vector2 _speed;
		bool _activeMovement;
	public:
		CircleEnemy();
		CircleEnemy(float x, float y, float radius, Color color, bool activeMovement, Vector2 speed);
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
		Colors GetColors();
		void SetSpeedX(float speedX);
		float GetSpeedX();
		void SetSpeedY(float speedY);
		float GetSpeedY();
		void SetActiveMovement(bool activeMovement);
		bool GetActiveMovement();
		void MoveCircleEnemy();
		void InitCircleEnemy();
		void CircleEnemyOutOfScreen();
		Colors circleEnemyColors;
		void SetCircleEnemyColors(Colors color);
	};
}

#endif