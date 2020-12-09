#include "rectangle_enemy.h"

#include "raylib.h"

#include"screens/game_loop.h"

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
		_color = WHITE;
		_speed.x = 100.0f;
		_speed.y = 100.0f;
		rectangleEnemyColors = Colors::colorGreen;
	}

	RectangleEnemy::RectangleEnemy(float x, float y, float width, float height, Vector2 speed, Color color, bool outOfScreen, bool changedShape, bool activeMovement, bool rotateEnemy)
	{
		_rec.x = x;
		_rec.y = y;
		_rec.width = width;
		_rec.height = height;
		_speed.x = speed.x;
		_speed.y = speed.y;
		_color = color;
		_outOfScreen = outOfScreen;
		_changedShape = changedShape;
		_activeMovement = activeMovement;
		_rotateEnemy = rotateEnemy;
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

	float RectangleEnemy::GetSpeedX()
	{
		return _speed.x;
	}

	float RectangleEnemy::GetSpeedY()
	{
		return _speed.y;
	}

	void RectangleEnemy::SetSpeedX(float speed)
	{
		_speed.x = speed;
	}

	void RectangleEnemy::SetSpeedY(float speed)
	{
		_speed.y = speed;
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
		float negativeSpeed = -1.0f;
		_rec.y += _speed.y * GetFrameTime();
		if (_activeMovement == true)
		{
			if (_rec.x > minScreenWidth && _rec.x < GetScreenWidth() || _rec.x + _rec.height > minScreenWidth && _rec.x + _rec.height < GetScreenWidth())
			{
				_rec.x += _speed.x * GetFrameTime();
			}
			if (_rec.x + _rec.width >= GetScreenWidth())
			{
				_speed.x *= negativeSpeed;
			}
			if (_rec.x <= minScreenWidth)
			{
				_speed.x *= negativeSpeed;
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
		else if (_rec.y >= GetScreenHeight())
		{
			_rec.y = -200.0f;
			_changedShape = false;
		}
		else if (_rec.y < minScreenWidth || _rec.y > GetScreenHeight())
		{
			_outOfScreen = true;
		}
		else if(_rec.y + _rec.height >= minScreenHeight && _rec.y <= GetScreenHeight())
		{
			_outOfScreen = false;
		}
		else if(_rec.x + _rec.width >= GetScreenWidth())
		{
			_rec.x = -200.0f;
			_changedShape = false;
		}
		else if (_rec.x < minScreenWidth || _rec.x > GetScreenWidth())
		{
			_outOfScreen = true;
		}
		else if (_rec.x >= minScreenWidth && _rec.x <= GetScreenWidth())
		{
			_outOfScreen = false;
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

	void RectangleEnemy::SetRotationEnemy(bool rotateEnemy)
	{
		_rotateEnemy = rotateEnemy;
	}

	bool RectangleEnemy::GetRotationEnemy()
	{
		return _rotateEnemy;
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