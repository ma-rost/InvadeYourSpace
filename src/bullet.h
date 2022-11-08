#pragma once
#include "destructible.h"

class Bullet : public Destructible {
	Destructible spawnSource_;
	const bool isPlayer_;
	bool isFired_{false};

public:

	Bullet (const float& x, const float& y, Destructible spawnSource,
	        const bool& isPlayer);

	void move();
	void draw();
	bool checkHit();
	void resetBullet(const Destructible& c);

	Bullet& operator++ ();
	Bullet& operator-- ();
};

inline Bullet& Bullet::operator++ ()
{
	this->coordinate_.y += this->moveSpeed_;
	return *this;
}

inline Bullet& Bullet::operator-- ()
{
	this->coordinate_.y -= this->moveSpeed_;
	return *this;
}
