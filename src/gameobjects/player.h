#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "colors.h"

namespace Colortrack
{
	class Player
	{
	private:
		float _x;
		float _y;
		float _width;
		float _height;
		float _speed;
		int _lives;
		bool _dead;
		Color _color;
	public:
		Player();
		Player(float x, float y, float width, float height, float speed, int lives, bool dead);
		~Player();
		void SetX(float x);
		float GetX();
		void SetY(float y);
		float GetY();
		void SetWidth(float width);
		float GetWidth();
		void SetHeight(float height);
		float GetHeight();
		Color GetColor();
		Colors GetColors();
		Rectangle rec;
		void SetInputs();
		void InitRectanglePlayer();
		void SetLives(int lives);
		int GetLives();
		bool IsDead();
		void CollisionWindow();
		Colors playerColors;
		void SetColor(Colors color);
		void SetPlayerColors(Colors color);
	};
}
#endif