#pragma once

#include "ofImage.h"
#include "point.h"
#include "ofGraphics.h"

class Character {
	const int resizeFactor_{3};
protected:
	ofImage spriteSheet_{"spaceInvaders_spriteSheet.png"};
	std::vector <ofImage> sprites_;
	Point <int> defaultSize_{16, 8};

	Point <float> coordinate_;
	Point <float> drawRestrictions_{50, 600};

	bool isLive_{true};

public:
	Character (const float& x, const float& y);

	void setSprites (const Point <int>& coords, const Point <int>& size);
	void setSprites (const Point <int>& coords);

	void setCoords (const float& x, const float& y, bool applyResize);
	void setCoords (const float& y, bool applyResize);

	int getSpriteValue () const;
};
