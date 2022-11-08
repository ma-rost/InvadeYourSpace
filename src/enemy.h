#pragma once
#include "character.h"
#include <algorithm>

class Enemy : public Character {
	static std::vector<Enemy*> enemies_;
	Enemy* enemy_;
	static bool isForwardMove_;
	static int downTrigger_;
	int points_{30};
	bool isBottomMost_;
public:
	
	Enemy (const float& x, const float& y, int& spriteSet);
	void draw ();
	void move();

	void getSprite (bool isFirst, const int& setNum);

	void hitEvent(const bool& isTrue);

	static void moveForward();

	void moveDown();

	static std::vector<Enemy*> getAllObjects() {
		return enemies_;
	}
	
};
