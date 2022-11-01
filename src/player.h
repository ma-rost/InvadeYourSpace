#pragma once
#include <utility>

#include "ofImage.h"
#include "ofGraphics.h"
#include "point.h"

class Player {
	ofImage sprite_;
	ofTexture test_;
	bool isLive_;
	Point <float> coordinate_;
	
	float moveSpeed_ {10};
	int resizeFactor_ {3};

public:
	Player(const float& x, const float& y);
	Player(const std::string& avatarFilename, const float& x, const float& y);
	Player(const ofImage& sprite, const float& x, const float& y);

	Player(const Point<float>& coordinate);
	Player(const std::string& avatarFilename, const Point<float>& coordinate);

	void setSprite(ofImage image);
	void move(bool isRightKey);
	void draw() const;
private:
};


