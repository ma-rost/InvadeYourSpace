#pragma once
#include "globals.h"
#include "ofImage.h"
#include "point.h"

class Sprite {
	ofImage spriteSheet_{ "spaceInvaders_spriteSheet.png" };
	Point <int> spriteSize_;
	std::vector <Point<int>> coordList_;
public:
	ofImage drawnSprite_;

	Sprite(const Point <int>& coords, const Point <int>& size) :
		spriteSize_(size) {
		newCoords(coords);
	}
	Sprite(const Point <int>& coords) :
		Sprite(coords, { 16, 8 }) {}
	Sprite(const int& x, const int& y) :
		Sprite({ x, y }, { 16, 8 }) {}
	Sprite() :
		Sprite({ 1, 49 }, { 16, 8 }) {}

	void debugSpriteVecValue() const;
	static float getResize() { return glb::RESIZE_FACTOR; }
	void clearCoords() { coordList_.clear(); }
	void newCoords(const Point<int>& coords) { coordList_.emplace_back(coords); }
	void setSize(const Point<int>& size) { spriteSize_ = size; }

	Point<float> getSize() const
	{
		return { drawnSprite_.getWidth(), drawnSprite_.getHeight() };
	}

	// Animation ------------------------------------------------------
	void changeSprite(const int& spriteIndex, const Point<int>& coords, const Point<int>& size);
	void changeSprite(const int& spriteIndex)
	{
		changeSprite(spriteIndex, coordList_[spriteIndex], spriteSize_);
	}
	void changeSprite()
	{
		changeSprite(0, coordList_[0], spriteSize_);
	}
	// Draw Sprite ----------------------------------------------------
	void drawSprite(const float& x, const float& y);
	void drawSprite(const int& spriteIndex, const float& x, const float& y);


};
//Set new sprite. 
