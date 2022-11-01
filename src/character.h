#pragma once
#include "ofImage.h"
#include "point.h"

class Character {
	const int resizeFactor_{ 3 };
protected:
	ofImage spriteSheet{ "spaceInvaders_spriteSheet.png" };
	std::vector<ofImage>sprites_;
	bool isLive_;
	Point <float> coordinate_;
public:
	Character(const float& x, const float& y);
	
	void setSprites(const ofImage& image, const Point<int>& coords, const Point<int>& size);
	void setSprites(const ofImage& image, const Point<int>& coords);
};
