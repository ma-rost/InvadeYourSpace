#pragma once
#include "character.h"

class Enemy : public Character {
	static std::vector <Enemy> allEnemies_;

	//const float moveSpeed_{12};
	static bool isForwardMove_;
public:
	
	Enemy (const float& x, const float& y, int& spriteSet);
	void draw ();
	void move();

	void getSprite (bool isFirst, const int& setNum);

	void hitEvent(const bool& isTrue);
};
