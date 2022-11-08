#pragma once

#include "destructible.h"

class Bullet : public Destructible {
	//Character spawnSource_;
	const bool isPlayer_;
	bool isFired_{false};
	Point <float> bulletOrigin_;

public:
	Bullet();
	explicit Bullet (const bool& isPlayer);
	Bullet (const float& x, const float& y, const bool& isPlayer);

	void move();
	void fire();
	bool isHitValid();

	void resetBullet();
	void setBulletOrigin(Point <float> bulletOrigin);

	Bullet& operator++ ();
};

inline Bullet& Bullet::operator++ ()
{
	isPlayer_ ? coordinate_.y -= moveSpeed_ :
				coordinate_.y += moveSpeed_;
	return *this;
}
