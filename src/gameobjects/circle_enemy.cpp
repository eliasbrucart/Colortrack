#include "circle_enemy.h"

namespace Colortrack
{
	CircleEnemy::CircleEnemy()
	{
		_x = 1.0f;
		_y = 1.0f;
		_radius = 10.0f;
		_color = WHITE;
	}

	CircleEnemy::CircleEnemy(float x, float y, float radius, Color color)
	{
		_x = x;
		_y = y;
		_radius = radius;
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

	Vector2 CircleEnemy::GetPosition() 
	{
		return Vector2{_x, _y};
	}

	void CircleEnemy::SetColor(Colors color)
	{
		circleEnemyColors = color;
		SetCircleEnemyColors(color);
	}

	Color CircleEnemy::GetColor()
	{
		return _color;
	}

	void CircleEnemy::MoveCircleEnemy()
	{
		_y += 100.0f * GetFrameTime();
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

	void CircleEnemy::SetCircleEnemyColors(Colors color) 
	{
		switch (color)
		{
		case colorGreen:
			_color = GREEN;
			break;
		case colorRed:
			_color = RED;
			break;
		case colorYellow:
			_color = YELLOW;
			break;
		case colorBlue:
			_color = BLUE;
			break;
		case colorOrange:
			_color = ORANGE;
			break;
		default:
			break;
		}
	}
}