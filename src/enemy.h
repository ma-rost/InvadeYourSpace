#pragma once
#include "character.h"

class Enemy : public Character {

	const float moveSpeed_{10};
public:
	Enemy (const float& x, const float& y, int& spriteSet);
	void draw ();
	void move(bool isRightKey);

	void getSprite (bool isFirst, const int& setNum);

	Enemy& operator++ ();
    Enemy  operator++ (int);
	Enemy& operator-- ();
	Enemy  operator-- (int);
};
