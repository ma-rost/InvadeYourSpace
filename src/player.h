#pragma once

#include "character.h"

class Player : public Character {
	const float moveSpeed_{10};
public:
	Player (const float& x, const float& y);

	void move (bool isRightKey);
	void draw () const;

	void kill ();
};
