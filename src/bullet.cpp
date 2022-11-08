#include "bullet.h"

Bullet::Bullet (const float& x, const float& y, const Character& spawnSource, const bool& isPlayer):
	Character(x, y), spawnSource_ (spawnSource), isPlayer_ (isPlayer)
{
	drawColor_ = ofColor::green;

	sprite_.clearCoords();
	sprite_.setSize({ 3,8 });
	sprite_.newCoords({ 41,21 });
}

void Bullet::move ()
{
	isPlayer_ ? --*this : ++*this;
}

void Bullet::draw ()
{
	Character::draw(0);
}

bool Bullet::checkHit ()
{
	return false;
}

