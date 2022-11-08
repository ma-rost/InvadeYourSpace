#pragma once
#include "character.h"
#include "destructible.h"

class Bullet : public Destructible {
	//Character spawnSource_;
	const bool isPlayer_;
	bool isFired_{false};

public:
	explicit Bullet (const bool& isPlayer);
	Bullet (const float& x, const float& y, const bool& isPlayer);

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
