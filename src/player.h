#pragma once
#include "character.h"
#include <array>

class Player : public Character {
	static constexpr float MOVE_SPEED {12};
public:
	Player(const float& x, const float& y);

	void move(bool isRightKey);
	void draw();
	void respawn();
};
