#include "player.h"

Player::Player (const float& x, const float& y):
	Character (x, y)
{
	for ( int i = 1; i < 3; ++i ) {
		sprite_.newCoords({ 1 + (i * 18), 49 });
	}
}

void Player::move (bool isRightKey)
{
	if ( isLive_ ) {
		isRightKey ? ++*this : --*this;
		coordinate_.x = ofClamp (coordinate_.x, drawRestrictions_.x,
													drawRestrictions_.y);
	}
}

void Player::draw ()
{
	ofSetColor (ofColor::green);

	/*if ( isLive_ )  sprites_[0].drawSprite (coordinate_.x, coordinate_.y); 
	else  sprites_[getSpriteValue() + 1].drawSprite (coordinate_.x, coordinate_.y); */

	if (isLive_)  sprite_.drawSprite(0, coordinate_.x, coordinate_.y);
	else  sprite_.drawSprite(getSpriteValue() + 1, coordinate_.x, coordinate_.y);
}

void Player::kill () { isLive_ = isLive_ ? false : true; }

void Player::shoot ()
{

}

Player& Player::operator++ ()
{
	this->coordinate_.x += this->moveSpeed_;
	return *this;
}

Player Player::operator++ (int)  // postfix ++
{
	Player result(*this);   // make a copy for result
	++(*this);              // Now use the prefix version to do the work
	return result;          // return the copy (the old) value.
}

Player& Player::operator-- ()
{
	this->coordinate_.x -= this->moveSpeed_;
	return *this;
}

Player Player::operator-- (int)
{
	Player result(*this);   // make a copy for result
	--(*this);              // Now use the prefix version to do the work
	return result;          // return the copy (the old) value.
}