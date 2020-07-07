#include "player.h"

#include "raylib.h"

#include "screens/game_loop.h"

namespace Colortrack
{

	Player::Player()
	{
		_x = 320.0f;
		_y = 240.0f;
		_width = 10.0f;
		_height = 10.0f;
		_speed = 500.0f;
		_lives = 1.0f;
	}

	Player::Player(float x, float y, float width, float height, float speed, int lives)
	{
		_x = x;
		_y = y;
		_width = width;
		_height = height;
		_speed = speed;
		_lives = lives;
	}

	Player::~Player()
	{

	}

	void Player::SetX(float x)
	{
		_x = x;
	}

	float Player::GetX()
	{
		return _x;
	}

	void Player::SetY(float y)
	{
		_y = y;
	}

	float Player::GetY()
	{
		return _y;
	}

	void Player::SetWidth(float width)
	{
		_width = width;
	}

	float Player::GetWidth()
	{
		return _width;
	}

	void Player::SetHeight(float height)
	{
		_height = height;
	}

	float Player::GetHeight()
	{
		return _height;
	}

	void Player::SetInputs()
	{
		if (IsKeyDown(KEY_A))
		{
			_x -= _speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_D))
		{
			_x += _speed * GetFrameTime();
		}
	}

	void Player::InitRectanglePlayer()
	{
		rec.x = _x;
		rec.y = _y;
		rec.width = _width;
		rec.height = _height;
	}

	void Player::SetLives(int lives)
	{
		_lives = lives;
	}

	void Player::CollisionWindow()
	{
		if (_x <= minScreenWidth) 
		{
			_x = minScreenWidth;
		}
		if (_x + _width >= GetScreenWidth())
		{
			_x = GetScreenWidth() - _width;
		}
	}
}

