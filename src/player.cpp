#include "player.h"

Player::Player (const float& x, const float& y):
	Character (x, y)
{
	for ( int i = 0; i < 3; ++i ) setSprites ({1 + (i * 18), 49});
}

void Player::move (bool isRightKey)
{
	if ( isLive_ ) {
		isRightKey ? coordinate_.x += moveSpeed_ : coordinate_.x -= moveSpeed_;
		coordinate_.x = ofClamp (coordinate_.x, drawRestrictions_.x,
													drawRestrictions_.y);
	}
}

void Player::draw () const
{
	ofSetColor (ofColor::green);

	if ( isLive_ )  sprites_[0].draw (coordinate_.x, coordinate_.y); 
	else  sprites_[getSpriteValue() + 1].draw (coordinate_.x, coordinate_.y); 
}

void Player::kill () { isLive_ = isLive_ ? false : true; }
