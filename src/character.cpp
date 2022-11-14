// ReSharper disable All
#include "character.h"
#include "ofGraphics.h"

Character::Character (const float& x, const float& y, const bool& isPlayer):
	Character (x, y , isPlayer, 10)
{
}

Character::Character (const float& x, const float& y, const bool& isPlayer, const float& moveSpeed):
	Destructible (x, y), isPlayer_ (isPlayer), bullet_ (isPlayer_)
{
	setBulletSpawn();
	bullet_.resetBullet();
}

#pragma region Actions

void Character::move(const bool& isMoveRight)
{
	isMoveRight ? ++ * this : -- * this;
}

void Character::draw(const int& spriteIndex)
{
	setBulletSpawn();
	bullet_.move();
	Destructible::draw(spriteIndex);
}

void Character::fire()
{
	bullet_.fire();
}
#pragma endregion

void Character::setBulletSpawn()
{
	bulletSpawn_.x = collider_.x + sprite_.getSize().x / 2 - 3;

	if (isPlayer_) { // Player
		bulletSpawn_.y = collider_.y - sprite_.getSize().y / 2 - 20;
	}
	else {			// Enemy
		bulletSpawn_.x-= 1; // Makes Bullet centered on enemies
		bulletSpawn_.y = collider_.y + sprite_.getSize().y / 2 + 20;
	}
	bullet_.setBulletOrigin(bulletSpawn_);
}

Point<float> Character::getCoordinate ()
{
	return collider_.getXY();
}

bool Character::checkCollide(const Destructible& obj)
{
	/*if ( >= ) {

	}*/
	return false;
}

#pragma region Operators
Character& Character::operator++ ()
{
	this->collider_.x += this->getMoveSpeed();
	return *this;
}

Character& Character::operator-- ()
{
	this->collider_.x -= this->getMoveSpeed();
	return *this;
}

#pragma endregion



