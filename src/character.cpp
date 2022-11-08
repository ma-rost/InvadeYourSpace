// ReSharper disable All
#include "character.h"
#include "ofGraphics.h"

Character::Character (const float& x, const float& y, const bool& isPlayer):
	Character (x, y , isPlayer, 10)
{
}

Character::Character (const float& x, const float& y, const bool& isPlayer, const float& moveSpeed):
	Destructible (x, y, moveSpeed), isPlayer_ (isPlayer), bullet_ (isPlayer_)
{
	//Bullet bullet_ {true};
	setBulletSpawn(isPlayer);
	
	bullet_.setCoords(bulletSpawn_.x, bulletSpawn_.y);
}


void Character::setBulletSpawn(const bool& isPlayer)
{
	bulletSpawn_.x = coordinate_.x + sprite_.getSize().x / 2;

	if (isPlayer) { // Player
		bulletSpawn_.y = coordinate_.y - sprite_.getSize().y / 2 - 5;
	}
	else {			// Enemy
		bulletSpawn_.x-= 1; // Makes Bullet centeered on enemies
		bulletSpawn_.y = coordinate_.y + sprite_.getSize().y / 2 + 20;
	}
	bullet_.setBulletOrigin(bulletSpawn_);
}

#pragma region Actions

void Character::move(const bool& isMoveRight)
{
	isMoveRight ? ++ * this : -- * this;
}

void Character::fire()
{
	bullet_.fire();
}
#pragma endregion



#pragma region Operators
Character& Character::operator++ ()
{
	this->coordinate_.x += this->moveSpeed_;
	return *this;
}

Character  Character::operator++ (int)
{
	Character result(*this);   // make a copy for result
	++(*this);              // Now use the prefix version to do the work
	return result;          // return the copy (the old) value.
}

Character& Character::operator-- ()
{
	this->coordinate_.x -= this->moveSpeed_;
	return *this;
}
Character  Character::operator-- (int)
{
	Character result(*this);   // make a copy for result
	--(*this);              // Now use the prefix version to do the work
	return result;          // return the copy (the old) value.
}
#pragma endregion



