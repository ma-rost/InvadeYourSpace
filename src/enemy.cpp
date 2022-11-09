// ReSharper disable All
#include "enemy.h"
#include <vector>       // std::vector
#include "ofGraphics.h"


// Static variables must be declared in the .cpp file
bool Enemy::isForwardMove_;
std::vector<Enemy*> Enemy::enemies_;
Point<float> Enemy::wholeCoordinate_; // The coordinate of the first enemy
Point<float> Enemy::wholeSize_; // The size of all of the enemies compiled into one

Enemy::Enemy(const float& x, const float& y, int& spriteSet) :
	Character(x, y, false)
{
	moveSpeed_ = 12;

	drawColor_ = ofColor::red;
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
		bullet_.isBulletActive(isBottomMost_);
	}

	sprite_.clearCoords();
	getSprite (true, sprite); // Sprite 1
	getSprite (false, sprite); // Sprite 2 
	sprite_.newCoords({ 55, 1 }); // Death Sprite

	// Vector
	enemy_ = &*this;
	std::cout << enemy_->isPlayer_;
	enemies_.push_back(&*this);

	setWholeSize(x, y);
}



void Enemy::draw ()
{
	Character::draw(isLive_ ? getSpriteValue() : 2);
}

void Enemy::move ()
{
	// When Enemy hits drawRestrictions_ value, toggle isForwardMove
	if (coordinate_.x >= DRAW_RESTRICTIONS.y) isForwardMove_ = false;
	if (coordinate_.x <= DRAW_RESTRICTIONS.x) isForwardMove_ = true;

	Character::move(isForwardMove_);
	draw();
}

void Enemy::getSprite (const bool isFirst, const int& setNum)
{
	const int x = 1 + (setNum * 18);
	const int y = isFirst ? 1 : 11;
	
	sprite_.newCoords({x, y});
}

#pragma region Static Functions
bool Enemy::isMoveValid()
{
	if (wholeSize_.x >= DRAW_RESTRICTIONS.y)	   return false;
	if (wholeCoordinate_.x <= DRAW_RESTRICTIONS.x) return true;
}

void Enemy::setWholeSize(int rowSize, int columnSize)
{
	wholeSize_.x += 10.7;
	wholeSize_.y += 4.4;

	std::cout << wholeSize_.x << ", " << wholeSize_.y << std::endl;
}

void Enemy::setWholeCoordinate(const Point<float> coordinate)
{
	wholeCoordinate_ = coordinate;
}

void Enemy::drawDebugRange()
{
	ofSetColor(ofColor::lavender);
	ofDrawRectangle(wholeCoordinate_.x, wholeCoordinate_.y, wholeSize_.x, wholeSize_.y);
}

void Enemy::moveWhole()
{
	isMoveValid () ? wholeCoordinate_.x += getMoveSpeed() : wholeCoordinate_.x -= getMoveSpeed();
	drawDebugRange();
}
#pragma endregion

