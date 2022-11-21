#pragma once

#include "ofMain.h"
#include "enemy.h"
#include "player.h"
#include "GameEvent.h"


class ofApp : public ofBaseApp{

	ofTrueTypeFont retroFont_;

	public:
		void setup();
		void update();
		void drawScore();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseReleased(int x, int y, int button);

		void gameEvent(GameEvent& e);
		void playerDied();
		void newGame();
		void endGame();
		void gameLost();
		void gameWon();
		
		Player player_{ 10, 70 };
		EnemyContainer enemyContainer_{ player_ };

		enum gameStates_ { startScreen, inPlay, won, lost };
		int curState_ = inPlay;
		int enemiesAlive_;

		bool isPlayerLive_{ true };
		int playerLivesLeft_{ 3 };
		int score_{ 0 };
		
};


