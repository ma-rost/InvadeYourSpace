#include "enemyContainer.h"

// Static variables must be declared in the .cpp file
bool EnemyContainer::isForwardMove_;

EnemyContainer::EnemyContainer (Character& player)
{
	for (int x = 0; x < 11; ++x) {
		for (int y = 0; y < 5; ++y) {
			enemyTest_[x].emplace_back(x * 18, y * 18, y, player);
			setWholeSize(x, y);
		}
	}

	setWholeCoordinate({ glb::draw_restrictions.x, 10 });
}

void EnemyContainer::draw ()
{
	drawDebugRange();
	drawEnemies();
}

void EnemyContainer::drawDebugRange() const
{
	ofSetColor(ofColor::lavender);
	ofDrawRectangle(wholeCollision_.x, wholeCollision_.y, wholeCollision_.w, wholeCollision_.h);
}

void EnemyContainer::drawEnemies()
{
	for (auto& enemyRow : enemyTest_) {
		for (auto& enemy : enemyRow) {
			enemy.move(wholeCollision_.getXY());
		}
	}
}

void EnemyContainer::moveWhole()
{
	if (ofGetFrameNum() % 30 == 0) {
		isMovingRight();
		isForwardMove_ ? wholeCollision_.x += MOVE_SPEED : wholeCollision_.x -= MOVE_SPEED;
	}
	drawDebugRange();
	drawEnemies();

	if (ofGetFrameNum() % 60 == 0) makeShoot();
	
}

void EnemyContainer::isMovingRight()
{
	if (wholeCollision_.addXW() >= glb::draw_restrictions.y) {
		isForwardMove_ = false;
		wholeCollision_.y += 3;
	}
	if (wholeCollision_.x <= glb::draw_restrictions.x) isForwardMove_ = true;
}

void EnemyContainer::setWholeSize (int rowSize, int columnSize)
{
	wholeCollision_.w += 10.7;
	wholeCollision_.h += 4.4;

	//std::cout << wholeSize_.x << ", " << wholeSize_.y << std::endl;
}

void EnemyContainer::setWholeCoordinate (const Point<float> coordinate)
{
	wholeCollision_.setXY(coordinate);
}

void EnemyContainer::makeShoot ()
{
	const int a = static_cast<int>(round(ofRandom(10)));
	const int b = static_cast<int>(round(ofRandom(4)));
	
	if (enemyTest_[a][b].canShoot()) enemyTest_[a][b].fire();
	else makeShoot ();
}


