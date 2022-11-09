#pragma once

#include "character.h"

class Player : public Character {
	static float moveSpeed_;
public:
	Player (const float& x, const float& y);

	void move (bool isRightKey);
	void draw ();

	void kill ();

	void shoot();


	static float getMoveSpeed() {
		return moveSpeed_;
	}
};