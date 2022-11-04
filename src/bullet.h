#pragma once
#include "character.h"

class Bullet : public Character{
public:

	Bullet(const float& x, const float& y);

	void move();
	void draw();
};
