#pragma once
#include <array>
#include "enemy.h"
#include "ofGraphics.h"
#include "point.h"

class EnemyContainer {
	Rect <float> wholeCollision_;
	static constexpr float MOVE_SPEED {8};
	static bool isForwardMove_;

	std::array <std::vector <Enemy>, 11> enemyTest_;
public:
	explicit EnemyContainer(Character& player);

	void draw();
	void drawDebugRange() const;
	void drawEnemies();
	void moveWhole();
	void isMovingRight();

	void setWholeSize(int rowSize, int columnSize);
	void setWholeCoordinate(const Point <float> coordinate);
	
	/** \brief Randomly chooses a bullet for one of the enemies to fire */
	void fireEvent();
	void checkForHit();
	void newBottomEnemy();
	bool enemiesLive();

	int totalEnemies();
	void debugKillAllEnemies();

	std::array<std::vector<Enemy>, 11>& getAllEnemies();
};


