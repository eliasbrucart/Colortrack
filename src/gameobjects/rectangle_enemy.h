#ifndef RECTANGLE_ENEMY_H
#define RECTANGLE_ENEMY_H

#include "raylib.h"
#include "colors.h"

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
		RectangleEnemy(float x, float y, float width, float height, float speed);
		~RectangleEnemy();
		void MoveRectangleEnemy();
		void SetX(int x);
		float GetX();
		void SetY(int y);
		float GetY();
		void SetWidth(int width);
		float GetWidth();
		void SetHeight(int height);
		float GetHeight();
		Color GetColor();
		Rectangle rec;
		void InitRectangleEnemy();
		void RectangleEnemyOutOfScreen();
		Colors rectangleEnemyColors;
		void SetColor(Colors color);
		void SetRectangleEnemyColors(Colors color);
	};
}

#endif