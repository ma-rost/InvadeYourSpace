#pragma once
#include "destructible.h"

class Bullet : public Destructible {
	const bool isPlayer_;
	bool isFired_{ false };
	bool isActive_{ false };
	Point <float> bulletOrigin_;

	static constexpr float MOVE_SPEED{ 10 };

public:
	explicit Bullet();
	explicit Bullet (const bool& isPlayer);
	Bullet (const float& x, const float& y, const bool& isPlayer);

	void move();
	void fire();
	bool isHitValid();

	void resetBullet();
	void setBulletOrigin(Point <float> bulletOrigin);
	void isBulletActive(const bool& isBottom);

	void checkCollider(Destructible& obj);

	static float getMoveSpeed() { return MOVE_SPEED; }
	Bullet& operator++ ();
};

inline Bullet& Bullet::operator++ ()
{
	isPlayer_ ? collider_.y -= MOVE_SPEED :
				collider_.y += MOVE_SPEED;
	return *this;
}
