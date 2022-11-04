#include "sprite.h"

Sprite::Sprite (const Point<int>& coords, const Point<int>& size): spriteSize_ (size)
{
	newCoords(coords);
	changeSprite(0, coords);
}

Sprite::Sprite (const Point<int>& coords):
	Sprite(coords, charSize_)
{

}

Sprite::Sprite (const int& x, const int& y):
	Sprite ({ 16, 8 }, charSize_)
{

}

void Sprite::drawSprite (const float& x, const float& y)
{
	changeSprite();
	drawnSprite_.draw(x, y);
}

void Sprite::drawSprite (int& spriteIndex, const float& x, const float& y)
{
	changeSprite(spriteIndex);
	drawnSprite_.draw(x, y);
}

void Sprite::debugSpriteVecValue () const
{
	std::cout << spriteList_.size();
}

void Sprite::newSprite (const Point<int>& coords, const Point<int>& size)
{
	ofImage newImage;
	newImage.cropFrom(spriteSheet_, coords.x, coords.y, size.x, size.y);
	newImage.resize(newImage.getWidth() * resizeFactor_, newImage.getHeight() * resizeFactor_);
	spriteList_.emplace_back(newImage);
}

void Sprite::newSprite (const Point<int>& coords)
{
	newSprite(coords, charSize_);
}

void Sprite::newCoords (const Point<int>& coords)
{
	coordList_.emplace_back(coords);
}

void Sprite::changeSprite (const int& spriteIndex, const Point<int>& coords, const Point<int>& size)
{
	drawnSprite_.clear();
	drawnSprite_.cropFrom(spriteSheet_, coordList_[spriteIndex].x, coordList_[spriteIndex].y, size.x, size.y);
	drawnSprite_.resize(drawnSprite_.getWidth() * resizeFactor_, drawnSprite_.getHeight() * resizeFactor_);

	debugSpriteVecValue();
}

void Sprite::changeSprite (const int& spriteIndex, const Point<int>& coords)
{
	changeSprite(spriteIndex, coords, spriteSize_);
}

void Sprite::changeSprite (const int& spriteIndex)
{
	changeSprite(spriteIndex, coordList_[spriteIndex]);
}

void Sprite::changeSprite ()
{
	changeSprite(0, coordList_[0]);
}
