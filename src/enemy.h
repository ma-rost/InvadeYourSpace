#pragma once
#include "character.h"
#include "ofImage.h"
#include "point.h"

class Enemy : public Character {

	const float moveSpeed_{ 10 };
	bool test;
public:
	Enemy(const float& x, const float& y, const int& spriteSet);
	void draw();

	void getSprite(bool isFirst, const int& setNum);
};
