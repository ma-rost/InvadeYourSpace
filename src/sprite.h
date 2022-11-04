#pragma once
#include "ofImage.h"
#include "point.h"

class Sprite {
	static constexpr int RESIZE_FACTOR{ 3 };
	ofImage spriteSheet_{ "spaceInvaders_spriteSheet.png" };
	Point <int> spriteSize_;
	std::vector <Point<int>> coordList_;
public:
	ofImage drawnSprite_;

	Sprite(const Point<int>& coords, const Point<int>& size);
	Sprite(const Point<int>& coords);
	Sprite(const int& x, const int& y);
	Sprite();

	static int getResize();
	void debugSpriteVecValue() const;

	void clearCoords();
	void newCoords(const Point<int>& coords);

	// Animation
	void changeSprite(const int& spriteIndex, const Point<int>& coords, const Point<int>& size);
	void changeSprite(const int& spriteIndex);
	void changeSprite();
	
	void drawSprite(const float& x, const float& y);
	void drawSprite(const int& spriteIndex, const float& x, const float& y);

	
};

//Set new sprite. 
