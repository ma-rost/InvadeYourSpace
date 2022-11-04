#pragma once
#include "ofImage.h"
#include "point.h"

class Sprite {
	const int resizeFactor_{ 3 };
	ofImage spriteSheet_{ "spaceInvaders_spriteSheet.png" };
public:
	std::vector <ofImage> sprites_;

	Sprite(Point<int> coords, Point<int> size);
	Sprite(Point<int> coords);

	int getSpriteValue() const;
	void newSprite(Point<int> coords, Point<int> size);
	void changeSprite(int spriteIndex);
};
