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
