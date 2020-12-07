#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "colors.h"

namespace Colortrack
{
	class Player
	{
	private:
		Rectangle _rec;
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
		Rectangle GetPlayerRec();
		void SetWidth(float width);
		float GetWidth();
		void SetHeight(float height);
		float GetHeight();
		void SetSpeed(float speed);
		float GetSpeed();
		Color GetColor();
		Colors GetColors();
		void SetInputs();
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