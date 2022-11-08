// ReSharper disable All
#include "enemy.h"

#include "ofGraphics.h"
#include <algorithm>

// Static variables must be declared in the .cpp file
bool Enemy::isForwardMove_;

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

	if (ofGetFrameNum() % 30 == 0) {
		Character::move(isForwardMove_);
	}
	draw();
}

void Enemy::getSprite (const bool isFirst, const int& setNum)
{
	const int x = 1 + (setNum * 18);
	const int y = isFirst ? 1 : 11;
	
	sprite_.newCoords({x, y});
}