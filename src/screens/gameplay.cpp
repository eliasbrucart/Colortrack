#include<iostream>
#include "raylib.h"
#include "easings.h"

#include "gameplay.h"
#include "game_loop.h"
#include "gameobjects/colors.h"
#include "credits.h"

#include "gameobjects/player.h"
#include "gameobjects/circle_enemy.h"
#include "gameobjects/rectangle_enemy.h"

using namespace std;

namespace Colortrack
{
	static int flag = 1;
	bool popUp = false;
	Gameplay::Gameplay()
	{
		Init();
	}

	Gameplay::~Gameplay()
	{
		if (_player != NULL)
		{
			delete _player;
			_player = NULL;
		}
		if (_rectangleEnemy != NULL)
		{
			delete _rectangleEnemy;
			_rectangleEnemy = NULL;
		}
		if (_rectangleEnemy2 != NULL)
		{
			delete _rectangleEnemy2;
			_rectangleEnemy2 = NULL;
		}
		if (_circleEnemy != NULL)
		{
			delete _circleEnemy;
			_circleEnemy = NULL;
		}
		UnloadTexture(_menuButtonSprite);
		UnloadTexture(_pauseButtonSprite);
		UnloadSound(_pointEarned);
		UnloadSound(_gameOver);
	}

	void Gameplay::Init()
	{
		_player = NULL;
		_rectangleEnemy = NULL;
		_rectangleEnemy2 = NULL;
		_circleEnemy = NULL;
		_player = new Player(320.0f, 340.0f, 20.0f, 20.0f, 300.0f, 1, false);
		_rectangleEnemy = new RectangleEnemy(0.0f, -100.0f, static_cast<float>(GetScreenWidth() / 2), 50.0f, { 150.0f, 150.0f }, false);
		_rectangleEnemy2 = new RectangleEnemy(static_cast<float>(GetScreenWidth() / 2), -100.0f, static_cast<float>(GetScreenWidth() / 2) - 0.5f, 50.0f, { 150.0f, 150.0f }, false);
		_circleEnemy = new CircleEnemy(300.0f, -100.0f, 20.0f, GREEN, false, { 200.0f, 150.0f }, false, false);
		_pauseRec.x = 600.0f;
		_pauseRec.y = 0.0f;
		_pauseRec.width = 40.0f;
		_pauseRec.height = 40.0f;
		_backToMenuRec.x = 280.0f;
		_backToMenuRec.y = 0.0f;
		_backToMenuRec.width = 100.0f;
		_backToMenuRec.height = 50.0f;
		_timePopUp = 0.0f;
		_timer = 240;
		_timeDeath = 240;
		_points = 0;
		_pause = false;
		_rotation = 0.0f;

		_menuButtonSprite = LoadTexture("assets/textures/menuButtonSprite.png");
		_pauseButtonSprite = LoadTexture("assets/textures/pauseButtonSprite.png");

		_pointEarned = LoadSound("assets/sounds/points.wav");
		_gameOver = LoadSound("assets/sounds/gameOver.wav");

		SetEnemiesColors();
		SetPlayerColors();

		if (CheckEnemiesColors() && CheckEnemiesPlayerColors())
		{
			SetEnemiesColors();
			SetPlayerColors();
		}
		SetTargetFPS(60);
	}

