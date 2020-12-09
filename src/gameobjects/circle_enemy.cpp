#include "circle_enemy.h"

#include"screens/game_loop.h"

namespace Colortrack
{
	static const float negativeSpeed = -1.0f;
	static const float setCircleUp = -200.0f;
	CircleEnemy::CircleEnemy()
	{
		_x = 1.0f;
		_y = 1.0f;
		_radius = 10.0f;
		_color = WHITE;
	}

	CircleEnemy::CircleEnemy(float x, float y, float radius, Color color, Vector2 speed, bool activeMovementInX, bool activeMovementInY)
	{
		_x = x;
		_y = y;
		_radius = radius;
		_color = color;
		_speed.x = speed.x;
		_speed.y = speed.y;
		_activeMovementInX = activeMovementInX;
		_activeMovementInY = activeMovementInY;
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

	Colors CircleEnemy::GetColors()
	{
		return circleEnemyColors;
	}

	void CircleEnemy::SetSpeedX(float speedX)
	{
		_speed.x = speedX;
	}

	float CircleEnemy::GetSpeedX()
	{
		return _speed.x;
	}

	void CircleEnemy::SetSpeedY(float speedY)
	{
		_speed.y = speedY;
	}

	float CircleEnemy::GetSpeedY()
	{
		return _speed.y;
	}

	void CircleEnemy::SetActiveMovementInX(bool activeMovementInX)
	{
		_activeMovementInX = activeMovementInX;
	}

	bool CircleEnemy::GetActiveMovementInX()
	{
		return _activeMovementInX;
	}

	void CircleEnemy::SetActiveMovementInY(bool activeMovementInY)
	{
		_activeMovementInY = activeMovementInY;
	}

	bool CircleEnemy::GetActiveMovementInY()
	{
		return _activeMovementInY;
	}

	void CircleEnemy::MoveCircleEnemy()
	{
		float setPreviusPosition = static_cast<float>(GetScreenWidth()) - _radius;;
		float setPreviusPosition2 = static_cast<float>(minScreenWidth) + _radius;
		if (_activeMovementInY == true)
			_y += _speed.y * GetFrameTime();
		if (_activeMovementInX == true)
		{
			_x += _speed.x * GetFrameTime();
			if (_x + _radius >= GetScreenWidth())
			{
				_speed.x *= negativeSpeed;
				_x = setPreviusPosition;
			}
			if (_x - _radius <= minScreenWidth)
			{
				_speed.x *= negativeSpeed;
				_x = setPreviusPosition2;
			}
		}
	}

	void CircleEnemy::CircleEnemyOutOfScreen()
	{
		if (_y + _radius >= GetScreenHeight())
			_y = setCircleUp;
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