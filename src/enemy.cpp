// ReSharper disable All
#include "enemy.h"

#include "ofGraphics.h"
#include <algorithm>

// Static variables must be declared in the .cpp file
std::vector <Enemy> Enemy::allEnemies_;
bool Enemy::isForwardMove_;

Enemy::Enemy (const float& x, const float& y, int& spriteSet):
	Character (x, y, false)
{
	drawColor_ = ofColor::red;
	moveSpeed_ = 12;
	int sprite = 0;

	if		( spriteSet == 1 || spriteSet == 2 )  sprite = 1; 
	else if ( spriteSet == 3 || spriteSet == 4 )  sprite = 2; 

	sprite_.clearCoords();
	getSprite (true, sprite); // Sprite 1
	getSprite (false, sprite); // Sprite 2 
	sprite_.newCoords({ 55, 1 }); // Death Sprite

	Enemy::allEnemies_.push_back (*this);
}

void Enemy::draw ()
{
	Destructible::draw(isLive_ ? getSpriteValue() : 2);
	setBulletSpawn(false);
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

void Enemy::hitEvent (const bool& isTrue)
{

}