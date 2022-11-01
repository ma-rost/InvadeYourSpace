#pragma once
#include "ofImage.h"
#include "ofGraphics.h"
#include "point.h"

class Player {
	ofImage sprite_;
	bool isLive_;
	Point <float> coordinate_;
	
	int moveSpeed_ {4};

public:
	Player(const float& x, const float& y);
	Player(const Point<float>& coordinate);
	Player(const std::string& avatarFilename, const Point<float>& coordinate);

	void move(bool isRightKey);
	void draw() const;
	
};
