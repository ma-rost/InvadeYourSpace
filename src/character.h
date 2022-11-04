#pragma once

#include "point.h"
#include "sprite.h"

class Character {
protected:
	Sprite sprite_;

	ofColor drawColor_{ ofColor::white };

	float moveSpeed_{ 10 };
	Point <float> coordinate_;
	Point <float> drawRestrictions_{10, 640};

	bool isLive_{true};
public:
	Character (const float& x, const float& y);
	Character(const float& x, const float& y, const float& moveSpeed);

	void setColor(const ofColor& color);

	void setCoords (const float& x, const float& y, bool applyResize);
	void setCoords (const float& y, bool applyResize);

	int getSpriteValue () const;

	void kill();
	void draw(const int& spriteIndex);
	void move();
};
