// ReSharper disable All
#include "character.h"
#include "ofGraphics.h"

Character::Character (const float& x, const float& y)
{

	setCoords(x, y, true);
}

Character::Character (const float& x, const float& y, const float& moveSpeed):
	Character (x,y)
{
	moveSpeed_ = moveSpeed;
}

void Character::setColor (const ofColor& color)
{
	drawColor_ = color;
}

void Character::setCoords (const float& x, const float& y, bool applyResize)
{
	coordinate_.x = applyResize ? x * Sprite::getResize() : x;
	coordinate_.y = applyResize ? y * Sprite::getResize() : y;
}

void Character::setCoords (const float& y, bool applyResize)
{
	coordinate_.y = applyResize ? y * Sprite::getResize() : y;
}

void Character::setBulletSpawn(const bool& isPlayer)
{
	ofSetColor(ofColor::white);
	bulletSpawn_.x = coordinate_.x + sprite_.getSize().x / 2;

	if (isPlayer) {
		bulletSpawn_.y = coordinate_.y - sprite_.getSize().y / 2 - 5;
	}
	else {
		bulletSpawn_.x-= 1; // Bullet not centered on enemies
		bulletSpawn_.y = coordinate_.y + sprite_.getSize().y / 2 + 20;
	}

	ofDrawRectangle(bulletSpawn_.x, bulletSpawn_.y, 4, 4);
}

int Character::getSpriteValue() const
{
	constexpr int frameRate = 60;
	return ofGetFrameNum() % frameRate < frameRate / 2 ? 0 : 1;
}

void Character::kill ()
{
	
}

void Character::draw (const int& spriteIndex, const bool& isPlayer)
{
	ofSetColor(drawColor_);
	sprite_.drawSprite(spriteIndex, coordinate_.x, coordinate_.y);
	setBulletSpawn(isPlayer);

}

void Character::move (const bool& isMoveRight)
{
	isMoveRight ? ++* this : --* this;
}

Character& Character::operator++ ()
{
	this->coordinate_.x += this->moveSpeed_;
	return *this;
}

Character  Character::operator++ (int)
{
	Character result(*this);   // make a copy for result
	++(*this);              // Now use the prefix version to do the work
	return result;          // return the copy (the old) value.
}

Character& Character::operator-- ()
{
	this->coordinate_.x -= this->moveSpeed_;
	return *this;
}
Character  Character::operator-- (int)
{
	Character result(*this);   // make a copy for result
	--(*this);              // Now use the prefix version to do the work
	return result;          // return the copy (the old) value.
}
