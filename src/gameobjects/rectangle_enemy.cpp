#include "rectangle_enemy.h"

#include "raylib.h"

namespace Colortrack
{
	RectangleEnemy::RectangleEnemy()
	{
		_x = 100.0f;
		_y = 100.0f;
		_width = 100.0f;
		_height = 50.0f;
		_speed = 200.0f;
		_color = WHITE;
	}

	RectangleEnemy::~RectangleEnemy()
	{

	}

	void RectangleEnemy::InitRectangleEnemy()
	{
		rec.x = _x;
		rec.y = _y;
		rec.width = _width;
		rec.height = _height;
	}

	void RectangleEnemy::MoveRectangleEnemy()
	{
		_x += _speed * GetFrameTime();
	}

	void RectangleEnemy::SetX(int x)
	{
		_x = x;
	}

	int RectangleEnemy::GetX()
	{
		return _x;
	}

	void RectangleEnemy::SetY(int y)
	{
		_y = y;
	}

	int RectangleEnemy::GetY()
	{
		return _y;
	}

	void RectangleEnemy::SetWidth(int width)
	{
		_width = width;
	}

	int RectangleEnemy::GetWidth() 
	{
		return _width;
	}

	void RectangleEnemy::SetHeight(int height)
	{
		_height = height;
	}

	int RectangleEnemy::GetHeight()
	{
		return _height;
	}

	void RectangleEnemy::SetColor(Color color)
	{
		_color = color;
	}

	Color RectangleEnemy::GetColor()
	{
		return _color;
	}

	void RectangleEnemy::RectangleEnemyOutOfScreen()
	{
		if (_y + _height >= GetScreenHeight()) 
		{
			_y = 0;
		}
		if(_x + _width >= GetScreenWidth())
		{
			_x = 0;
		}
	}
}