#pragma once

#include "ofImage.h"
#include "point.h"
#include "ofGraphics.h"
#include "sprite.h"

class Character {
protected:
	Sprite sprite_;

	Point <float> coordinate_;
	Point <float> drawRestrictions_{10, 600};

	bool isLive_{true};
public:
	Character (const float& x, const float& y);

	void setCoords (const float& x, const float& y, bool applyResize);
	void setCoords (const float& y, bool applyResize);

	int getSpriteValue () const;


};
