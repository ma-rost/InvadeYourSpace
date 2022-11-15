#pragma once
#include "destructible.h"

class Character;
class EnemyContainer;

class Bullet : public Destructible {

	/*Character* player_;
	EnemyContainer* container_;*/

	const bool isPlayer_;
	bool isFired_ {false};
	bool isActive_ {false};
	Point <float> bulletOrigin_;

	//std::vector <Destructible> targetableObj_;

	static constexpr float MOVE_SPEED {10};

public:
	explicit Bullet();
	explicit Bullet(const bool& isPlayer);
	Bullet(const float& x, const float& y, const bool& isPlayer);

	void move();
	void fire();
	bool isHitValid();

	void resetBullet();
	void setBulletOrigin(Point <float> bulletOrigin);
	void isBulletActive(const bool& isBottom);

	void checkEach(const Character& obj);
	void checkCollider();
	bool hasHitOppos(Rect<float> col);

	static float getMoveSpeed() { return MOVE_SPEED; }
	Bullet& operator++();
};

inline Bullet& Bullet::operator++()
{
	isPlayer_ ? collider_.y -= MOVE_SPEED : collider_.y += MOVE_SPEED;
	return *this;
}
