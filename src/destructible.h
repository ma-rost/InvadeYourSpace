#pragma once
#include "ofColor.h"
#include "point.h"
#include "sprite.h"

class Destructible {
protected:
	Sprite sprite_;

	ofColor drawColor_{ ofColor::white };

	static float moveSpeed_;
	Point <float> coordinate_;
	static constexpr Point <float> DRAW_RESTRICTIONS{ 10, 640 };

	bool isLive_{ true };
public:
	Destructible(const float& x, const float& y);

	void setCoords(const float& x, const float& y, bool applyResize);
	void setCoords(const float& y, bool applyResize);
	int getSpriteValue () const;

	void kill();
	void draw(const int& spriteIndex);

	static float getMoveSpeed()
	{
		return moveSpeed_;
	}
	
};