	void Gameplay::SetEnemiesColors()
	{
		int randomColorRectangleEnemy = GetRandomValue(1, 5);
		int randomColorRectangleEnemy2 = GetRandomValue(1, 5);
		int randomColorCircleEnemy = GetRandomValue(1, 5);

		if (_rectangleEnemy != NULL)
		{
			switch (randomColorRectangleEnemy)
			{
			case 1:
				_rectangleEnemy->SetRectangleEnemyColors(_rectangleEnemy->rectangleEnemyColors = Colors::colorGreen);
				break;
			case 2:
				_rectangleEnemy->SetRectangleEnemyColors(_rectangleEnemy->rectangleEnemyColors = Colors::colorRed);
				break;
			case 3:
				_rectangleEnemy->SetRectangleEnemyColors(_rectangleEnemy->rectangleEnemyColors = Colors::colorYellow);
				break;
			case 4:
				_rectangleEnemy->SetRectangleEnemyColors(_rectangleEnemy->rectangleEnemyColors = Colors::colorBlue);
				break;
			case 5:
				_rectangleEnemy->SetRectangleEnemyColors(_rectangleEnemy->rectangleEnemyColors = Colors::colorOrange);
				break;
			default:
				break;
			}
		}

		if (_circleEnemy != NULL)
		{
			switch (randomColorCircleEnemy)
			{
			case 1:
				_circleEnemy->SetCircleEnemyColors(_circleEnemy->circleEnemyColors = Colors::colorGreen);
				break;
			case 2:
				_circleEnemy->SetCircleEnemyColors(_circleEnemy->circleEnemyColors = Colors::colorRed);
				break;
			case 3:
				_circleEnemy->SetCircleEnemyColors(_circleEnemy->circleEnemyColors = Colors::colorYellow);
				break;
			case 4:
				_circleEnemy->SetCircleEnemyColors(_circleEnemy->circleEnemyColors = Colors::colorBlue);
				break;
			case 5:
				_circleEnemy->SetCircleEnemyColors(_circleEnemy->circleEnemyColors = Colors::colorOrange);
				break;
			default:
				break;
			}
		}

		if (_rectangleEnemy2 != NULL)
		{
			switch (randomColorRectangleEnemy2)
			{
			case 1:
				_rectangleEnemy2->SetRectangleEnemyColors(_rectangleEnemy2->rectangleEnemyColors = Colors::colorGreen);
				break;
			case 2:
				_rectangleEnemy2->SetRectangleEnemyColors(_rectangleEnemy2->rectangleEnemyColors = Colors::colorRed);
				break;
			case 3:
				_rectangleEnemy2->SetRectangleEnemyColors(_rectangleEnemy2->rectangleEnemyColors = Colors::colorYellow);
				break;
			case 4:
				_rectangleEnemy2->SetRectangleEnemyColors(_rectangleEnemy2->rectangleEnemyColors = Colors::colorBlue);
				break;
			case 5:
				_rectangleEnemy2->SetRectangleEnemyColors(_rectangleEnemy2->rectangleEnemyColors = Colors::colorOrange);
				break;
			default:
				break;
			}
		}
	}

	void Gameplay::SetPlayerColors()
	{
		Colors rectangleEnemyColor = _rectangleEnemy->GetColors();
		Colors rectangleEnemyColor2 = _rectangleEnemy2->GetColors();
		int rand = GetRandomValue(1, 2);
		if (_player != NULL)
		{
			switch (rand)
			{
			case 1:
				_player->SetPlayerColors(_player->playerColors = rectangleEnemyColor);
				break;
			case 2:
				_player->SetPlayerColors(_player->playerColors = rectangleEnemyColor2);
				break;
			}
		}
	}

	bool Gameplay::CheckEnemiesColors()
	{
		if (_rectangleEnemy != NULL && _rectangleEnemy2 != NULL && _circleEnemy != NULL)
		{
			if (_rectangleEnemy->GetColors() == _rectangleEnemy2->GetColors() && _rectangleEnemy->GetColors() == _circleEnemy->GetColors() && _rectangleEnemy2->GetColors() == _circleEnemy->GetColors())
				return true;
		}
		return false;
	}

	bool Gameplay::CheckEnemiesPlayerColors()
	{
		if (_player != NULL && _rectangleEnemy != NULL && _rectangleEnemy2 != NULL && _circleEnemy != NULL)
		{
			if (_player->GetColors() != _rectangleEnemy->GetColors() && _player->GetColors() != _rectangleEnemy2->GetColors() && _player->GetColors() != _circleEnemy->GetColors())
				return true;
		}
		return false;
	}

	void Gameplay::CollisionsGame()
	{
		_timePopUp += GetFrameTime();
		if (_player != NULL && _rectangleEnemy != NULL && _rectangleEnemy2 != NULL && _circleEnemy != NULL)
		{
			if (CheckCollisionRecs(_player->GetPlayerRec(), _rectangleEnemy->GetRectangleEnemyRec()))
			{
				if (_player->playerColors != _rectangleEnemy->rectangleEnemyColors && flag != 0)
				{
					_player->SetLives(0);
					PlaySound(_gameOver);
					flag = 0;
				}
				else if (flag != 0)
				{
					_points += 100;
					PlaySound(_pointEarned);
					flag = 0;
					popUp = true;
				}
				_timePopUp = 0.0f;
			}
			else if (CheckCollisionRecs(_player->GetPlayerRec(), _rectangleEnemy2->GetRectangleEnemyRec()))
			{
				if (_player->playerColors != _rectangleEnemy2->rectangleEnemyColors && flag != 0)
				{
					_player->SetLives(0);
					PlaySound(_gameOver);
					flag = 0;
				}
				else if (flag != 0)
				{
					_points += 100;
					PlaySound(_pointEarned);
					flag = 0;
					popUp = true;
				}
				_timePopUp = 0.0f;
			}
			else if (CheckCollisionCircleRec(_circleEnemy->GetPosition(), _circleEnemy->GetRadius(), _player->GetPlayerRec()))
			{
				if (_player->playerColors != _circleEnemy->circleEnemyColors && flag != 0)
				{
					_player->SetLives(0);
					PlaySound(_gameOver);
					flag = 0;
				}
				else if (flag != 0)
				{
					_points += 100;
					PlaySound(_pointEarned);
					flag = 0;
					popUp = true;
				}
				_timePopUp = 0.0f;
			}
			else
			{
				flag = 1;
			}
		}
	}

