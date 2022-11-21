// ReSharper disable All
#include "enemy.h"
#include "ofGraphics.h"
#include <vector>       // std::vector

#include "gameEvent.h"


Enemy::Enemy(const float& x, const float& y, int& rowNum, Character& player) :
	Character (x, y, false)
{
	int sprite = setupRows (rowNum);
	
	sprite_.clearCoords();
	getSprite (true, sprite); // Sprite 1
	getSprite (false, sprite); // Sprite 2 
	sprite_.newCoords ({55, 1}); // Death Sprite

	placeValue_ = {static_cast <int> (x / 18), static_cast <int> (rowNum)};
	selfCoord_  = applyResize ({x, y});
	
	std::ostringstream oss;
	oss << "[" << placeValue_.x << ", " << placeValue_.y << "]";
	bullet_.memoryAddress_ = oss.str();
	
}

int Enemy::setupRows(int& setNum)
{
	value_ = 30;
	int sprite;
	drawColor_ = ofColor::red;
	sprite     = 0;
	if (setNum == 1 || setNum == 2) {
		sprite     = 1;
		drawColor_ = ofColor::orangeRed;
	}
	else if (setNum == 3 || setNum == 4) {
		sprite     = 2;
		drawColor_ = ofColor::paleVioletRed;
	}
	value_ -= sprite * 10;

	if (setNum == 4) {
		isBottomMost_ = true;
		canBeKilled_ = true;
	}
	else isBottomMost_             = false;
	bullet_.setIsActive (isBottomMost_);

	return sprite;
}

void Enemy::draw() { Character::draw (isLive_ ? getSpriteValue() : 2); }

void Enemy::move(Point <float> refCoord)
{
	if (player_->isLiving()) {
		player_->checkCollider(bullet_);
	}
	
	collider_.x = selfCoord_.x + refCoord.x;
	collider_.y = selfCoord_.y + refCoord.y;
	draw();
}

void Enemy::kill()
{
	Character::kill();
	container_->enemyKilled();
}

void Enemy::getSprite(const bool isFirst, const int& setNum)
{
	const int x = 1 + (setNum * 18);
	const int y = isFirst ? 1 : 11;

	sprite_.newCoords ({x, y});
}

void Enemy::setNewBottom()
{
	isBottomMost_ = true;
	canBeKilled_ = true;
	bullet_.setIsActive(isBottomMost_);
	//std::cout << bullet_.memoryAddress_ << " is " << isBottomMost_ << "\n";
}

bool Enemy::canShoot() { return isLive_ && isBottomMost_ ? true : false; }


// Static variables must be declared in the .cpp file
bool EnemyContainer::isForwardMove_;
float EnemyContainer::moveSpeed_ = 8;

EnemyContainer::EnemyContainer (Character& player)
{
	for (int x = 0; x < 11; ++x) {
		for (int y = 0; y < 5; ++y) {
			enemyTest_[x].emplace_back (x * 18, y * 18, y, player);
			setWholeSize (x, y);
		}
	}
	setWholeCoordinate ({glb::DRAW_RESTRICTIONS.x, 100});
}

void EnemyContainer::draw ()
{
	//drawDebugRange();
	drawEnemies();
}

void EnemyContainer::drawDebugRange () const
{
	ofSetColor (ofColor::lavender);
	wholeCollision_.drawRect();
}

void EnemyContainer::drawEnemies ()
{
	for (auto& enemyRow : enemyTest_) {
		for (auto& enemy : enemyRow) enemy.move (wholeCollision_.getXY()); 
	}
}

void EnemyContainer::moveWhole ()
{
	if (ofGetFrameNum() % 30 == 0) {
		isMovingRight();
		isForwardMove_
			? wholeCollision_.x += moveSpeed_
			: wholeCollision_.x -= moveSpeed_;
	}
}

void EnemyContainer::isMovingRight ()
{
	if (wholeCollision_.addXW() >= glb::DRAW_RESTRICTIONS.w) {
		isForwardMove_ = false;
		wholeCollision_.y += 6;
	}
	if (wholeCollision_.x <= glb::DRAW_RESTRICTIONS.x) isForwardMove_ = true;
}

void EnemyContainer::setWholeSize (int rowSize, int columnSize)
{
	wholeCollision_.w += glb::RESIZE_FACTOR * 3.56f;
	wholeCollision_.h += glb::RESIZE_FACTOR + 1.6f;
}

void EnemyContainer::setWholeCoordinate (const Point <float> coordinate)
{
	wholeCollision_.setXY (coordinate);
}

void EnemyContainer::fireEvent ()
{
	constexpr int a1 = 10;
	constexpr int b1 = 4;
	int a = static_cast <int> (round (ofRandom (a1)));
	int b = static_cast <int> (round (ofRandom (b1)));

	if (a > a1) a = a1;
	if (b > b1) b = b1;
	

	if (enemyTest_[a][b].canShoot()) {
		enemyTest_[a][b].fire();
		//std::cout << a << " " << b << "\n";
	}
	else fireEvent();
}

// ENEMY CONTAINER ----------------------

void EnemyContainer::checkForHit()
{
	for (auto& enemyRow : enemyTest_) {
		for (auto& enemy : enemyRow) {
			if (enemy.isBottomMost_) {
				// Make each enemy check player bullet
				const bool isEnemyLive = enemy.checkCollider (Character::player_->bullet_);
				// Make player check each enemy bullet
				const bool isPlayerLive = Character::player_->checkCollider (enemy.bullet_);

				if (!isPlayerLive) Character::player_->kill();
				if (!isEnemyLive && enemy.canBeKilled_) enemy.kill();
			}
		}
	}
}

void EnemyContainer::enemyKilled()
{
	moveSpeed_ += 3;
	for (auto& x : enemyTest_) {
		for (int y = 0; y < x.size(); ++y) {
			if (y != 0 && !x[y].isLiving() && x[y].isBottomMost_) {
				x[y].isBottomMost_ = false;
				x[y].canBeKilled_ = false;
				x[y - 1].setNewBottom();
			}
		}
	}
}

bool EnemyContainer::enemiesLive()
{
	int enemiesAlive = 0;
	for (auto& enemyRow : enemyTest_) {
		for (auto enemy : enemyRow) {
			if (enemy.isLiving()) {
				enemiesAlive++;
			}
		}
	}

	return enemiesAlive == 0 ? false : true;
}

int EnemyContainer::totalEnemies()
{
	int enemies = 0;
	for (auto& enemyRow : enemyTest_) {
		for (auto& enemy : enemyRow) {
			enemies++;
		}
	}
	return enemies;
}

void EnemyContainer::debugKillAllEnemies()
{
	for (auto& enemyRow : enemyTest_) {
		for (auto& enemy : enemyRow) {
			enemy.kill();
		}
	}
}

std::array<std::vector<Enemy>, 11>& EnemyContainer::getAllEnemies()
{
	return enemyTest_;
}

void EnemyContainer::debugPrintStates()
{
	if (ofGetFrameNum() % 30 == 0) {
		for (auto& enemyRow : enemyTest_) {
			for (auto& enemy : enemyRow) {
				std::cout << enemy.isBottomMost_ << ", ";
			}
			std::cout << "\n";
		}
		std::cout << "----\n";
	}
	
}
