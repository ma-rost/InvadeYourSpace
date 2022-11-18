// ReSharper disable All
#include "character.h"

#include "enemyContainer.h"
#include "ofGraphics.h"

Character* Character::player_;
EnemyContainer* Character::container_;

Character::Character(const float& x, const float& y, const bool& isPlayer):
	Character (x, y, isPlayer, 10)
{
}

Character::Character(const float& x, const float& y, 
					 const bool& isPlayer, const float& moveSpeed):
	Destructible (x, y), isPlayer_ (isPlayer), bullet_ (isPlayer_)
{
	setBulletSpawn();
	bullet_.resetBullet();
}

#pragma region Actions
void Character::move(const bool& isMoveRight) { isMoveRight ? ++ *this : -- *this; }

void Character::moveBullet()
{
	setBulletSpawn();
	bullet_.move();
}

void Character::draw(const int& spriteIndex)
{
	moveBullet();
	Destructible::draw (spriteIndex);
}

void Character::fire() { bullet_.fire(); }

bool Character::checkCollider(Bullet& bullet)
{
	ofDrawBitmapString(bullet.memoryAddress_, bullet.getCollider().x, bullet.getCollider().y);

	bool lifeState = bullet.hasHitOppos(getCollider());

	if (lifeState) {
		std::cout << bullet.memoryAddress_ << " HIT ME!";
		kill();
		return true;
	}
	return false;
}
#pragma endregion

void Character::setBulletSpawn()
{
	bulletSpawn_.x = collider_.x + sprite_.getSize().x / 2 - 3;

	if (isPlayer_) {
		// Player
		bulletSpawn_.y = collider_.y - sprite_.getSize().y / 2 - 20;
	}
	else {
		// Enemy
		bulletSpawn_.x -= 1; // Makes Bullet centered on enemies
		bulletSpawn_.y = collider_.y + sprite_.getSize().y / 2 + 20;
	}
	bullet_.setBulletOrigin (bulletSpawn_);
}

Point <float> Character::getCoordinate() { return collider_.getXY(); }



void Character::setDestructibles(Character& player, EnemyContainer& container)
{
	player_ = &player;
	container_ = &container;
}

#pragma region Operators
Character& Character::operator++()
{
	this->collider_.x += this->MOVE_SPEED;
	return *this;
}

Character& Character::operator--()
{
	this->collider_.x -= this->MOVE_SPEED;
	return *this;
}
#pragma endregion