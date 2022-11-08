#pragma once
#include "ofColor.h"
#include "point.h"
#include "sprite.h"

class Destructible {
protected:
	Sprite sprite_;

	ofColor drawColor_{ ofColor::white };

	float moveSpeed_{ 10 };
	Point <float> coordinate_;
	Point <float> drawRestrictions_{ 10, 640 };

	bool isLive_{ true };
public:
	Destructible(const float& x, const float& y);
	Destructible(const float& x, const float& y, const float& moveSpeed);

	void setCoords(const float& x, const float& y, bool applyResize);
	void setCoords(const float& y, bool applyResize);
	int getSpriteValue () const;

	void kill();
	void draw(const int& spriteIndex);
	
};
