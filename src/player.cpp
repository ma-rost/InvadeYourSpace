#include "player.h"

Player::Player(const float& x, const float& y):
	Character (x, y, true)
{
	drawColor_ = ofColor::green;
	for (int i = 1; i < 3; ++i) sprite_.newCoords ({1 + (i * 18), 49});
}

void Player::move(const bool isRightKey)
{
	if (isLive_) {
		Character::move (isRightKey);
		collider_.x = ofClamp (collider_.x, glb::DRAW_RESTRICTIONS.x,
		                       glb::DRAW_RESTRICTIONS.y - 16 * 3);
	}
}

void Player::draw() { Character::draw (isLive_ ? 0 : getSpriteValue() + 1); }

void Player::kill() { isLive_ = isLive_ ? false : true; }
