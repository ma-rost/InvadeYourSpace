// ReSharper disable All
#include "enemy.h"
#include <vector>       // std::vector
#include "ofGraphics.h"


// Static variables must be declared in the .cpp file


Enemy::Enemy(const float& x, const float& y, int& rowNum) :
	Character(x, y, false)
{
	int sprite = setupRows (rowNum);

	sprite_.clearCoords();
	getSprite (true, sprite); // Sprite 1
	getSprite (false, sprite); // Sprite 2 
	sprite_.newCoords({ 55, 1 }); // Death Sprite

	placeValue_ = { static_cast<int>(x/18),static_cast<int>(rowNum) };
	selfCoord_ = applyResize ({x,y});
}

int Enemy::setupRows(int& setNum)
{
	int sprite;
	drawColor_ = ofColor::red;
	sprite = 0;
	if (setNum == 1 || setNum == 2) {
		sprite = 1;
		drawColor_ = ofColor::orangeRed;
	}
	else if (setNum == 3 || setNum == 4) {
		sprite = 2;
		drawColor_ = ofColor::paleVioletRed;
	}
	points_ -= sprite * 10;

	isBottomMost_ = setNum == 4 ? true : false;
	bullet_.isBulletActive(isBottomMost_);

	return sprite;
}

void Enemy::draw ()
{
	Character::draw(isLive_ ? getSpriteValue() : 2);
}

void Enemy::move (Point<float> refCoord)
{
	collider_.x = selfCoord_.x + refCoord.x;
	collider_.y = selfCoord_.y + refCoord.y;
	draw();
}

void Enemy::getSprite (const bool isFirst, const int& setNum)
{
	const int x = 1 + (setNum * 18);
	const int y = isFirst ? 1 : 11;
	
	sprite_.newCoords({x, y});
}

void Enemy::hitEvent (const bool& isTrue)
{
	if (isBottomMost_) {
		
	}
}

void Enemy::setNewBottom (const bool& val)
{
	isBottomMost_ = val;
}

bool Enemy::canShoot ()
{
	return isLive_ && isBottomMost_ ? true : false;
}

