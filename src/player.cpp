#include "player.h"


Player::Player (const float& x, const float& y)
{
	coordinate_.x = x;
	coordinate_.y = y;
}

Player::Player (const ofImage& sprite, const float& x, const float& y):
	sprite_ (sprite)
{
	coordinate_.x = x;
	coordinate_.y = y;
}

void Player::move (bool isRightKey)
{
	isRightKey ? coordinate_.x += moveSpeed_:
				 coordinate_.x -= moveSpeed_;
}

void Player::draw () const
{
	ofSetColor(ofColor::green);
	switch ( isLive_ ) {
		case true: 
			for ( int i = 0; i < 6; ++i ) {
				sprites_[1].draw(coordinate_.x, coordinate_.y);
				Sleep(10);
				sprites_[2].draw(coordinate_.x, coordinate_.y);
				Sleep(10);
			}
			break;
		default:
			sprites_[0].draw(coordinate_.x, coordinate_.y);
			break;
	}
	
}

void Player::setSprites (const ofImage& image, const Point<int>& coords, const Point<int>& size)
{
	ofImage newImage;
	newImage.cropFrom(image, coords.x, coords.y, size.x, size.y);
	newImage.resize(newImage.getWidth() * resizeFactor_, newImage.getHeight() * resizeFactor_);
	sprites_.emplace_back(newImage);
}
