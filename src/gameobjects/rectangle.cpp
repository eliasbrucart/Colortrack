#include "rectangle.h"

#include "raylib.h"

namespace Colortrack
{
	RectangleEnemy::RectangleEnemy()
	{
		_x = 1;
		_y = 1;
		_width = 10;
		_height = 10;
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

	void RectangleEnemy::DrawRectangleEnemy()
	{
		DrawRectangle(rec.x, rec.y, rec.width, rec.height, WHITE);
	}

	void RectangleEnemy::MoveRectangleEnemy()
	{

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
}