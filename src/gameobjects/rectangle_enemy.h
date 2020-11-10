#ifndef RECTANGLE_ENEMY_H
#define RECTANGLE_ENEMY_H

#include "raylib.h"
#include "colors.h"

namespace Colortrack 
{
	class RectangleEnemy
	{
	private:
		Rectangle _rec;
		float _speed;
		Color _color;
		bool _outOfScreen;
		bool _changedShape;
	public:
		RectangleEnemy();
		RectangleEnemy(float x, float y, float width, float height, float speed);
		~RectangleEnemy();
		void MoveRectangleEnemy();
		void SetX(float x);
		float GetX();
		void SetY(float y);
		float GetY();
		Rectangle GetRectangleEnemyRec();
		void SetWidth(float width);
		float GetWidth();
		void SetHeight(float height);
		float GetHeight();
		float GetSpeed();
		void SetSpeed(float speed);
		int GetOutOfScreen();
		void SetOutOfScreen(int outOfScreen);
		bool GetChangedShape();
		void SetChangedShape(bool changedShape);
		Color GetColor();
		Colors GetColors();
		void RectangleEnemyOutOfScreen();
		Colors rectangleEnemyColors;
		void SetColor(Colors color);
		void SetRectangleEnemyColors(Colors color);
	};
}

#endif