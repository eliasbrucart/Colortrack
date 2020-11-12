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
		Vector2 _speed1;
		Color _color;
		bool _outOfScreen;
		bool _changedShape;
		bool _activeMovement;
	public:
		RectangleEnemy();
		RectangleEnemy(float x, float y, float width, float height, float speed, Vector2 speed1);
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
		bool GetOutOfScreen();
		void SetOutOfScreen(int outOfScreen);
		bool GetChangedShape();
		void SetChangedShape(bool changedShape);
		Color GetColor();
		Colors GetColors();
		void RectangleEnemyOutOfScreen();
		void SetActiveMovement(bool activeMovement);
		bool GetActiveMovement();
		Colors rectangleEnemyColors;
		void SetColor(Colors color);
		void SetRectangleEnemyColors(Colors color);
	};
}

#endif