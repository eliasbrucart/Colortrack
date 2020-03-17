#ifndef RECTANGLE_H
#define RECTANGLE_H

namespace Colortrack 
{
	class Rectangle
	{
	private:
		int _x;
		int _y;
		int _width;
		int _height;
	public:
		void InitRectangleEnemy();
		void DrawRectangleEnemy();
		void MoveRectangleEnemy();
		void SetX();
		int GetX(int x);
		void SetY();
		int GetY(int y);
		void SetWidth();
		int GetWidth(int width);
		void SetHeight();
		int GetHeight(int height);
	};
}

#endif
