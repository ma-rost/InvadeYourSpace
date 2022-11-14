// ReSharper disable All
#include "enemy.h"
#include <vector>       // std::vector
#include "ofGraphics.h"


// Static variables must be declared in the .cpp file


Enemy::Enemy(const float& x, const float& y, int& spriteSet) :
	Character(x, y, false)
{
	selfCoord_ = { x,y };
	int sprite = setupRows (spriteSet);

	sprite_.clearCoords();
	getSprite (true, sprite); // Sprite 1
	getSprite (false, sprite); // Sprite 2 
	sprite_.newCoords({ 55, 1 }); // Death Sprite
	
}

int Enemy::setupRows(int& setNum)
{
	int sprite;
	drawColor_ = ofColor::red;
	sprite = 0;
	if (setNum == 1 || setNum == 2) {
		sprite = 1;
		points_ = 20;
		drawColor_ = ofColor::orangeRed;
	}
	else if (setNum == 3 || setNum == 4) {
		sprite = 2;
		points_ = 10;
		drawColor_ = ofColor::paleVioletRed;
		isBottomMost_ = true;
		bullet_.isBulletActive(isBottomMost_);
	}

	return sprite;
}

void Enemy::draw ()
{
	Character::draw(isLive_ ? getSpriteValue() : 2);
}

void Enemy::move (Point<float> refCoord)
{
	coordinate_.x = selfCoord_.x + refCoord.x;
	coordinate_.y = selfCoord_.y + refCoord.y;
	draw();
}

void Enemy::getSprite (const bool isFirst, const int& setNum)
{
	const int x = 1 + (setNum * 18);
	const int y = isFirst ? 1 : 11;
	
	sprite_.newCoords({x, y});
}

