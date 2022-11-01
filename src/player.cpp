#include "player.h"


Player::Player (const float& x, const float& y)
{
	coordinate_.x = x;
	coordinate_.y = y;
}

Player::Player (const Point<float>& coordinate):
coordinate_(coordinate)
{
}

Player::Player (const std::string& avatarFilename, const Point<float>& coordinate):
	coordinate_(coordinate)
{
	//sprite.load(avatarFilename);
}

void Player::move (bool isRightKey)
{
	isRightKey ? coordinate_.x += moveSpeed_:
				 coordinate_.x -= moveSpeed_;
}

void Player::draw () const
{
	ofSetColor(ofColor::white);
	ofDrawRectangle(coordinate_.x, coordinate_.y, 16, 8);
}
