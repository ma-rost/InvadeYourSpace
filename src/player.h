#pragma once
#include "character.h"
#include <array>

class Player : public Character {
	static constexpr float MOVE_SPEED {12};
public:
	int score_{ 0 };
	Player(const float& x, const float& y);

	void move(bool isRightKey);
	void draw();
	void kill();

	void killEnemy();

	int getScore();
	void getDigits(int x);
	void printDigits();

	static float getMoveSpeed() { return MOVE_SPEED; }
};
