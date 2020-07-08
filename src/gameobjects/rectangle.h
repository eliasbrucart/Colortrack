#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "raylib.h"

namespace Colortrack 
{
	class RectangleEnemy
	{
	private:
		float _x;
		float _y;
		float _width;
		float _height;
		float _speed;
	public:
		RectangleEnemy();
		~RectangleEnemy();
		void InitRectangleEnemy();
		void DrawRectangleEnemy();
		void MoveRectangleEnemy();
		void SetX(int x);
		int GetX();
		void SetY(int y);
		int GetY();
		void SetWidth(int width);
		int GetWidth();
		void SetHeight(int height);
		int GetHeight();
		Rectangle rec;
	};
}

#endif
