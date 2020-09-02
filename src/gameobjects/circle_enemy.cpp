#include "circle_enemy.h"

namespace Colortrack
{
	CircleEnemy::CircleEnemy()
	{
		_x = 1.0f;
		_y = 1.0f;
		_radius = 10.0f;
		_center = {1.0f, 1.0f};
		_color = WHITE;
	}

	CircleEnemy::CircleEnemy(float x, float y, float radius, Vector2 center, Color color)
	{
		_x = x;
		_y = y;
		_radius = radius;
		_center = center;
		_color = color;
	}

	CircleEnemy::~CircleEnemy()
	{

	}

	void CircleEnemy::SetX(float x)
	{
		_x = x;
	}

	float CircleEnemy::GetX()
	{
		return _x;
	}

	void CircleEnemy::SetY(float y)
	{
		_y = y;
	}

	float CircleEnemy::GetY()
	{
		return _y;
	}

	void CircleEnemy::SetRadius(float radius)
	{
		_radius = radius;
	}

	float CircleEnemy::GetRadius()
	{
		return _radius;
	}

	void CircleEnemy::SetCenter(Vector2 center)
	{
		_center = center;
	}

	Vector2 CircleEnemy::GetCenter() 
	{
		return _center;
	}

	void CircleEnemy::SetColor(Color color)
	{
		_color = color;
	}

	Color CircleEnemy::GetColor()
	{
		return _color;
	}

	void CircleEnemy::MoveCircleEnemy()
	{
		_y += 200.0f * GetFrameTime();
	}

	void CircleEnemy::InitCircleEnemy()
	{

	}

	void CircleEnemy::CircleEnemyOutOfScreen()
	{
		if (_y + _radius >= GetScreenHeight()) 
		{
			_y = 0.0f;
		}
	}
}