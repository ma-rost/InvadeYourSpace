#pragma once
#include "enemyContainer.h"
#include "player.h"

class GameTemplate {
	bool isPlayerLive_{ true };
	int playerLivesLeft_{3};
	int enemiesAlive_;

	Player player{ 10, 70 };
	EnemyContainer enemyContainer{ player };

	int score_ {0};

public:

	void update();

	void playerDied();
	void newGame();
	void endGame();
};
