#include "player.h"

#include "enemyContainer.h"

Player::Player(const float& x, const float& y):
	Character (x, y, true)
{
	drawColor_ = ofColor::green;
	for (int i = 1; i < 3; ++i) sprite_.newCoords ({1 + (i * 18), 49});
}

void Player::move(const bool isRightKey)
{
	if (isLive_) {
		container_->checkForHit(bullet_);
		Character::move (isRightKey);
		collider_.x = ofClamp (collider_.x, glb::DRAW_RESTRICTIONS.x,
		                       glb::DRAW_RESTRICTIONS.y - 16 * 3);
	}
}

void Player::draw() { Character::draw (isLive_ ? 0 : getSpriteValue() + 1); }

void Player::kill() { isLive_ = isLive_ ? false : true; }

void Player::killEnemy()
{
	score_ += 30;
	printDigits();
}

int Player::getScore()
{
	return 0;
}

void Player::getDigits(int x)
{
	if (x >= 10)
		getDigits(x / 10);

	int digit = x % 10;
	
	std::vector<int> numbers;
	numbers.emplace_back(digit);

	for (auto number : numbers) {
		std::cout << digit;
	}
}

void Player::printDigits()
{
	std::array<int, 4> numbers;
	getDigits(score_);
	std::cout << '\n';
}
