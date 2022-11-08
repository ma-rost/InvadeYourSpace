#pragma once

#include "bullet.h"
#include "destructible.h"
#include "point.h"

class Character : public Destructible {
protected:
	const bool isPlayer_;
	Point <float> bulletSpawn_;
	Bullet bullet_;
public:
	Character (const float& x, const float& y, const bool& isPlayer);
	Character(const float& x, const float& y, const bool& isPlayer, const float& moveSpeed);

	void setBulletSpawn(const bool& isPlayer);

	void move(const bool& isMoveRight);
	void fire();

	Character& operator++ ();
	Character  operator++ (int);
	Character& operator-- ();
	Character  operator-- (int);
};


