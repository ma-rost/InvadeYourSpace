#include "enemyContainer.h"

// Static variables must be declared in the .cpp file
bool EnemyContainer::isForwardMove_;

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
		for (auto& enemy : enemyRow) { enemy.move (wholeCollision_.getXY()); }
	}
}

void EnemyContainer::moveWhole ()
{
	if (ofGetFrameNum() % 30 == 0) {
		isMovingRight();
		isForwardMove_
			? wholeCollision_.x += MOVE_SPEED
			: wholeCollision_.x -= MOVE_SPEED;
	}
	draw();

	if (ofGetFrameNum() % 60 == 0) fireEvent();
}

void EnemyContainer::isMovingRight ()
{
	if (wholeCollision_.addXW() >= glb::DRAW_RESTRICTIONS.y) {
		isForwardMove_ = false;
		wholeCollision_.y += 3;
	}
	if (wholeCollision_.x <= glb::DRAW_RESTRICTIONS.x) isForwardMove_ = true;
}

void EnemyContainer::setWholeSize (int rowSize, int columnSize)
{
	wholeCollision_.w += glb::RESIZE_FACTOR * 3.56f;
	wholeCollision_.h += glb::RESIZE_FACTOR + 2;
}

void EnemyContainer::setWholeCoordinate (const Point <float> coordinate)
{
	wholeCollision_.setXY (coordinate);
}

void EnemyContainer::fireEvent ()
{
	const int a = static_cast <int> (round (ofRandom (10)));
	const int b = static_cast <int> (round (ofRandom (4)));

	if (enemyTest_[a][b].canShoot()) {
		enemyTest_[a][b].fire();
		std::cout << a << " " << b << "\n";
	}
	else fireEvent();
}



void EnemyContainer::checkForHit()
{
	for (auto& enemyRow : enemyTest_) {
		for (auto& enemy : enemyRow) {
			if (enemy.isBottomMost_) {
				// Make each enemy check player bullet
				const bool isEnemyLive = enemy.checkCollider (Character::player_->bullet_);
				// Make player check each enemy bullet
				const bool isPlayerLive = Character::player_->checkCollider (enemy.bullet_);

				if (!isEnemyLive) newBottomEnemy();
			}
		}
	}
}

void EnemyContainer::newBottomEnemy()
{
	for (auto& x : enemyTest_) {
		for (int y = 0; y < x.size(); ++y) {
			if (y != 0 && !x[y].isLiving() && x[y].isBottomMost_) {
				x[y].isBottomMost_ = false;
				x[y - 1].setNewBottom();
			}
		}
	}
}

bool EnemyContainer::allEnemiesLive()
{
	int enemiesAlive = 0;
	for (auto& enemyRow : enemyTest_) {
		for (auto enemy : enemyRow) {
			if (enemy.isLiving()) {
				enemiesAlive++;
			}
		}
	}

	return enemiesAlive >= 0 ? true : false;
}

int EnemyContainer::totalEnemies()
{
	int enemies = 0;
	for (auto& enemyRow : enemyTest_) {
		for (auto enemy : enemyRow) {
			enemies++;
		}
	}
	return enemies;
}

std::array<std::vector<Enemy>, 11>& EnemyContainer::getAllEnemies()
{
	return enemyTest_;
}
