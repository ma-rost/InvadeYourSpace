#pragma once
#include "ofImage.h"
#include "point.h"

class Sprite {
	const int resizeFactor_{ 3 };
	ofImage spriteSheet_{ "spaceInvaders_spriteSheet.png" };
	const Point <int> charSize_{ 16, 8 };
	Point <int> spriteSize_;
public:
	ofImage drawnSprite_;
	std::vector <Point<int>> coordList_;
	std::vector <ofImage> spriteList_;

	Sprite(const Point<int>& coords, const Point<int>& size);
	Sprite(const Point<int>& coords);
	Sprite(const int& x, const int& y);

	void newSprite(const Point<int>& coords, const Point<int>& size);
	void newSprite(const Point<int>& coords);

	void newCoords(const Point<int>& coords);

	// Animation
	void changeSprite(const int& spriteIndex, const Point<int>& coords, const Point<int>& size);
	void changeSprite(const int& spriteIndex, const Point<int>& coords);
	void changeSprite(const int& spriteIndex);
	void changeSprite();

	void drawSprite(const float& x, const float& y);
	void drawSprite(int& spriteIndex, const float& x, const float& y);

	void debugSpriteVecValue() const;
};

//Set new sprite. 
