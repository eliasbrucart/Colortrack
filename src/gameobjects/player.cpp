#include "player.h"

#include "raylib.h"

#include "screens/game_loop.h"

namespace Colortrack
{

	Player::Player()
	{
		_x = 1.0f;
		_y = 1.0f;
		_width = 10.0f;
		_height = 10.0f;
		_speed = 100.0f;
		_lives = 1;
		_color = WHITE;
		playerColors = PlayerColors::playerGreen;
	}

	Player::Player(float x, float y, float width, float height, float speed, int lives)
	{
		_x = x;
		_y = y;
		_width = width;
		_height = height;
		_speed = speed;
		_lives = lives;
		playerColors = PlayerColors::playerGreen;
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

	void Player::SetColor(PlayerColors color)
	{
		playerColors = color;
		SetPlayerColors(color);
	}

	Color Player::GetColor()
	{
		return _color;
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
			_x = static_cast<float>(minScreenWidth);
		}
		if (_x + _width >= GetScreenWidth())
		{
			_x = static_cast<float>(GetScreenWidth()) - _width;
		}
	}

	void Player::SetPlayerColors(PlayerColors color)
	{
		switch (color)
		{
		case playerGreen:
			_color = GREEN;
			break;
		case playerRed:
			_color = RED;
			break;
		case playerYellow:
			_color = YELLOW;
			break;
		case playerBlue:
			_color = BLUE;
			break;
		case playerOrange:
			_color = ORANGE;
			break;
		}
	}
}