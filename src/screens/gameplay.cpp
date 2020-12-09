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

	static const float playerX = 320.0f;
	static const float playerY = 340.0f;
	static const float playerWidth = 20.0f;
	static const float playerHeight = 20.0f;
	static const float playerSpeed = 300.0f;
	static const int playerLives = 1;

	static const float rectangleWidth = 320.0f;
	static const float rectangleHeight = 50.0f;

	static const float rectangle1X = 320.0f;
	static const float rectangleY = -100.0f;

	static const float rectangle2X = 0.0f;
	static const float rectangle2Width = 319.5f;

	static const float circleX = 300.0f;
	static const float circleY = -100.0f;
	static const float circleRadius = 20.0f;

	static const int pointsX = 2;
	static const int pointsY = 2;
	static const int pointsFontSize = 20;

	static const int gameOverTextX = 220;
	static const int gameOverTextY = 240;
	static const int gameOverTextFontSize = 50;

	static const int pauseTextX = 220;
	static const int pauseTextY = 240;
	static const int pauseTextFontSize = 70;

	static const int startTextX = 200;
	static const int startTextY = 210;
	static const int startTextFontSize = 50;

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
		UnloadTexture(_muteAudioSprite);
		UnloadTexture(_unMuteAudioSprite);
		UnloadSound(_pointEarned);
		UnloadSound(_gameOver);
		Unload();
	}

	void Gameplay::Init()
	{
		_player = NULL;
		_rectangleEnemy = NULL;
		_rectangleEnemy2 = NULL;
		_circleEnemy = NULL;
		_player = new Player(playerX, playerY, playerWidth, playerHeight, playerSpeed, playerLives, false, GREEN);
		_rectangleEnemy = new RectangleEnemy(rectangle1X, rectangleY, rectangleWidth, rectangleHeight, { 150.0f, 150.0f }, GREEN, true, true, false, false);
		_rectangleEnemy2 = new RectangleEnemy(rectangle2X, rectangleY, rectangle2Width, rectangleHeight, { 150.0f, 150.0f }, GREEN, true, true,false, false);
		_circleEnemy = new CircleEnemy(circleX, circleY, circleRadius, GREEN, { 200.0f, 150.0f }, false, false);
		_pauseRec.x = 600.0f;
		_pauseRec.y = 0.0f;
		_pauseRec.width = 40.0f;
		_pauseRec.height = 40.0f;
		_backToMenuRec.x = 280.0f;
		_backToMenuRec.y = 0.0f;
		_backToMenuRec.width = 100.0f;
		_backToMenuRec.height = 50.0f;
		_muteAudio.x = 500.0f;
		_muteAudio.y = 0.0f;
		_muteAudio.width = 40.0f;
		_muteAudio.height = 40.0f;
		_timePopUp = 0.0f;
		_timer = 240;
		_timeDeath = 240;
		_points = 0;
		_pause = false;
		_rotation = 0.0f;
		_muted = false;

		_menuButtonSprite = LoadTexture("res/assets/textures/menuButtonSprite.png");
		_pauseButtonSprite = LoadTexture("res/assets/textures/pauseButtonSprite.png");
		_muteAudioSprite = LoadTexture("res/assets/textures/audioSprite1.png");
		_unMuteAudioSprite = LoadTexture("res/assets/textures/audioSprite2.png");

		_pointEarned = LoadSound("res/assets/sounds/points.wav");
		_gameOver = LoadSound("res/assets/sounds/gameOver.wav");

		SetEnemiesColors();
		SetPlayerColors();

		CheckColorValidation();

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
			if (_points == 4500)
			{
				_rectangleEnemy->SetSpeedY(250.0f);
				_rectangleEnemy2->SetSpeedY(250.0f);
				_circleEnemy->SetSpeedY(250.0f);
			}
		}
	}

	void Gameplay::PopUp()
	{
		float textPopUpX = _player->GetX();
		float textPopUpY = _player->GetY() - 25;
		int textPopUpFontSize = 25;
		if (_player != NULL)
		{
			if (popUp)
			{
				if (_timePopUp != 0.0f)
					if (_timePopUp < 2.0f)
						DrawText("+100!", static_cast<int>(textPopUpX), static_cast<int>(textPopUpY), textPopUpFontSize, WHITE);
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

	void Gameplay::MuteAudio()
	{
		if (CheckCollisionPointRec(_mouse, _muteAudio))
		{
			_mouseHoverInButton = muteButtonHover;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) )
			{
				_muted = !_muted;
				if (!_muted)
					SetMasterVolume(0);
				else
					SetMasterVolume(1);
			}
		}
		else
			_mouseHoverInButton = noHover;
	}

	void Gameplay::CheckColorValidation()
	{
		if (CheckEnemiesColors() && CheckEnemiesPlayerColors())
		{
			SetEnemiesColors();
			SetPlayerColors();
		}
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
				MuteAudio();
				if (_rectangleEnemy->GetOutOfScreen() == true && _rectangleEnemy2->GetOutOfScreen() == true)
				{
					if (!_rectangleEnemy->GetChangedShape() && !_rectangleEnemy2->GetChangedShape())
					{
						GenerateShapes();
						SetEnemiesColors();
						SetPlayerColors();
						CheckColorValidation();
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
		float rectangleOriginX = _rectangleEnemy->GetX() + _rectangleEnemy->GetWidth() / 2;
		float rectangleOriginY = _rectangleEnemy->GetHeight() / 2;
		DrawRectangleRec(_player->GetPlayerRec(), _player->GetColor());
		if (_rectangleEnemy->GetRotationEnemy())
			DrawRectanglePro(_rectangleEnemy->GetRectangleEnemyRec(), { rectangleOriginX, rectangleOriginY }, _rotation, _rectangleEnemy->GetColor());
		else 
			DrawRectangleRec(_rectangleEnemy->GetRectangleEnemyRec(), _rectangleEnemy->GetColor());
		DrawRectangleRec(_rectangleEnemy2->GetRectangleEnemyRec(), _rectangleEnemy2->GetColor());
		DrawCircle(static_cast<int>(_circleEnemy->GetX()), static_cast<int>(_circleEnemy->GetY()), _circleEnemy->GetRadius(), _circleEnemy->GetColor());
		DrawText(TextFormat("Points: %i", _points), pointsX, pointsY, pointsFontSize, WHITE);
		if (_player->IsDead())
			DrawText("Game Over!", gameOverTextX, gameOverTextY, gameOverTextFontSize, WHITE);
		if (_pause == true)
			DrawText("PAUSE", pauseTextX, pauseTextY, pauseTextFontSize, WHITE);
		DrawTexture(_menuButtonSprite, static_cast<int>(_backToMenuRec.x), static_cast<int>(_backToMenuRec.y), WHITE);
		DrawTexture(_pauseButtonSprite, static_cast<int>(_pauseRec.x), static_cast<int>(_pauseRec.y), WHITE);
		if(!_muted)
			DrawTexture(_unMuteAudioSprite, static_cast<int>(_muteAudio.x), static_cast<int>(_muteAudio.y), WHITE);
		else
			DrawTexture(_muteAudioSprite, static_cast<int>(_muteAudio.x), static_cast<int>(_muteAudio.y), WHITE);
		switch (_mouseHoverInButton)
		{
		case menuButtonHover:
			DrawTexture(_menuButtonSprite, static_cast<int>(_backToMenuRec.x), static_cast<int>(_backToMenuRec.y), LIME);
			break;
		case pauseButtonHover:
			DrawTexture(_pauseButtonSprite, static_cast<int>(_pauseRec.x), static_cast<int>(_pauseRec.y), GRAY);
			break;
		case muteButtonHover:
			if(!_muted)
				DrawTexture(_unMuteAudioSprite, static_cast<int>(_muteAudio.x), static_cast<int>(_muteAudio.y), GRAY);
			else
				DrawTexture(_muteAudioSprite, static_cast<int>(_muteAudio.x), static_cast<int>(_muteAudio.y), GRAY);
			break;
		case noHover:
			break;
		default:
			break;
		}
		if (_timer >= 0)
		{
			DrawText(TextFormat("Start in: %i", _timer / 60), startTextX, startTextY, startTextFontSize, WHITE);
		}
	}

	void Gameplay::Unload()
	{
		_timePopUp = 0.0f;
		_points = 0;
		_rotation = 0.0f;
	}
}