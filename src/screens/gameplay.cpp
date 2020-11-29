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
		if (player != NULL)
		{
			delete player;
			player = NULL;
		}
		if (rectangleEnemy != NULL)
		{
			delete rectangleEnemy;
			rectangleEnemy = NULL;
		}
		if (rectangleEnemy2 != NULL)
		{
			delete rectangleEnemy2;
			rectangleEnemy2 = NULL;
		}
		if (circleEnemy != NULL)
		{
			delete circleEnemy;
			circleEnemy = NULL;
		}
	}

	void Gameplay::Init()
	{
		SetTargetFPS(60);
		player = NULL;
		rectangleEnemy = NULL;
		rectangleEnemy2 = NULL;
		circleEnemy = NULL;
		player = new Player(320.0f, 340.0f, 20.0f, 20.0f, 300.0f, 1, false);
		rectangleEnemy = new RectangleEnemy(0.0f, -100.0f, static_cast<float>(GetScreenWidth() / 2), 50.0f, {150.0f, 150.0f}, false);
		rectangleEnemy2 = new RectangleEnemy(static_cast<float>(GetScreenWidth() / 2), -100.0f, static_cast<float>(GetScreenWidth() / 2) - 0.5f, 50.0f, { 150.0f, 150.0f }, false);
		circleEnemy = new CircleEnemy(300.0f, -100.0f, 20.0f, GREEN);
		_pauseRec.x = 610.0f;
		_pauseRec.y = 2.0f;
		_pauseRec.width = 30.0f;
		_pauseRec.height = 30.0f;
		_time = 0.0f;
		_points = 0;
		_pause = false;
		_rotation = 0.0f;

		SetEnemiesColors();
		SetPlayerColors();

		if (CheckEnemiesColors() && CheckEnemiesPlayerColors())
		{
			SetEnemiesColors();
			SetPlayerColors();
		}
	}

	void Gameplay::SetEnemiesColors()
	{
		int randomColorRectangleEnemy = GetRandomValue(1, 5);
		int randomColorRectangleEnemy2 = GetRandomValue(1, 5);
		int randomColorCircleEnemy = GetRandomValue(1, 5);

		switch (randomColorRectangleEnemy)
		{
		case 1:
			rectangleEnemy->SetRectangleEnemyColors(rectangleEnemy->rectangleEnemyColors = Colors::colorGreen);
			break;
		case 2:
			rectangleEnemy->SetRectangleEnemyColors(rectangleEnemy->rectangleEnemyColors = Colors::colorRed);
			break;
		case 3:
			rectangleEnemy->SetRectangleEnemyColors(rectangleEnemy->rectangleEnemyColors = Colors::colorYellow);
			break;
		case 4:
			rectangleEnemy->SetRectangleEnemyColors(rectangleEnemy->rectangleEnemyColors = Colors::colorBlue);
			break;
		case 5:
			rectangleEnemy->SetRectangleEnemyColors(rectangleEnemy->rectangleEnemyColors = Colors::colorOrange);
			break;
		default:
			break;
		}

		switch (randomColorCircleEnemy)
		{
		case 1:
			circleEnemy->SetCircleEnemyColors(circleEnemy->circleEnemyColors = Colors::colorGreen);
			break;
		case 2:
			circleEnemy->SetCircleEnemyColors(circleEnemy->circleEnemyColors = Colors::colorRed);
			break;
		case 3:
			circleEnemy->SetCircleEnemyColors(circleEnemy->circleEnemyColors = Colors::colorYellow);
			break;
		case 4:
			circleEnemy->SetCircleEnemyColors(circleEnemy->circleEnemyColors = Colors::colorBlue);
			break;
		case 5:
			circleEnemy->SetCircleEnemyColors(circleEnemy->circleEnemyColors = Colors::colorOrange);
			break;
		default:
			break;
		}

		switch (randomColorRectangleEnemy2)
		{
		case 1:
			rectangleEnemy2->SetRectangleEnemyColors(rectangleEnemy2->rectangleEnemyColors = Colors::colorGreen);
			break;
		case 2:
			rectangleEnemy2->SetRectangleEnemyColors(rectangleEnemy2->rectangleEnemyColors = Colors::colorRed);
			break;
		case 3:
			rectangleEnemy2->SetRectangleEnemyColors(rectangleEnemy2->rectangleEnemyColors = Colors::colorYellow);
			break;
		case 4:
			rectangleEnemy2->SetRectangleEnemyColors(rectangleEnemy2->rectangleEnemyColors = Colors::colorBlue);
			break;
		case 5:
			rectangleEnemy2->SetRectangleEnemyColors(rectangleEnemy2->rectangleEnemyColors = Colors::colorOrange);
			break;
		default:
			break;
		}
	}

	void Gameplay::SetPlayerColors()
	{
		Colors rectangleEnemyColor = rectangleEnemy->GetColors();
		Colors rectangleEnemyColor2 = rectangleEnemy2->GetColors();
		//Colors circleEnemyColor = circleEnemy->GetColors();
		int rand = GetRandomValue(1, 2);
		switch (rand)
		{
		case 1:
			player->SetPlayerColors(player->playerColors = rectangleEnemyColor);
			break;
		case 2:
			player->SetPlayerColors(player->playerColors = rectangleEnemyColor2);
			break;
		}
	}

	bool Gameplay::CheckEnemiesColors() 
	{
		if (rectangleEnemy->GetColors() == rectangleEnemy2->GetColors() && rectangleEnemy->GetColors() == circleEnemy->GetColors() && rectangleEnemy2->GetColors() == circleEnemy->GetColors())
			return true;
		return false;
	}

	bool Gameplay::CheckEnemiesPlayerColors()
	{
		if (player->GetColors() != rectangleEnemy->GetColors() && player->GetColors() != rectangleEnemy2->GetColors() && player->GetColors() != circleEnemy->GetColors())
			return true;
		return false;
	}

	void Gameplay::CollisionsGame()
	{
		_time += GetFrameTime();
		if (CheckCollisionRecs(player->GetPlayerRec(), rectangleEnemy->GetRectangleEnemyRec()))
		{
			if (player->playerColors != rectangleEnemy->rectangleEnemyColors)
			{
				player->SetLives(0);
			}
			else if (flag != 0)
			{
				_points += 100;
				flag = 0;
				popUp = true;
			}
			_time = 0.0f;
		}
		else if (CheckCollisionRecs(player->GetPlayerRec(), rectangleEnemy2->GetRectangleEnemyRec()))
		{
			if (player->playerColors != rectangleEnemy2->rectangleEnemyColors)
			{
				player->SetLives(0);
			}
			else if (flag != 0)
			{
				_points += 100;
				flag = 0;
				popUp = true;
			}
			_time = 0.0f;
		}
		else if (CheckCollisionCircleRec(circleEnemy->GetPosition(), circleEnemy->GetRadius(), player->GetPlayerRec()))
		{
			if (player->playerColors != circleEnemy->circleEnemyColors)
			{
				player->SetLives(0);
			}
			else if (flag != 0)
			{
				_points += 100;
				flag = 0;
				popUp = true;
			}
			_time = 0.0f;
		}
		else
		{
			flag = 1;
		}
	}

	void Gameplay::CheckPlayerAlive()
	{
		if (player->IsDead())
		{
			state = GameState::creditsScreen;
		}
	}

	void Gameplay::GenerateShapes()
	{
		int randomShape = GetRandomValue(1, 8);
		switch (randomShape)
		{
		case 1:
			rectangleEnemy->SetX(0.0f);
			rectangleEnemy->SetY(-200.0f);
			rectangleEnemy->SetWidth(320.0f);
			rectangleEnemy->SetHeight(30.0f);
			rectangleEnemy->SetChangedShape(true);
			rectangleEnemy->SetActiveMovement(false);
			rectangleEnemy->SetRotationEnemy(false);
			rectangleEnemy2->SetWidth(320.0f);
			rectangleEnemy2->SetX(321.0f);
			rectangleEnemy2->SetY(-200.0f);
			rectangleEnemy2->SetHeight(30.0f);
			rectangleEnemy2->SetChangedShape(true);
			rectangleEnemy2->SetActiveMovement(false);
			rectangleEnemy2->SetRotationEnemy(false);
			break;
		case 2:
			rectangleEnemy->SetX(0.0f);
			rectangleEnemy->SetY(-200.0f);
			rectangleEnemy->SetWidth(150.0f);
			rectangleEnemy->SetHeight(20.0f);
			rectangleEnemy->SetChangedShape(true);
			rectangleEnemy->SetActiveMovement(false);
			rectangleEnemy->SetRotationEnemy(false);
			rectangleEnemy2->SetX(151.0f);
			rectangleEnemy2->SetY(-200.0f);
			rectangleEnemy2->SetWidth(490.0f);
			rectangleEnemy2->SetHeight(20.0f);
			rectangleEnemy2->SetChangedShape(true);
			rectangleEnemy2->SetActiveMovement(false);
			rectangleEnemy2->SetRotationEnemy(false);
			break;
		case 3:
			rectangleEnemy->SetX(0.0f);
			rectangleEnemy->SetY(-200.0f);
			rectangleEnemy->SetWidth(200.0f);
			rectangleEnemy->SetHeight(50.0f);
			rectangleEnemy->SetChangedShape(true);
			rectangleEnemy->SetActiveMovement(false);
			rectangleEnemy->SetRotationEnemy(false);
			rectangleEnemy2->SetX(201.0f);
			rectangleEnemy2->SetY(-200.0f);
			rectangleEnemy2->SetWidth(440.0f);
			rectangleEnemy2->SetHeight(50.0f);
			rectangleEnemy2->SetChangedShape(true);
			rectangleEnemy2->SetActiveMovement(false);
			rectangleEnemy2->SetRotationEnemy(false);
			break;
		case 4:
			rectangleEnemy->SetX(0.0f);
			rectangleEnemy->SetY(-200.0f);
			rectangleEnemy->SetWidth(500.0f);
			rectangleEnemy->SetHeight(70.0f);
			rectangleEnemy->SetChangedShape(true);
			rectangleEnemy->SetActiveMovement(false);
			rectangleEnemy->SetRotationEnemy(false);
			rectangleEnemy2->SetX(501.0f);
			rectangleEnemy2->SetY(-200.0f);
			rectangleEnemy2->SetWidth(140.0f);
			rectangleEnemy2->SetHeight(70.0f);
			rectangleEnemy2->SetChangedShape(true);
			rectangleEnemy2->SetActiveMovement(false);
			rectangleEnemy2->SetRotationEnemy(false);
			break;
		case 5:
			rectangleEnemy->SetX(0.0f);
			rectangleEnemy->SetY(-200.0f);
			rectangleEnemy->SetWidth(90.0f);
			rectangleEnemy->SetHeight(45.0f);
			rectangleEnemy->SetChangedShape(true);
			rectangleEnemy->SetActiveMovement(false);
			rectangleEnemy->SetRotationEnemy(false);
			rectangleEnemy2->SetX(91.0f);
			rectangleEnemy2->SetY(-200.0f);
			rectangleEnemy2->SetWidth(550.0f);
			rectangleEnemy2->SetHeight(45.0f);
			rectangleEnemy2->SetChangedShape(true);
			rectangleEnemy2->SetActiveMovement(false);
			rectangleEnemy2->SetRotationEnemy(false);
			break;
		case 6:
			rectangleEnemy->SetX(0.0f);
			rectangleEnemy->SetY(-400.0f);
			rectangleEnemy->SetWidth(200.0f);
			rectangleEnemy->SetHeight(300.0f);
			rectangleEnemy->SetChangedShape(true);
			rectangleEnemy->SetActiveMovement(false);
			rectangleEnemy->SetRotationEnemy(false);
			rectangleEnemy2->SetX(440.0f);
			rectangleEnemy2->SetY(-400.0f);
			rectangleEnemy2->SetWidth(200.0f);
			rectangleEnemy2->SetHeight(300.0f);
			rectangleEnemy2->SetChangedShape(true);
			rectangleEnemy2->SetActiveMovement(false);
			rectangleEnemy2->SetRotationEnemy(false);
			break;
		case 7:
			rectangleEnemy->SetX(50.0f);
			rectangleEnemy->SetY(-200.0f);
			rectangleEnemy->SetWidth(200.0f);
			rectangleEnemy->SetHeight(50.0f);
			rectangleEnemy->SetChangedShape(true);
			rectangleEnemy->SetActiveMovement(true);
			rectangleEnemy->SetRotationEnemy(false);
			rectangleEnemy2->SetX(100.0f);
			rectangleEnemy2->SetY(-100.0f);
			rectangleEnemy2->SetWidth(200.0f);
			rectangleEnemy2->SetHeight(50.0f);
			rectangleEnemy2->SetChangedShape(true);
			rectangleEnemy2->SetActiveMovement(true);
			rectangleEnemy2->SetRotationEnemy(false);
			break;
		case 8:
			rectangleEnemy->SetX(100.0f);
			rectangleEnemy->SetY(-200.0f);
			rectangleEnemy->SetWidth(200.0f);
			rectangleEnemy->SetHeight(50.0f);
			rectangleEnemy->SetChangedShape(true);
			rectangleEnemy->SetActiveMovement(false);
			rectangleEnemy->SetRotationEnemy(true);
			rectangleEnemy2->SetX(400.0f);
			rectangleEnemy2->SetY(-200.0f);
			rectangleEnemy2->SetWidth(200.0f);
			rectangleEnemy2->SetHeight(50.0f);
			rectangleEnemy2->SetChangedShape(true);
			rectangleEnemy2->SetActiveMovement(false);
			rectangleEnemy2->SetRotationEnemy(true);
			break;
		default:
			break;
		}
	}

	void Gameplay::SetPause() 
	{
		if(IsKeyPressed(KEY_P)) 
		{
			_pause = !_pause;
		}
		if (CheckCollisionPointRec(mouse, _pauseRec))
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				_pause = !_pause;
		}
	}

	int Gameplay::GetPoints()
	{
		return _points;
	}

	void Gameplay::PowerUp()
	{
		if (_points == 1000)
		{
			rectangleEnemy->SetSpeedY(170.0f);
			rectangleEnemy2->SetSpeedY(170.0f);
		}
		if (_points == 2000)
		{
			rectangleEnemy->SetSpeedY(190.0f);
			rectangleEnemy2->SetSpeedY(190.0f);

		}
		if (_points == 3000)
		{
			rectangleEnemy->SetSpeedY(210.0f);
			rectangleEnemy2->SetSpeedY(210.0f);
			player->SetSpeed(350.0f);
		}
		if (_points == 3500)
		{
			rectangleEnemy->SetSpeedY(230.0f);
			rectangleEnemy2->SetSpeedY(230.0f);
		}
	}

	void Gameplay::PopUp()
	{
		if (popUp)
		{
			if (_time != 0.0f)
				if(_time < 2.0f)
					DrawText("+100!", player->GetX(), player->GetY() - 25, 25, WHITE);
			if (_time > 2.0f)
				popUp = false;
		}
	}

	void Gameplay::Update()
	{
		if (_pause == false) 
		{
			mouse = GetMousePosition();
			player->SetInputs();
			player->CollisionWindow();
			rectangleEnemy->MoveRectangleEnemy();
			rectangleEnemy->RectangleEnemyOutOfScreen();
			rectangleEnemy2->MoveRectangleEnemy();
			rectangleEnemy2->RectangleEnemyOutOfScreen();
			circleEnemy->MoveCircleEnemy();
			circleEnemy->CircleEnemyOutOfScreen();
			CollisionsGame();
			CheckPlayerAlive();
			SetPause();
			PowerUp();
			PopUp();
			_rotation++;
			if (rectangleEnemy->GetOutOfScreen() == true && rectangleEnemy2->GetOutOfScreen() == true)
			{
				if (!rectangleEnemy->GetChangedShape() && !rectangleEnemy2->GetChangedShape())
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
		} else 
		{
			if(IsKeyPressed(KEY_P) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				_pause = !_pause;
		}
	}

	void Gameplay::Draw()
	{
		DrawRectangleRec(player->GetPlayerRec(), player->GetColor());
		if (rectangleEnemy->GetRotationEnemy() && rectangleEnemy2->GetRotationEnemy())
		{
			DrawRectanglePro(rectangleEnemy->GetRectangleEnemyRec(), {rectangleEnemy->GetX() + rectangleEnemy->GetWidth()/2, rectangleEnemy->GetHeight()/2 }, _rotation, rectangleEnemy->GetColor());
			DrawRectanglePro(rectangleEnemy2->GetRectangleEnemyRec(), {rectangleEnemy2->GetX() + rectangleEnemy2->GetWidth()/2, rectangleEnemy2->GetHeight()/2 }, _rotation, rectangleEnemy2->GetColor());
		}
		else
		{
			DrawRectangleRec(rectangleEnemy->GetRectangleEnemyRec(), rectangleEnemy->GetColor());
			DrawRectangleRec(rectangleEnemy2->GetRectangleEnemyRec(), rectangleEnemy2->GetColor());
		}
		DrawCircle(static_cast<int>(circleEnemy->GetX()), static_cast<int>(circleEnemy->GetY()), circleEnemy->GetRadius(), circleEnemy->GetColor());
		DrawText(TextFormat("Points: %i", _points), 2, 2, 20, WHITE);
		if (player->IsDead())
		{
			DrawText("You Lose!", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2, 50, WHITE);
		}
		if(_pause == true)
			DrawText("PAUSE", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2, 70, WHITE);
		DrawRectangleRec(_pauseRec, WHITE);
	}

	void Gameplay::Unload() 
	{
		_time = 0.0f;
		_points = 0;
		_rotation = 0;
	}
}