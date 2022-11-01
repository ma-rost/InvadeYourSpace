// ReSharper disable All
#include "character.h"

Character::Character (const float& x, const float& y)
{
	coordinate_.x = x;
	coordinate_.y = y;
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
	setSprites(image, coords, { 16, 8 });
}

void Character::setSprites (const Point<int>& coords)
{
	setSprites(spriteSheet, coords, { 16, 8 });
}

int Character::getSpriteValue () const
{
	constexpr int frameRate = 60;
	return ofGetFrameNum() % frameRate < frameRate / 2 ? 0 : 1;
}
