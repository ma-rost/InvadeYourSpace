#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"

class Player : public Character {
	static constexpr float MOVE_SPEED{ 12 };

public:
	Player (const float& x, const float& y);

	void move (bool isRightKey);
	void draw ();

	void kill ();

	void shoot();
	static float getMoveSpeed() { return MOVE_SPEED; }
};
#endif // PLAYER_H
