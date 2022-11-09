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


void Character::setBulletSpawn()
{
	bulletSpawn_.x = coordinate_.x + sprite_.getSize().x / 2 - 3;

	if (isPlayer_) { // Player
		bulletSpawn_.y = coordinate_.y - sprite_.getSize().y / 2 - 20;
	}
	else {			// Enemy
		bulletSpawn_.x-= 1; // Makes Bullet centered on enemies
		bulletSpawn_.y = coordinate_.y + sprite_.getSize().y / 2 + 20;
	}
	bullet_.setBulletOrigin(bulletSpawn_);
}

Point<float> Character::getCoordinate ()
{
	return coordinate_;
}

#pragma region Actions

void Character::move(const bool& isMoveRight)
{
	isMoveRight ? ++*this : --*this;
}

void Character::fire()
{
	bullet_.fire();
}

void Character::draw (const int& spriteIndex)
{
	setBulletSpawn();
	bullet_.move();
	Destructible::draw(spriteIndex);
}
#pragma endregion


#pragma region Operators
Character& Character::operator++ ()
{
	this->coordinate_.x += this->moveSpeed_;
	return *this;
}

Character& Character::operator-- ()
{
	this->coordinate_.x -= this->moveSpeed_;
	return *this;
}

#pragma endregion



