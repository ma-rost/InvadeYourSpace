// ReSharper disable All
#include "enemy.h"


Enemy::Enemy (const float& x, const float& y, int& spriteSet):
	Character (x, y)
{
	int sprite = 0;

	if		( spriteSet == 1 || spriteSet == 2 )  sprite = 1; 
	else if ( spriteSet == 3 || spriteSet == 4 )  sprite = 2; 

	sprite_.clearCoords();
	getSprite (true, sprite);
	getSprite (false, sprite);
}

void Enemy::draw ()
{
	ofSetColor (ofColor::red);
	sprite_.drawSprite(getSpriteValue(), coordinate_.x, coordinate_.y);
}

void Enemy::getSprite (const bool isFirst, const int& setNum)
{
	const int x = 1 + (setNum * 18);
	const int y = isFirst ? 1 : 11;
	
	sprite_.newCoords({x, y});
}
