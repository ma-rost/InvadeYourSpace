#pragma once

#include "destructible.h"
#include "point.h"
#include "sprite.h"

class Character : public Destructible {
protected:
	Point <float> bulletSpawn_;
public:
	Character (const float& x, const float& y);
	Character(const float& x, const float& y, const float& moveSpeed);

	void setBulletSpawn(const bool& isPlayer);

	void move(const bool& isMoveRight);
	void fire();

	Character& operator++ ();
	Character  operator++ (int);
	Character& operator-- ();
	Character  operator-- (int);
};


