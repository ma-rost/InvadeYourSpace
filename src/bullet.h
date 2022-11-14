#ifndef BULLET_H
#define BULLET_H
#include "destructible.h"

class Bullet : public Destructible {
	const bool isPlayer_;
	bool isFired_{false};
	bool isActive_{ false };
	Point <float> bulletOrigin_;

	static constexpr float MOVE_SPEED{ 10 };

public:
	explicit Bullet();
	explicit Bullet (const bool& isPlayer);
	Bullet (const float& x, const float& y, const bool& isPlayer);

	void isBulletActive(const bool& isBottom);

	void move();
	void fire();
	bool isHitValid();

	void resetBullet();
	void setBulletOrigin(Point <float> bulletOrigin);

	Bullet& operator++ ();

	static float getMoveSpeed() { return MOVE_SPEED; }

	void checkCollider(Destructible& obj);
};

inline Bullet& Bullet::operator++ ()
{
	isPlayer_ ? collider_.y -= MOVE_SPEED :
				collider_.y += MOVE_SPEED;
	return *this;
}
#endif // BULLET_H
