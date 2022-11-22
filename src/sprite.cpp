#include "sprite.h"
void Sprite::changeSprite(const int& spriteIndex, const Point<int>& coords,
                          const Point<int>& size)
{
	//drawnSprite_.clear();
	drawnSprite_.cropFrom(spriteSheet_, coordList_[spriteIndex].x,
	                      coordList_[spriteIndex].y, size.x, size.y);
	drawnSprite_.resize(drawnSprite_.getWidth() * glb::RESIZE_FACTOR,
	                    drawnSprite_.getHeight() * glb::RESIZE_FACTOR);
}

// Draw Sprite ----------------------------------------------------
void Sprite::drawSprite(const float& x, const float& y)
{
	changeSprite();
	drawnSprite_.draw(x, y);
}

void Sprite::drawSprite(const int& spriteIndex, const float& x, const float& y)
{
	changeSprite(spriteIndex);
	drawnSprite_.draw(x, y);
}
