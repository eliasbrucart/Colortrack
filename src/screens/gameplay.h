#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "gameobjects/player.h"
#include "gameobjects/circle_enemy.h"
#include "gameobjects/rectangle_enemy.h"

namespace Colortrack
{
	class Gameplay
	{
	private:
		Player* _player;
		RectangleEnemy* _rectangleEnemy;
		RectangleEnemy* _rectangleEnemy2;
		CircleEnemy* _circleEnemy;
		float _timePopUp;
		int _timer;
		int _timeDeath;
		int _points;
		bool _pause;
		float _rotation;
		bool _muted;
		Vector2 _mouse;
		Rectangle _pauseRec;
		Rectangle _backToMenuRec;
		Rectangle _muteAudio;
		Texture2D _menuButtonSprite;
		Texture2D _pauseButtonSprite;
		Texture2D _muteAudioSprite;
		Texture2D _unMuteAudioSprite;
		Sound _pointEarned;
		Sound _gameOver;
		enum buttonsHover {
			menuButtonHover,
			pauseButtonHover,
			muteButtonHover,
			noHover
		};
		buttonsHover _mouseHoverInButton;
	public:
		Gameplay();
		~Gameplay();
		void Init();
		void SetEnemiesColors();
		void SetPlayerColors();
		bool CheckEnemiesColors();
		bool CheckEnemiesPlayerColors();
		void CollisionsGame();
		void CheckPlayerAlive();
		void GenerateShapes();
		void SetPause();
		int GetPoints();
		void IncreaseEnemySpeed();
		void PopUp();
		void ActivateRotationEnemy();
		void BackToMenuInput();
		void MuteAudio();
		void CheckColorValidation();
		void Update();
		void Draw();
		void Unload();
	};
}

#endif