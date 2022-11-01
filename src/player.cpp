#include "player.h"

Player::Player (const float& x, const float& y):Character (x,y)
{
	for ( int i = 0; i < 3; ++i ) setSprites ({1 + (i * 18), 49}); 
}

void Player::move (bool isRightKey)
{
	isRightKey ? coordinate_.x += moveSpeed_:
				 coordinate_.x -= moveSpeed_;
}

void Player::draw () const
{
	ofSetColor(ofColor::green);

	if (isLive_) {
		sprites_[getSpriteValue() + 1].draw(coordinate_.x, coordinate_.y);
	}
	else {
		sprites_[0].draw(coordinate_.x, coordinate_.y);
	}
	
}

void Player::kill ()
{
	isLive_ = isLive_ ? false : true;
}