	void Gameplay::CheckPlayerAlive()
	{
		if (_player != NULL)
		{
			if (_player->IsDead())
			{
				if (_rectangleEnemy != NULL)
				{
					_rectangleEnemy->SetSpeedY(0.0f);
					_rectangleEnemy->SetSpeedX(0.0f);
				}
				if (_rectangleEnemy2 != NULL)
				{
					_rectangleEnemy2->SetSpeedY(0.0f);
					_rectangleEnemy2->SetSpeedX(0.0f);
				}
				if (_circleEnemy != NULL)
				{
					_circleEnemy->SetSpeedY(0.0f);
					_circleEnemy->SetSpeedX(0.0f);
				}
				_player->SetSpeed(0.0f);
				_rotation = 0.0f;
				_timeDeath--;
				if (_timeDeath <= 0)
					state = GameState::gameOverScreen;
			}
		}
	}

	void Gameplay::GenerateShapes()
	{
		int randomShape = GetRandomValue(1, 9);
		if (_rectangleEnemy != NULL && _rectangleEnemy2 != NULL && _circleEnemy != NULL)
		{
			switch (randomShape)
			{
			case 1:
				_rectangleEnemy->SetX(0.0f);
				_rectangleEnemy->SetY(-200.0f);
				_rectangleEnemy->SetWidth(320.0f);
				_rectangleEnemy->SetHeight(30.0f);
				_rectangleEnemy->SetChangedShape(true);
				_rectangleEnemy->SetActiveMovement(false);
				_rectangleEnemy->SetRotationEnemy(false);
				_rectangleEnemy2->SetWidth(320.0f);
				_rectangleEnemy2->SetX(321.0f);
				_rectangleEnemy2->SetY(-200.0f);
				_rectangleEnemy2->SetHeight(30.0f);
				_rectangleEnemy2->SetChangedShape(true);
				_rectangleEnemy2->SetActiveMovement(false);
				_rectangleEnemy2->SetRotationEnemy(false);
				_circleEnemy->SetRadius(20.0f);
				_circleEnemy->SetX(300.0f);
				_circleEnemy->SetY(-230);
				_circleEnemy->SetActiveMovementInX(false);
				_circleEnemy->SetActiveMovementInY(true);
				break;
			case 2:
				_rectangleEnemy->SetX(0.0f);
				_rectangleEnemy->SetY(-200.0f);
				_rectangleEnemy->SetWidth(150.0f);
				_rectangleEnemy->SetHeight(20.0f);
				_rectangleEnemy->SetChangedShape(true);
				_rectangleEnemy->SetActiveMovement(false);
				_rectangleEnemy->SetRotationEnemy(false);
				_rectangleEnemy2->SetX(151.0f);
				_rectangleEnemy2->SetY(-200.0f);
				_rectangleEnemy2->SetWidth(490.0f);
				_rectangleEnemy2->SetHeight(20.0f);
				_rectangleEnemy2->SetChangedShape(true);
				_rectangleEnemy2->SetActiveMovement(false);
				_rectangleEnemy2->SetRotationEnemy(false);
				_circleEnemy->SetY(-230.0f);
				_circleEnemy->SetActiveMovementInX(true);
				_circleEnemy->SetActiveMovementInY(true);
				break;
			case 3:
				_rectangleEnemy->SetX(0.0f);
				_rectangleEnemy->SetY(-200.0f);
				_rectangleEnemy->SetWidth(200.0f);
				_rectangleEnemy->SetHeight(50.0f);
				_rectangleEnemy->SetChangedShape(true);
				_rectangleEnemy->SetActiveMovement(false);
				_rectangleEnemy->SetRotationEnemy(false);
				_rectangleEnemy2->SetX(201.0f);
				_rectangleEnemy2->SetY(-200.0f);
				_rectangleEnemy2->SetWidth(440.0f);
				_rectangleEnemy2->SetHeight(50.0f);
				_rectangleEnemy2->SetChangedShape(true);
				_rectangleEnemy2->SetActiveMovement(false);
				_rectangleEnemy2->SetRotationEnemy(false);
				_circleEnemy->SetX(300.0f);
				_circleEnemy->SetY(-230.0f);
				_circleEnemy->SetActiveMovementInX(true);
				_circleEnemy->SetActiveMovementInY(true);
				break;
			case 4:
				_rectangleEnemy->SetX(0.0f);
				_rectangleEnemy->SetY(-200.0f);
				_rectangleEnemy->SetWidth(500.0f);
				_rectangleEnemy->SetHeight(70.0f);
				_rectangleEnemy->SetChangedShape(true);
				_rectangleEnemy->SetActiveMovement(false);
				_rectangleEnemy->SetRotationEnemy(false);
				_rectangleEnemy2->SetX(501.0f);
				_rectangleEnemy2->SetY(-200.0f);
				_rectangleEnemy2->SetWidth(140.0f);
				_rectangleEnemy2->SetHeight(70.0f);
				_rectangleEnemy2->SetChangedShape(true);
				_rectangleEnemy2->SetActiveMovement(false);
				_rectangleEnemy2->SetRotationEnemy(false);
				_circleEnemy->SetY(-230.0f);
				_circleEnemy->SetRadius(40.0f);
				_circleEnemy->SetActiveMovementInX(true);
				_circleEnemy->SetActiveMovementInY(true);
				break;
			case 5:
				_rectangleEnemy->SetX(0.0f);
				_rectangleEnemy->SetY(-200.0f);
				_rectangleEnemy->SetWidth(90.0f);
				_rectangleEnemy->SetHeight(45.0f);
				_rectangleEnemy->SetChangedShape(true);
				_rectangleEnemy->SetActiveMovement(false);
				_rectangleEnemy->SetRotationEnemy(false);
				_rectangleEnemy2->SetX(91.0f);
				_rectangleEnemy2->SetY(-200.0f);
				_rectangleEnemy2->SetWidth(550.0f);
				_rectangleEnemy2->SetHeight(45.0f);
				_rectangleEnemy2->SetChangedShape(true);
				_rectangleEnemy2->SetActiveMovement(false);
				_rectangleEnemy2->SetRotationEnemy(false);
				_circleEnemy->SetX(300.0f);
				_circleEnemy->SetY(-230.0f);
				_circleEnemy->SetActiveMovementInX(true);
				_circleEnemy->SetActiveMovementInY(true);
				break;
			case 6:
				_rectangleEnemy->SetX(0.0f);
				_rectangleEnemy->SetY(-400.0f);
				_rectangleEnemy->SetWidth(200.0f);
				_rectangleEnemy->SetHeight(300.0f);
				_rectangleEnemy->SetChangedShape(true);
				_rectangleEnemy->SetActiveMovement(false);
				_rectangleEnemy->SetRotationEnemy(false);
				_rectangleEnemy2->SetX(440.0f);
				_rectangleEnemy2->SetY(-400.0f);
				_rectangleEnemy2->SetWidth(200.0f);
				_rectangleEnemy2->SetHeight(300.0f);
				_rectangleEnemy2->SetChangedShape(true);
				_rectangleEnemy2->SetActiveMovement(false);
				_rectangleEnemy2->SetRotationEnemy(false);
				_circleEnemy->SetY(-230.0f);
				_circleEnemy->SetRadius(20.0f);
				_circleEnemy->SetActiveMovementInX(true);
				_circleEnemy->SetActiveMovementInY(true);
				break;
			case 7:
				_rectangleEnemy->SetX(50.0f);
				_rectangleEnemy->SetY(-200.0f);
				_rectangleEnemy->SetWidth(200.0f);
				_rectangleEnemy->SetHeight(50.0f);
				_rectangleEnemy->SetChangedShape(true);
				_rectangleEnemy->SetActiveMovement(true);
				_rectangleEnemy->SetRotationEnemy(false);
				_rectangleEnemy2->SetX(100.0f);
				_rectangleEnemy2->SetY(-100.0f);
				_rectangleEnemy2->SetWidth(200.0f);
				_rectangleEnemy2->SetHeight(50.0f);
				_rectangleEnemy2->SetChangedShape(true);
				_rectangleEnemy2->SetActiveMovement(true);
				_rectangleEnemy2->SetRotationEnemy(false);
				_circleEnemy->SetX(300.0f);
				_circleEnemy->SetY(-230.0f);
				_circleEnemy->SetActiveMovementInX(true);
				_circleEnemy->SetActiveMovementInY(true);
				break;
			case 8:
				_rectangleEnemy->SetX(100.0f);
				_rectangleEnemy->SetY(-200.0f);
				_rectangleEnemy->SetWidth(200.0f);
				_rectangleEnemy->SetHeight(50.0f);
				_rectangleEnemy->SetChangedShape(true);
				_rectangleEnemy->SetActiveMovement(false);
				_rectangleEnemy->SetRotationEnemy(true);
				_rectangleEnemy2->SetX(400.0f);
				_rectangleEnemy2->SetY(-200.0f);
				_rectangleEnemy2->SetWidth(200.0f);
				_rectangleEnemy2->SetHeight(50.0f);
				_rectangleEnemy2->SetChangedShape(true);
				_rectangleEnemy2->SetActiveMovement(true);
				_rectangleEnemy2->SetRotationEnemy(false);
				_circleEnemy->SetX(300.0f);
				_circleEnemy->SetY(-230.0f);
				_circleEnemy->SetActiveMovementInX(true);
				_circleEnemy->SetActiveMovementInY(true);
				break;
			case 9:
				_rectangleEnemy->SetX(100.0f);
				_rectangleEnemy->SetY(-200.0f);
				_rectangleEnemy->SetWidth(200.0f);
				_rectangleEnemy->SetHeight(50.0f);
				_rectangleEnemy->SetChangedShape(true);
				_rectangleEnemy->SetActiveMovement(true);
				_rectangleEnemy->SetRotationEnemy(false);
				_rectangleEnemy2->SetX(400.0f);
				_rectangleEnemy2->SetY(-200.0f);
				_rectangleEnemy2->SetWidth(200.0f);
				_rectangleEnemy2->SetHeight(50.0f);
				_rectangleEnemy2->SetChangedShape(true);
				_rectangleEnemy2->SetActiveMovement(true);
				_rectangleEnemy2->SetRotationEnemy(false);
				_circleEnemy->SetY(-230.0f);
				_circleEnemy->SetRadius(20.0f);
				_circleEnemy->SetActiveMovementInX(true);
				_circleEnemy->SetActiveMovementInY(true);
			default:
				break;
			}
		}
	}

