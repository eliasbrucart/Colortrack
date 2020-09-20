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
		playerColors = Colors::colorGreen;
	}

	Player::Player(float x, float y, float width, float height, float speed, int lives, bool dead)
	{
		_x = x;
		_y = y;
		_width = width;
		_height = height;
		_speed = speed;
		_lives = lives;
		_dead = dead;
		playerColors = Colors::colorGreen;
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

	void Player::SetColor(Colors color)
	{
		playerColors = color;
		SetPlayerColors(color);
	}

	Color Player::GetColor()
	{
		return _color;
	}

	Colors Player::GetColors()
	{
		return playerColors;
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

	int Player::GetLives() 
	{
		return _lives;
	}

	bool Player::IsDead()
	{
		if (_lives == 0)
		{
			return _dead = true;
		}
		return _dead = false;
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

	void Player::SetPlayerColors(Colors color)
	{
		switch (color)
		{
		case colorGreen:
			_color = GREEN;
			break;
		case colorRed:
			_color = RED;
			break;
		case colorYellow:
			_color = YELLOW;
			break;
		case colorBlue:
			_color = BLUE;
			break;
		case colorOrange:
			_color = ORANGE;
			break;
		}
	}
}