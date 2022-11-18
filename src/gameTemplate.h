#pragma once
#include "enemyContainer.h"
#include "player.h"

class GameTemplate {
	bool isPlayerLive_{ true };
	int playerLivesLeft_{3};
	int enemiesAlive_;

	Player player_{ 10, 70 };
	EnemyContainer enemyContainer_{ player_ };

public:
	int score_{ 0 };

	void setup();
	void update();

	void playerDied();
	void newGame();
	void endGame();

	void gameLost();
	void gameWon();

	void keyPress(int key);
};
