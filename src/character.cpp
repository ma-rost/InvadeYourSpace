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

int Character::getSpriteValue() const
{
	constexpr int frameRate = 60;
	return ofGetFrameNum() % frameRate < frameRate / 2 ? 0 : 1;
}

void Character::kill ()
{
	
}

void Character::draw (const int& spriteIndex)
{
	ofSetColor(drawColor_);
	sprite_.drawSprite(spriteIndex, coordinate_.x, coordinate_.y);
}

void Character::move ()
{

}


