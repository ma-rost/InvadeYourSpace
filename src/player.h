#pragma once
#include <utility>

#include "ofImage.h"
#include "ofGraphics.h"
#include "point.h"


class Player {
	std::vector<ofImage>sprites_;
	bool isLive_;
	Point <float> coordinate_;
	
	const float moveSpeed_ {10};
	const int resizeFactor_ {3};

public:
	Player(const float& x, const float& y);
	Player(const ofImage& sprite, const float& x, const float& y);

	
	void move(bool isRightKey);
	void draw() const;
	void setSprites(const ofImage& image, const Point<int>& coords, const Point<int>& size);
private:
};


