#include "player.h"

#include "ofGraphics.h"

Player::Player (const float& x, const float& y):
	Character (x, y)
{
	drawColor_ = ofColor::green;
	for ( int i = 1; i < 3; ++i ) {
		sprite_.newCoords({ 1 + (i * 18), 49 });
	}
}

void Player::move (bool isRightKey)
{
	if ( isLive_ ) {
		Character::move(isRightKey);
		coordinate_.x = ofClamp (coordinate_.x, drawRestrictions_.x,
													drawRestrictions_.y);
	}
}

void Player::draw ()
{
	Character::draw(isLive_ ? 0 : getSpriteValue() + 1);
	setBulletSpawn(true);
}

void Player::kill () { isLive_ = isLive_ ? false : true; }

void Player::shoot ()
{
	
}