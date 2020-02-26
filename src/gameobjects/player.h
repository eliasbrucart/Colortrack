#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player 
{
private:
	float _x;
	float _y;
	float width;
	float height;
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
	void InitRectangle();
	void SetLives();
};

#endif