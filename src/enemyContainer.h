#pragma once
#include <array>

#include "globals.h"
#include "enemy.h"
#include "point.h"

class EnemyContainer {

	Point<float> wholeCoordinate_; // The coordinate of the first enemy
	Point<float> wholeSize_; // The size of all of the enemies compiled into one

	Rect <float> wholeCollision_;
	static constexpr float MOVE_SPEED{ 8 };
	static bool isForwardMove_;

	std::array<std::vector<Enemy>, 11> enemyTest_;
public:
	EnemyContainer();

	void draw();

	void isMovingRight ();
	void setWholeSize(int rowSize, int columnSize);

	void setWholeCoordinate(const Point<float> coordinate);
	void drawDebugRange() const;
	void drawEnemies ();

	void makeShoot ();
	void moveWhole();
	static float getMoveSpeed() { return MOVE_SPEED; }
};
