#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "gameplay.h"
#include "screens.h"

#include"raylib.h"

namespace Colortrack
{
	class GameOver : public Screens {
	private:
		Rectangle _playAgain;
		Rectangle _mainMenu;
		Rectangle _exitButton;
		Vector2 _mouse;
		Gameplay* _gameplay;
		Texture2D _gameOverSprite;
		Texture2D _playButtonSprite;
		Texture2D _menuButtonSprite;
		Texture2D _exitButtonSprite;
		enum buttonCreditsHover {
			playAgain,
			mainMenu,
			exitButton,
			noHover
		};
		buttonCreditsHover _mouseHoverInButton;
	public:
		GameOver(Gameplay* gameplay);
		~GameOver();
		virtual void Input();
		virtual void Draw();
	};

}

#endif