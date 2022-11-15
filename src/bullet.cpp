#include "bullet.h"

#include "character.h"
#include "ofGraphics.h"

Bullet::Bullet():
	Bullet (4, 5, true)
{
}

Bullet::Bullet(const bool& isPlayer):
	Bullet (4, 5, isPlayer)
{
}

Bullet::Bullet(const float& x, const float& y, const bool& isPlayer):
	Destructible (x, y), isPlayer_ (isPlayer)
{
	sprite_.clearCoords();
	sprite_.setSize ({3, 7});
	sprite_.newCoords ({41, 21}); // Default
	sprite_.newCoords ({16, 21}); // Death
}

void Bullet::isBulletActive(const bool& isBottom) { isActive_ = isBottom; }

void Bullet::checkEach(const Character& obj)
{
	if(isFired_) {
		isFired_ = hasHitOppos(obj.getCollider());
	}
}

void Bullet::checkCollider()
{
}

void Bullet::move()
{
	if (!isFired_) { resetBullet(); }
	else {
		isFired_ = isHitValid();
		++*this;
	}

	draw (isLive_ ? 0 : 1);
}

void Bullet::fire()
{
	if (!isFired_) {
		isFired_ = true;
		drawColor_ = ofColor::white;
	}
}

bool Bullet::isHitValid()
{
	if (collider_.y < 1 || collider_.y > ofGetViewportHeight()) { return false; }
	return true;
}

void Bullet::resetBullet()
{
	drawColor_ = ofColor::red;
	setCoords (bulletOrigin_.x, bulletOrigin_.y, false);
}


void Bullet::setBulletOrigin(const Point <float> bulletOrigin)
{
	bulletOrigin_ = bulletOrigin;
}

bool Bullet::hasHitOppos(Rect<float> col)
{
	if (collider_.x <= col.x && collider_.addXW() >= col.addXW()) {
		std::cout << "IN X\n";
		return true;
	}
	if (collider_.y <= col.y && collider_.addYH() >= col.addYH()) {
		std::cout << "IN Y\n";
		return true;
	}

	return false;
}
