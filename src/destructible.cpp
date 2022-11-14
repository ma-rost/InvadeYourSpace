#include "destructible.h"
#include "ofGraphics.h"


Destructible::Destructible (const float& x, const float& y)
{
	setCoords(x, y, true);
}

void Destructible::setCoords (const float& x, const float& y, const bool applyResize)
{
	coordinate_.x = applyResize ? x * Sprite::getResize() : x;
	coordinate_.y = applyResize ? y * Sprite::getResize() : y;
}

void Destructible::setCoords (const float& y, bool applyResize)
{
	coordinate_.y = applyResize ? y * Sprite::getResize() : y;
}

int Destructible::getSpriteValue() const
{
	constexpr int frameRate = 60;
	return ofGetFrameNum() % frameRate < frameRate / 2 ? 0 : 1;
}

void Destructible::kill ()
{
	isLive_ = false;
}

void Destructible::draw (const int& spriteIndex)
{
	ofSetColor(drawColor_);
	sprite_.drawSprite(spriteIndex, coordinate_.x, coordinate_.y);
}
