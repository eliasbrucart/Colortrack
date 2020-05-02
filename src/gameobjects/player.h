#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

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
	public:
		Player();
		Player(float x, float y, float width, float height, float speed, int lives);
		~Player();
		void SetX(float x);
		float GetX();
		void SetY(float y);
		float GetY();
		void SetWidth(float width);
		float GetWidth();
		void SetHeight(float height);
		float GetHeight();
		Rectangle rec;
		void SetInputs();
		void InitRectanglePlayer();
		void SetLives(int lives);
	};

}



#endif