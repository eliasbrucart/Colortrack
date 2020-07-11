#ifndef RECTANGLE_ENEMY_H
#define RECTANGLE_ENEMY_H

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
		Color _color;
	public:
		RectangleEnemy();
		~RectangleEnemy();
		void InitRectangleEnemy();
		void MoveRectangleEnemy();
		void SetX(int x);
		int GetX();
		void SetY(int y);
		int GetY();
		void SetWidth(int width);
		int GetWidth();
		void SetHeight(int height);
		int GetHeight();
		void SetColor(Color color);
		Color GetColor();
		Rectangle rec;
		void RectangleEnemyOutOfScreen();
	};
}

#endif
