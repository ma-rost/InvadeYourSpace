#pragma once
#include "character.h"

class Enemy : public Character {

	const float moveSpeed_{10};
public:
	Enemy (const float& x, const float& y, const int& spriteSet);
	void draw () const;

	void getSprite (bool isFirst, const int& setNum);
};
