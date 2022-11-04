// ReSharper disable All
#include "enemy.h"

#include "ofGraphics.h"
#include <algorithm>

// Static variables must be declared in the .cpp file
std::vector <Enemy> Enemy::allEnemies_;
bool Enemy::isForwardMove_;

Enemy::Enemy (const float& x, const float& y, int& spriteSet):
	Character (x, y)
{
	drawColor_ = ofColor::red;
	int sprite = 0;

	if		( spriteSet == 1 || spriteSet == 2 )  sprite = 1; 
	else if ( spriteSet == 3 || spriteSet == 4 )  sprite = 2; 

	sprite_.clearCoords();
	getSprite (true, sprite);
	getSprite (false, sprite);

	Enemy::allEnemies_.push_back (*this);
}

void Enemy::draw ()
{
	ofSetColor (ofColor::red);
	sprite_.drawSprite(getSpriteValue(), coordinate_.x, coordinate_.y);
}

void Enemy::move ()
{
	// When Enemy hits drawRestrictions_ value, toggle isForwardMove
	if (coordinate_.x >= drawRestrictions_.y) isForwardMove_ = false;
	if (coordinate_.x <= drawRestrictions_.x) isForwardMove_ = true;

	if (ofGetFrameNum() % 30 == 0) {
		isForwardMove_ ? ++*this : --*this;
		//coordinate_.x = ofClamp(coordinate_.x, drawRestrictions_.x,
			//drawRestrictions_.y);
	}
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

}


Enemy& Enemy::operator++ ()
{
	this->coordinate_.x += this->moveSpeed_;
	return *this;
}

Enemy  Enemy::operator++ (int)
{
	Enemy result(*this);   // make a copy for result
	++(*this);              // Now use the prefix version to do the work
	return result;          // return the copy (the old) value.
}

Enemy& Enemy::operator-- ()
{
	this->coordinate_.x -= this->moveSpeed_;
	return *this;
}
Enemy  Enemy::operator-- (int)
{
	Enemy result(*this);   // make a copy for result
	--(*this);              // Now use the prefix version to do the work
	return result;          // return the copy (the old) value.
}