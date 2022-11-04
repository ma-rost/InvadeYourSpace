#pragma once

#include "ofImage.h"
#include "point.h"
#include "ofGraphics.h"
#include "sprite.h"

class Character {
	const int resizeFactor_{3};
protected:
	ofImage spriteSheet_{"spaceInvaders_spriteSheet.png"};
	std::vector <Sprite> sprites_;
	Point <int> defaultSize_{16, 8};

	Point <float> coordinate_;
	Point <float> drawRestrictions_{50, 600};

	bool isLive_{true};


public:
	Character (const float& x, const float& y);

	void setCoords (const float& x, const float& y, bool applyResize);
	void setCoords (const float& y, bool applyResize);

	int getSpriteValue () const;
};
