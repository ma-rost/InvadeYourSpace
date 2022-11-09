#include "bullet.h"

#include "ofGraphics.h"

Bullet::Bullet ():Bullet(4, 5, true)
{

}

Bullet::Bullet (const bool& isPlayer):
	Bullet (4,5,isPlayer)
{

}

Bullet::Bullet (const float& x, const float& y, const bool& isPlayer):
	Destructible(x, y, 24), isPlayer_ (isPlayer)
{
	moveSpeed_ = 4;
	sprite_.clearCoords();
	sprite_.setSize({ 3,7 });
	sprite_.newCoords({ 41,21 }); // Default
	sprite_.newCoords({ 16,21 }); // Death
}

void Bullet::isBulletActive (const bool& isBottom)
{
	isActive_ = isBottom;
}

void Bullet::move ()
{
	if (!isFired_) {
		resetBullet();
	}
	else {
		isFired_ = isHitValid();
		++* this;
	}

	draw (isLive_ ? 0 : 1);
}

void Bullet::fire ()
{
	if(!isFired_) {
		isFired_ = true;
		
		drawColor_ = ofColor::white;
	}
	
}

bool Bullet::isHitValid ()
{
	if(coordinate_.y < 1 || coordinate_.y > ofGetViewportHeight()) {
		std::cout << "FIRE\n";
		return false;
	}
	else {
		return true;
	}
	
}

void Bullet::resetBullet ()
{
	drawColor_  = ofColor::red;
	setCoords(bulletOrigin_.x, bulletOrigin_.y, false);
}


void Bullet::setBulletOrigin (const Point<float> bulletOrigin)
{
	bulletOrigin_ = bulletOrigin;
}
