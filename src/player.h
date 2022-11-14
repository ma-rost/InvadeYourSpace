#pragma once
#include "character.h"
#include <array>

class Player : public Character {
	static constexpr float MOVE_SPEED{ 12 };
	std::array<std::vector<Character>, 11> enemies_;

public:
	Player (const float& x, const float& y);

	void move (bool isRightKey);
	void draw ();
	void kill ();

	static float getMoveSpeed() { return MOVE_SPEED; }
};
