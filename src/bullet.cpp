#include "bullet.h"

Bullet::Bullet ( const bool& isPlayer):
	Bullet (4,5,isPlayer)
{

}

Bullet::Bullet (const float& x, const float& y, const bool& isPlayer):
	Destructible(x, y),  isPlayer_ (isPlayer)
{
	drawColor_ = ofColor::green;

	sprite_.clearCoords();
	sprite_.setSize({ 3,8 });
	sprite_.newCoords({ 41,21 }); // Default
	sprite_.newCoords({ 16,21 }); // Death
}

void Bullet::move ()
{
	isPlayer_ ? --*this : ++*this;
}

void Bullet::draw ()
{
	Destructible::draw(isLive_ ? 0 : 1);
}

bool Bullet::checkHit ()
{
	return false;
}

