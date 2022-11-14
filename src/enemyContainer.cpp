#include "enemyContainer.h"

#include "ofGraphics.h"


// Static variables must be declared in the .cpp file

Point<float> EnemyContainer::wholeCoordinate_; // The coordinate of the first enemy
Point<float> EnemyContainer::wholeSize_; // The size of all of the enemies compiled into one
bool EnemyContainer::isForwardMove_;

EnemyContainer::EnemyContainer ()
{

}

void EnemyContainer::isMovingRight ()
{
	//std::cout << wholeCoordinate_.x << ", " << wholeCoordinate_.x + wholeSize_.x << std::endl;
	if (wholeCoordinate_.x + wholeSize_.x >= glb::DRAW_RESTRICTIONS.y) {
		isForwardMove_ = false;

		if (ofGetFrameNum() % 4 == 0) wholeCoordinate_.y += 3;
	}
	if (wholeCoordinate_.x <= glb::DRAW_RESTRICTIONS.x) isForwardMove_ = true;
}

void EnemyContainer::setWholeSize (int rowSize, int columnSize)
{
	wholeSize_.x += 10.7;
	wholeSize_.y += 4.4;

	//std::cout << wholeSize_.x << ", " << wholeSize_.y << std::endl;
}

void EnemyContainer::setWholeCoordinate (const Point<float> coordinate)
{
	wholeCoordinate_ = coordinate;
}

void EnemyContainer::drawDebugRange ()
{
	ofSetColor(ofColor::lavender);
	ofDrawRectangle(wholeCoordinate_.x, wholeCoordinate_.y, wholeSize_.x, wholeSize_.y);
}

void EnemyContainer::moveWhole ()
{
	isMovingRight();
	if (ofGetFrameNum() % 6 == 0) {
		isForwardMove_ ? wholeCoordinate_.x += MOVE_SPEED : wholeCoordinate_.x -= MOVE_SPEED;
	}
	drawDebugRange();
}
