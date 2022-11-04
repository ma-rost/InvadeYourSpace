// ReSharper disable All
#include "enemy.h"


Enemy::Enemy (const float& x, const float& y, const int& spriteSet):
	Character (x, y)
{
	getSprite (true, spriteSet);
	getSprite (false, spriteSet);
}

void Enemy::draw ()
{
	ofSetColor (ofColor::red);
	sprites_[getSpriteValue()].drawSprite (coordinate_.x, coordinate_.y);
}

void Enemy::getSprite (const bool isFirst, const int& setNum)
{
	const int x = 1 + (setNum * 18);
	const int y = isFirst ? 1 : 11;

	sprites_.emplace_back(x, y);
}
