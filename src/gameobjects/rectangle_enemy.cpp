#include "rectangle_enemy.h"

#include "raylib.h"

#include<iostream>
using namespace std;

namespace Colortrack
{
	RectangleEnemy::RectangleEnemy()
	{
		_rec.x = 100.0f;
		_rec.y = 100.0f;
		_rec.width = 50.0f;
		_rec.height = 50.0f;
		_speed = 100.0f;
		_color = WHITE;
		_speed1.x = 100.0f;
		_speed1.y = 100.0f;
		rectangleEnemyColors = Colors::colorGreen;
	}

	RectangleEnemy::RectangleEnemy(float x, float y, float width, float height, float speed, Vector2 speed1)
	{
		_rec.x = x;
		_rec.y = y;
		_rec.width = width;
		_rec.height = height;
		_speed = speed;
		_speed1.x = speed1.x;
		_speed1.y = speed1.y;
		rectangleEnemyColors = Colors::colorGreen;
	}

	RectangleEnemy::~RectangleEnemy()
	{

	}

	void RectangleEnemy::SetX(float x)
	{
		_rec.x = x;
	}

	float RectangleEnemy::GetX()
	{
		return _rec.x;
	}

	void RectangleEnemy::SetY(float y)
	{
		_rec.y = y;
	}

	float RectangleEnemy::GetY()
	{
		return _rec.y;
	}

	Rectangle RectangleEnemy::GetRectangleEnemyRec()
	{
		return _rec;
	}

	void RectangleEnemy::SetWidth(float width)
	{
		_rec.width = width;
	}

	float RectangleEnemy::GetWidth() 
	{
		return _rec.width;
	}

	void RectangleEnemy::SetHeight(float height)
	{
		_rec.height = height;
	}

	float RectangleEnemy::GetHeight()
	{
		return _rec.height;
	}

	float RectangleEnemy::GetSpeed()
	{
		return _speed;
	}

	void RectangleEnemy::SetSpeed(float speed)
	{
		_speed = speed;
	}

	bool RectangleEnemy::GetOutOfScreen()
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
		_rec.y += _speed1.y * GetFrameTime();
		if (_activeMovement == true)
		{
			if (_rec.x > 0 && _rec.x < 640 || _rec.x + _rec.height > 0 && _rec.x + _rec.height < 640)
			{
				_rec.x += _speed1.x * GetFrameTime();
			}
			if (_rec.x + _rec.width >= GetScreenWidth())
			{
				_speed1.x *= -1.0f;
			}
			if (_rec.x <= 0)
			{
				_speed1.x *= -1.0f;
			}
		}
	}

	void RectangleEnemy::RectangleEnemyOutOfScreen()
	{
		if (_rec.height >= 250.0f)
		{
			if (_rec.y >= GetScreenHeight())
			{
				_rec.y = -200.0f;
				_changedShape = false;
			}
		}
		else if (_rec.y + _rec.height >= GetScreenHeight())
		{
			_rec.y = -200.0f;
			_changedShape = false;
		}
		else if (_rec.y < 0.0f || _rec.y > GetScreenHeight())
		{
			_outOfScreen = true;
			cout << "Esta afuera" << endl;
		}
		else if(_rec.y + _rec.height >= 0.0f && _rec.y <= GetScreenHeight())
		{
			_outOfScreen = false;
			cout << "Esta adentro" << endl;
		}
		else if(_rec.x + _rec.width >= GetScreenWidth())
		{
			_rec.x = -200.0f;
			_changedShape = false;
		}
		else if (_rec.x < 0.0f || _rec.x > GetScreenWidth())
		{
			_outOfScreen = true;
			cout << "Esta afuera" << endl;
		}
		else if (_rec.x >= 0.0f && _rec.x <= GetScreenWidth())
		{
			_outOfScreen = false;
			cout << "Esta adentro" << endl;
		}
	}

	void RectangleEnemy::SetActiveMovement(bool activeMovement)
	{
		_activeMovement = activeMovement;
	}

	bool RectangleEnemy::GetActiveMovement()
	{
		return _activeMovement;
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