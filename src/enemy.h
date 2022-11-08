#pragma once
#include "character.h"

class Enemy : public Character {
	
	static bool isForwardMove_;
	int points_{30};
	bool isBottomMost_;
public:
	
	Enemy (const float& x, const float& y, int& spriteSet);
	void draw ();
	void move();

	void getSprite (bool isFirst, const int& setNum);

	void hitEvent(const bool& isTrue);
	
};
