#include "enemy.h"

#include "ofGraphics.h"

Enemy::Enemy (const float& x, const float& y, const int& spriteSet): Character(x, y)
{
	getSprite(true, spriteSet);
	getSprite(false, spriteSet);
}

void Enemy::draw () const
{
	ofSetColor (ofColor::red);
	sprites_[getSpriteValue()].draw (coordinate_.x, coordinate_.y);
}

void Enemy::getSprite (bool isFirst, const int& setNum)
{
	const int x = 1 + (setNum * 18);
	const int y = isFirst ? 1 : 11;

	setSprites({x, y});
}
