#pragma once
#include "destructible.h"


class Character;
class EnemyContainer;

class Bullet : public Destructible {

	/*Character* player_;
	EnemyContainer* container_;*/

	const bool isPlayer_;
	bool isFired_ {false};
	ofEvent <bool> fired_;
	bool isActive_ {false};
	Point <float> bulletOrigin_;

	static constexpr float MOVE_SPEED {10};

public:
	std::string memoryAddress_;
	explicit Bullet();
	explicit Bullet(const bool& isPlayer);
	Bullet(const float& x, const float& y, const bool& isPlayer);

	void move();
	void fire();
	bool isHitValid();

	void resetBullet();
	void setBulletOrigin(Point <float> bulletOrigin);
	void setIsActive(const bool& isBottom);
	
	bool hasHitOppos(Rect<float> col, bool isLive);

	Bullet& operator++();
};

inline Bullet& Bullet::operator++()
{
	isPlayer_ ? collider_.y -= MOVE_SPEED : collider_.y += MOVE_SPEED;
	return *this;
}
