#pragma once
#include "character.h"

// THINGS TO DO /////
// - Make enemies move down when hitting right side
//		- only rightmost enemies slide down
// - Only bottom most enemy has (Working) bullets
//		- Hide bullets on enemies not bottommost

class Enemy : public Character {
	Point <int> placeValue_;
	Point <float> selfCoord_;
	int setupRows(int& setNum);

public:
	bool isBottomMost_;

	Enemy(const float& x, const float& y, int& rowNum, Character& player);

	void draw();
	void move(Point <float> refCoord);
	
	void kill();

	void getSprite(bool isFirst, const int& setNum);

	void setNewBottom();

	bool canShoot();
};

class EnemyContainer {
	Rect <float> wholeCollision_;
	static constexpr float MOVE_SPEED{ 8 };
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
