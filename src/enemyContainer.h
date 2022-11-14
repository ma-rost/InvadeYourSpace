#pragma once
#include "globals.h"
#include "enemy.h"
#include "point.h"

class EnemyContainer {
	//static std::array<std::array<Enemy, 5>, 11> enemyTest_;
	static Point<float> wholeCoordinate_; // The coordinate of the first enemy
	static Point<float> wholeSize_; // The size of all of the enemies compiled into one
	static constexpr float MOVE_SPEED{ 24 };

	static bool isForwardMove_;
public:
	EnemyContainer();

	static void isMovingRight();
	static void setWholeSize(int rowSize, int columnSize);

	/*static std::vector<Enemy*> getAllObjects() {
		return enemies_;
	}*/

	static void setWholeCoordinate(const Point<float> coordinate);
	static void drawDebugRange();

	static void moveWhole();
	static float getMoveSpeed() { return MOVE_SPEED; }
};
