#include "destructible.h"
#include "ofGraphics.h"


Destructible::Destructible (const float& x, const float& y)
{
	setCoords(x, y, true);
}

void Destructible::setCoords (const float& x, const float& y, const bool applyResize)
{
	collider_.x = applyResize ? x * Sprite::getResize() : x;
	collider_.y = applyResize ? y * Sprite::getResize() : y;


}

void Destructible::setCoords (const float& y, bool applyResize)
{
	collider_.y = applyResize ? y * Sprite::getResize() : y;
}

float Destructible::applyResize (float value)
{
	return value * Sprite::getResize();
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
	sprite_.drawSprite(spriteIndex, collider_.x, collider_.y);
}

void Destructible::setCollision ()
{
	setCollision(collider_.x, collider_.y, sprite_.getSize().x, sprite_.getSize().y);
}

void Destructible::setCollision(const float& x, const float& y, const float& w, const float& h)
{
	setCollision({ x,y }, { w,h });
}

void Destructible::setCollision (Point<float> xy, Point<float> wh)
{
	collider_.setXY(xy);
	collider_.setWH(wh);
}


