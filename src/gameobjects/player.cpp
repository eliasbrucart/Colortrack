#include "player.h"

#include "raylib.h"

#include "screens/game_loop.h"

namespace Colortrack
{

	Player::Player()
	{
		_rec.x = 1.0f;
		_rec.y = 1.0f;
		_rec.width = 10.0f;
		_rec.height = 10.0f;
		_speed = 100.0f;
		_lives = 1;
		_color = WHITE;
		_dead = false;
		playerColors = Colors::colorGreen;
	}

	Player::Player(float x, float y, float width, float height, float speed, int lives, bool dead)
	{
		_rec.x = x;
		_rec.y = y;
		_rec.width = width;
		_rec.height = height;
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
		_rec.x = x;
	}

	float Player::GetX()
	{
		return _rec.x;
	}

	void Player::SetY(float y)
	{
		_rec.y = y;
	}

	float Player::GetY()
	{
		return _rec.y;
	}

	Rectangle Player::GetPlayerRec()
	{
		return _rec;
	}

	void Player::SetWidth(float width)
	{
		_rec.width = width;
	}

	float Player::GetWidth()
	{
		return _rec.width;
	}

	void Player::SetHeight(float height)
	{
		_rec.height = height;
	}

	float Player::GetHeight()
	{
		return _rec.height;
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
			_rec.x -= _speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_D))
		{
			_rec.x += _speed * GetFrameTime();
		}
	}

	/*void Player::InitRectanglePlayer()
	{
		rec.x = _x;
		rec.y = _y;
		rec.width = _width;
		rec.height = rec.height;
	}*/

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
			_dead = true;
			return true;
		}
		_dead = false;
		return false;
	}

	void Player::CollisionWindow()
	{
		if (_rec.x <= minScreenWidth)
		{
			_rec.x = static_cast<float>(minScreenWidth);
		}
		if (_rec.x + _rec.width >= GetScreenWidth())
		{
			_rec.x = static_cast<float>(GetScreenWidth()) - _rec.width;
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