#include "rectangle_enemy.h"

#include "raylib.h"

namespace Colortrack
{
	RectangleEnemy::RectangleEnemy()
	{
		_x = 100.0f;
		_y = 100.0f;
		_width = 50.0f;
		_height = 50.0f;
		_speed = 200.0f;
		_color = WHITE;
		rectangleEnemyColors = RectangleEnemyColors::rectangleEnemyGreen;
	}

	RectangleEnemy::RectangleEnemy(float x, float y, float width, float height, float speed, Color color)
	{
		_x = x;
		_y = y;
		_width = width;
		_height = height;
		_speed = speed;
		_color = color;
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

	void RectangleEnemy::SetColor(RectangleEnemyColors color)
	{
		rectangleEnemyColors = color;
		SetRectangleEnemyColors(color);
	}

	Color RectangleEnemy::GetColor()
	{
		return _color;
	}

	/*Color RectangleEnemy::GetColor()
	{
		return _color;
	}*/

	void RectangleEnemy::MoveRectangleEnemy()
	{
		_y += _speed * GetFrameTime();
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

	void RectangleEnemy::SetRectangleEnemyColors(RectangleEnemyColors color)
	{
		switch (color)
		{
		case rectangleEnemyGreen:
			_color = GREEN;
			break;
		case rectangleEnemyRed:
			_color = RED;
			break;
		case rectangleEnemyYellow:
			_color = YELLOW;
			break;
		case rectangleEnemyBlue:
			_color = BLUE;
			break;
		case rectangleEnemyOrange:
			_color = ORANGE;
			break;
		}
	}
}