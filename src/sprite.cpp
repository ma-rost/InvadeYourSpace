#include "sprite.h"

Sprite::Sprite (Point<int> coords, Point<int> size)
{
	newSprite(coords, size);
}

Sprite::Sprite (Point<int> coords): Sprite(coords, { 16, 8 })
{

}

int Sprite::getSpriteValue () const
{
	constexpr int frameRate = 60;
	return ofGetFrameNum() % frameRate < frameRate / 2 ? 0 : 1;
}

void Sprite::newSprite (Point<int> coords, Point<int> size)
{
	ofImage newImage;
	newImage.cropFrom(spriteSheet_, coords.x, coords.y, size.x, size.y);
	newImage.resize(newImage.getWidth() * resizeFactor_, newImage.getHeight() * resizeFactor_);
	sprites_.emplace_back(newImage);
}

void Sprite::changeSprite (int spriteIndex)
{


}