	void Gameplay::SetPause()
	{
		if (IsKeyPressed(KEY_P))
		{
			_pause = !_pause;
		}
		if (CheckCollisionPointRec(_mouse, _pauseRec))
		{
			_mouseHoverInButton = pauseButtonHover;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				_pause = !_pause;
		}
		else
			_mouseHoverInButton = noHover;
	}

	int Gameplay::GetPoints()
	{
		return _points;
	}

	void Gameplay::IncreaseEnemySpeed()
	{
		if (_rectangleEnemy != NULL && _rectangleEnemy2 != NULL && _circleEnemy != NULL)
		{
			if (_points == 1000)
			{
				_rectangleEnemy->SetSpeedY(170.0f);
				_rectangleEnemy2->SetSpeedY(170.0f);
				_circleEnemy->SetSpeedY(170.0f);
			}
			if (_points == 2000)
			{
				_rectangleEnemy->SetSpeedY(190.0f);
				_rectangleEnemy2->SetSpeedY(190.0f);
				_circleEnemy->SetSpeedY(190.0f);
			}
			if (_points == 3000)
			{
				_rectangleEnemy->SetSpeedY(210.0f);
				_rectangleEnemy2->SetSpeedY(210.0f);
				_circleEnemy->SetSpeedY(210.0f);
				_player->SetSpeed(350.0f);
			}
			if (_points == 3500)
			{
				_rectangleEnemy->SetSpeedY(230.0f);
				_rectangleEnemy2->SetSpeedY(230.0f);
				_circleEnemy->SetSpeedY(230.0f);
			}
		}
	}

