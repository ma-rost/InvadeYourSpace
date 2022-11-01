// ReSharper disable All
#include "character.h"

Character::Character (const float& x, const float& y)
{
	setCoords(x, y, true);
}

void Character::setSprites (const ofImage& image, const Point<int>& coords,
	const Point<int>& size)
{
	ofImage newImage;
	newImage.cropFrom(image, coords.x, coords.y, size.x, size.y);
	newImage.resize(newImage.getWidth() * resizeFactor_, newImage.getHeight() * resizeFactor_);
	sprites_.emplace_back(newImage);
}

void Character::setSprites (const ofImage& image, const Point<int>& coords)
{
	setSprites(image, coords, defaultSize);
}

void Character::setSprites (const Point<int>& coords)
{
	setSprites(spriteSheet, coords, defaultSize);
}

void Character::setCoords (const float& x, const float& y, bool applyResize)
{
	coordinate_.x = applyResize ? x * resizeFactor_ : x;
	coordinate_.y = applyResize ? y * resizeFactor_ : y;
}

void Character::setCoords (const float& y, bool applyResize)
{
	coordinate_.y = applyResize ? y * resizeFactor_ : y;
}

int Character::getSpriteValue () const
{
	constexpr int frameRate = 60;
	return ofGetFrameNum() % frameRate < frameRate / 2 ? 0 : 1;
}
