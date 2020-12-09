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
		Vector2 _speed;
		Color _color;
		bool _outOfScreen;
		bool _changedShape;
		bool _activeMovement;
		bool _rotateEnemy;
	public:
		RectangleEnemy();
		RectangleEnemy(float x, float y, float width, float height, Vector2 speed, Color color, bool outOfScreen, bool changedShape, bool activeMovement, bool rotateEnemy);
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
		float GetSpeedX();
		float GetSpeedY();
		void SetSpeedX(float speed);
		void SetSpeedY(float speed);
		bool GetOutOfScreen();
		void SetOutOfScreen(int outOfScreen);
		bool GetChangedShape();
		void SetChangedShape(bool changedShape);
		Color GetColor();
		Colors GetColors();
		void RectangleEnemyOutOfScreen();
		void SetActiveMovement(bool activeMovement);
		bool GetActiveMovement();
		void SetRotationEnemy(bool rotateEnemy);
		bool GetRotationEnemy();
		Colors rectangleEnemyColors;
		void SetColor(Colors color);
		void SetRectangleEnemyColors(Colors color);
	};
}

#endif