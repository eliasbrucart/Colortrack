#include "rectangle_enemy.h"

#include "raylib.h"

#include<iostream>
using namespace std;

namespace Colortrack
{
	RectangleEnemy::RectangleEnemy()
	{
		_x = 100.0f;
		_y = 100.0f;
		_width = 50.0f;
		_height = 50.0f;
		_speed = 100.0f;
		_color = WHITE;
		rectangleEnemyColors = Colors::colorGreen;
	}

	RectangleEnemy::RectangleEnemy(float x, float y, float width, float height, float speed)
	{
		_x = x;
		_y = y;
		_width = width;
		_height = height;
		_speed = speed;
		rectangleEnemyColors = Colors::colorGreen;
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

	void RectangleEnemy::SetX(float x)
	{
		_x = x;
	}

	float RectangleEnemy::GetX()
	{
		return _x;
	}

	void RectangleEnemy::SetY(float y)
	{
		_y = y;
	}

	float RectangleEnemy::GetY()
	{
		return _y;
	}

	void RectangleEnemy::SetWidth(float width)
	{
		_width = width;
	}

	float RectangleEnemy::GetWidth() 
	{
		return _width;
	}

	void RectangleEnemy::SetHeight(float height)
	{
		_height = height;
	}

	float RectangleEnemy::GetHeight()
	{
		return _height;
	}

	float RectangleEnemy::GetSpeed()
	{
		return _speed;
	}

	void RectangleEnemy::SetSpeed(float speed)
	{
		_speed = speed;
	}

	int RectangleEnemy::GetOutOfScreen()
	{
		return _outOfScreen;
	}

	void RectangleEnemy::SetOutOfScreen(int outOfScreen) 
	{
		_outOfScreen = outOfScreen;
	}

	bool RectangleEnemy::GetChangedShape()
	{
		return _changedShape;
	}

	void RectangleEnemy::SetChangedShape(bool changedShape)
	{
		_changedShape = changedShape;
	}

	void RectangleEnemy::SetColor(Colors color)
	{
		rectangleEnemyColors = color;
		SetRectangleEnemyColors(color);
	}

	Color RectangleEnemy::GetColor()
	{
		return _color;
	}

	Colors RectangleEnemy::GetColors()
	{
		return rectangleEnemyColors;
	}

	void RectangleEnemy::MoveRectangleEnemy()
	{
		_y += _speed * GetFrameTime();
	}

	void RectangleEnemy::RectangleEnemyOutOfScreen()
	{
		if (_y + _height >= GetScreenHeight())
		{
			_y = -200.0f;
			_changedShape = false;
		}
		else if (_y < 0.0f || _y > GetScreenHeight())
		{
			_outOfScreen = 1;
			cout << "Esta afuera" << endl;
		}
		else if(_y + _height >= 0.0f && _y <= GetScreenHeight())
		{
			_outOfScreen = 0;
			cout << "Esta adentro" << endl;
		}
		else if(_x + _width >= GetScreenWidth())
		{
			_x = -200.0f;
		}
		else if (_x < 0.0f || _x > GetScreenWidth())
		{
			_outOfScreen = 1;
			cout << "Esta afuera" << endl;
		}
		else if (_x >= 0.0f && _x <= GetScreenWidth())
		{
			_outOfScreen = 0;
			cout << "Esta adentro" << endl;
		}
	}

	void RectangleEnemy::SetRectangleEnemyColors(Colors color)
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
		}
	}
}