// ReSharper disable All
#include "enemy.h"
#include <vector>       // std::vector
#include "ofGraphics.h"


// Static variables must be declared in the .cpp file
bool Enemy::isForwardMove_;
int Enemy::downTrigger_;
std::vector<Enemy*>Enemy::enemies_;

Enemy::Enemy (const float& x, const float& y, int& spriteSet):
	Character (x, y, false)
{
	drawColor_ = ofColor::red;
	moveSpeed_ = 12;
	int sprite = 0;
	if	( spriteSet == 1 || spriteSet == 2 ) {
		sprite = 1;
		points_ = 20;
		drawColor_ = ofColor::orangeRed;
	}
	else if ( spriteSet == 3 || spriteSet == 4 ) {
		sprite = 2;
		points_ = 10;
		drawColor_ = ofColor::paleVioletRed;
		isBottomMost_ = true;
	}

	sprite_.clearCoords();
	getSprite (true, sprite); // Sprite 1
	getSprite (false, sprite); // Sprite 2 
	sprite_.newCoords({ 55, 1 }); // Death Sprite
	enemy_ = &*this;
	std::cout << enemy_->isPlayer_;
	enemies_.push_back(enemy_);
}

void Enemy::draw ()
{
	Character::draw(isLive_ ? getSpriteValue() : 2);
}

void Enemy::move ()
{
	// When Enemy hits drawRestrictions_ value, toggle isForwardMove
	if (coordinate_.x >= drawRestrictions_.y) isForwardMove_ = false;
	if (coordinate_.x <= drawRestrictions_.x) isForwardMove_ = true;

	Character::move(isForwardMove_);
	draw();
}

void Enemy::getSprite (const bool isFirst, const int& setNum)
{
	const int x = 1 + (setNum * 18);
	const int y = isFirst ? 1 : 11;
	
	sprite_.newCoords({x, y});
}

void Enemy::moveForward ()
{
	for (int i = 0; i < Enemy::getAllObjects().size(); i++) {
		std::cout << downTrigger_;

	}
	std::cout << std::endl;
}

void Enemy::moveDown ()
{
	if ( downTrigger_ == 1 ) {
		coordinate_.y++;
	}
	downTrigger_ = 0;
}
