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
	void draw();
	void fire();
	bool checkHit();

	void resetBullet();
	void setBulletOrigin(Point <float> bulletOrigin);

	Bullet& operator++ ();
};

inline Bullet& Bullet::operator++ ()
{
	isPlayer_ ? this->coordinate_.y -= this->moveSpeed_ :
				this->coordinate_.y += this->moveSpeed_;
	this->draw();
	return *this;
}
