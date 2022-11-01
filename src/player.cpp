#include "player.h"


Player::Player (const float& x, const float& y)
{
	coordinate_.x = x;
	coordinate_.y = y;
}

Player::Player(const std::string& avatarFilename, const float& x, const float& y)
{

}

Player::Player (const ofImage& sprite, const float& x, const float& y):
	sprite_ (sprite)
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
	sprite_.draw(coordinate_.x, coordinate_.y);
}

void Player::setSprite(ofImage image)
{
	sprite_.cropFrom(image, 1, 49, 16, 8);
	sprite_.resize(sprite_.getWidth() * resizeFactor_, sprite_.getHeight() * resizeFactor_);
}