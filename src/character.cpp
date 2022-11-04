// ReSharper disable All
#include "character.h"

Character::Character (const float& x, const float& y)
{
	setCoords(x, y, true);
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
