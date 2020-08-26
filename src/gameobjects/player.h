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
		Color _color;
	public:
		Player();
		Player(float x, float y, float width, float height, float speed, int lives, Color color);
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
		Rectangle rec;
		void SetInputs();
		void InitRectanglePlayer();
		void SetLives(int lives);
		void CollisionWindow();
		enum PlayerColors
		{
			playerGreen,
			playerRed,
			playerYellow,
			playerBlue,
			playerOrange
		};
		PlayerColors playerColors;
		void SetColor(PlayerColors color);
		void SetPlayerColors(PlayerColors color);
	};

}



#endif