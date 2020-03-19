#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "raylib.h"

namespace Colortrack 
{
	class RectangleEnemy
	{
	private:
		int _x;
		int _y;
		int _width;
		int _height;
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