	void Gameplay::PopUp()
	{
		if (_player != NULL)
		{
			if (popUp)
			{
				if (_timePopUp != 0.0f)
					if (_timePopUp < 2.0f)
						DrawText("+100!", _player->GetX(), _player->GetY() - 25, 25, WHITE);
				if (_timePopUp > 2.0f)
					popUp = false;
			}
		}
	}

	void Gameplay::ActivateRotationEnemy()
	{
		if (_rectangleEnemy->GetRotationEnemy())
			_rotation++;
		else
			_rotation = 0;
	}

	void Gameplay::BackToMenuInput()
	{
		if (CheckCollisionPointRec(_mouse, _backToMenuRec))
		{
			_mouseHoverInButton = menuButtonHover;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				state = GameState::mainmenu;
		}
		else
			_mouseHoverInButton = noHover;
	}

	void Gameplay::Update()
	{
		_timer--;
		if (_timer <= 0)
		{
			if (_pause == false)
			{
				_mouse = GetMousePosition();
				if (_player != NULL)
				{
					_player->SetInputs();
					_player->CollisionWindow();
				}
				if (_rectangleEnemy != NULL)
				{
					_rectangleEnemy->MoveRectangleEnemy();
					_rectangleEnemy->RectangleEnemyOutOfScreen();
				}
				if (_rectangleEnemy2 != NULL)
				{
					_rectangleEnemy2->MoveRectangleEnemy();
					_rectangleEnemy2->RectangleEnemyOutOfScreen();
				}
				if (_circleEnemy != NULL)
				{
					_circleEnemy->MoveCircleEnemy();
					_circleEnemy->CircleEnemyOutOfScreen();
				}
				CollisionsGame();
				CheckPlayerAlive();
				SetPause();
				IncreaseEnemySpeed();
				PopUp();
				ActivateRotationEnemy();
				BackToMenuInput();
				if (_rectangleEnemy->GetOutOfScreen() == true && _rectangleEnemy2->GetOutOfScreen() == true)
				{
					if (!_rectangleEnemy->GetChangedShape() && !_rectangleEnemy2->GetChangedShape())
					{
						GenerateShapes();
						SetEnemiesColors();
						SetPlayerColors();
						if (CheckEnemiesColors() && CheckEnemiesPlayerColors())
						{
							SetEnemiesColors();
							SetPlayerColors();
						}
					}
				}
			}
			else
			{
				if (IsKeyPressed(KEY_P) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
					_pause = !_pause;
			}
		}
	}

	void Gameplay::Draw()
	{
		DrawRectangleRec(_player->GetPlayerRec(), _player->GetColor());
		if (_rectangleEnemy->GetRotationEnemy())
			DrawRectanglePro(_rectangleEnemy->GetRectangleEnemyRec(), { _rectangleEnemy->GetX() + _rectangleEnemy->GetWidth() / 2, _rectangleEnemy->GetHeight() / 2 }, _rotation, _rectangleEnemy->GetColor());
		else 
			DrawRectangleRec(_rectangleEnemy->GetRectangleEnemyRec(), _rectangleEnemy->GetColor());
		DrawRectangleRec(_rectangleEnemy2->GetRectangleEnemyRec(), _rectangleEnemy2->GetColor());
		DrawCircle(static_cast<int>(_circleEnemy->GetX()), static_cast<int>(_circleEnemy->GetY()), _circleEnemy->GetRadius(), _circleEnemy->GetColor());
		DrawText(TextFormat("Points: %i", _points), 2, 2, 20, WHITE);
		if (_player->IsDead())
		{
			DrawText("Game Over!", GetScreenWidth() / 2 - 120, GetScreenHeight() / 2, 50, WHITE);
		}
		if (_pause == true)
			DrawText("PAUSE", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2, 70, WHITE);
		DrawTexture(_menuButtonSprite, _backToMenuRec.x, _backToMenuRec.y, WHITE);
		DrawTexture(_pauseButtonSprite, _pauseRec.x, _pauseRec.y, WHITE);
		switch (_mouseHoverInButton)
		{
		case menuButtonHover:
			DrawTexture(_menuButtonSprite, _backToMenuRec.x, _backToMenuRec.y, LIME);
			break;
		case pauseButtonHover:
			DrawTexture(_pauseButtonSprite, _pauseRec.x, _pauseRec.y, GRAY);
			break;
		case noHover:
			break;
		default:
			break;
		}
		if (_timer >= 0)
		{
			DrawText(TextFormat("Start in: %i", _timer / 60), GetScreenWidth() / 2 - 120, GetScreenHeight() / 2 - 30, 50, WHITE);
		}
	}

	void Gameplay::Unload()
	{
		_timePopUp = 0.0f;
		_points = 0;
		_rotation = 0.0f;
	}
}