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
	Destructible(x, y, 24),  isPlayer_ (isPlayer)
{
	sprite_.clearCoords();
	sprite_.setSize({ 3,7 });
	sprite_.newCoords({ 41,21 }); // Default
	sprite_.newCoords({ 16,21 }); // Death
}

void Bullet::move ()
{
}

void Bullet::draw ()
{
	resetBullet();

	Destructible::draw(isLive_ ? 0 : 1);
}

void Bullet::fire ()
{
	if(!isFired_) {
		
		//isFired_ = true;
		drawColor_ = ofColor::white;
		++* this;
	}
}

bool Bullet::checkHit ()
{
	return false;
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
