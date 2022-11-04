#include "sprite.h"

Sprite::Sprite (const Point<int>& coords, const Point<int>& size): spriteSize_ (size)
{
	newCoords(coords);
}

Sprite::Sprite (const Point<int>& coords):
	Sprite(coords, { 16, 8 })
{}

Sprite::Sprite (const int& x, const int& y):
	Sprite ({ x, y } ,{ 16, 8 })
{}

Sprite::Sprite () :
	Sprite({ 1, 49 }, { 16, 8 })
{}

int Sprite::getResize ()
{
	return RESIZE_FACTOR;
}

void Sprite::clearCoords ()
{
	coordList_.clear();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
void Sprite::drawSprite (const float& x, const float& y)
{
	changeSprite();
	drawnSprite_.draw(x, y);
}

void Sprite::drawSprite (const int& spriteIndex, const float& x, const float& y)
{
	changeSprite(spriteIndex);
	drawnSprite_.draw(x, y);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
void Sprite::debugSpriteVecValue () const
{
	for ( const auto element : coordList_) {
		std::cout << element.x << " " << element.y<< "\n";
	}
	
}

void Sprite::newCoords (const Point<int>& coords)
{
	coordList_.emplace_back(coords);
}

void Sprite::setSize (const Point<int>& size)
{
	spriteSize_ = size;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void Sprite::changeSprite (const int& spriteIndex, const Point<int>& coords, const Point<int>& size)
{
	//drawnSprite_.clear();
	drawnSprite_.cropFrom(spriteSheet_, coordList_[spriteIndex].x, coordList_[spriteIndex].y, size.x, size.y);
	drawnSprite_.resize(drawnSprite_.getWidth() * RESIZE_FACTOR, drawnSprite_.getHeight() * RESIZE_FACTOR);
}

void Sprite::changeSprite (const int& spriteIndex)
{
	changeSprite(spriteIndex, coordList_[spriteIndex], spriteSize_);
}

void Sprite::changeSprite ()
{
	changeSprite(0, coordList_[0], spriteSize_);
}


