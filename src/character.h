#pragma once

#include "bullet.h"
#include "destructible.h"

class Character : public Destructible {
protected:
	const bool isPlayer_;
	Point <float> bulletSpawn_;
	Bullet bullet_;
public:
	Character (const float& x, const float& y, const bool& isPlayer);
	Character(const float& x, const float& y, const bool& isPlayer, const float& moveSpeed);

	void setBulletSpawn();

	void move(const bool& isMoveRight);
	void fire();
	void draw(const int& spriteIndex);

	Character& operator++ ();
	Character& operator-- ();
};


