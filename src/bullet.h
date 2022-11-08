#pragma once
#include "character.h"

class Bullet : public Character{
	Character spawnSource_;
	const bool isPlayer_;
	bool isFired_{false};

public:

	Bullet (const float& x, const float& y, Character spawnSource,
	        const bool& isPlayer);

	void move();
	void draw();
	bool checkHit();
	void resetBullet(const Character& c);

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
