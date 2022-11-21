#pragma once
#include "enemyContainer.h"
#include "GameEvent.h"
#include "ofTrueTypeFont.h"
#include "player.h"

class GameTemplate {
	bool isPlayerLive_{ true };
	
	int enemiesAlive_;

	Player player_{ 10, 70 };
	EnemyContainer enemyContainer_{ player_ };

	enum gameState_ { startScreen, inPlay, won, lost };
	int state_ = inPlay;

	ofTrueTypeFont retroFont_;

public:
	int playerLivesLeft_{ 3 };
	int score_{ 0 };

	void setup();
	void update();
	void drawScore();
	void draw();

	void playerDied();
	void newGame();
	void endGame();

	void gameLost();
	void gameWon();
	void keyRelease(int key);

	void keyPress(int key);
	


	void gameEvent(GameEvent& e);
	
};


