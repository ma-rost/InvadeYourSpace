#pragma once

#include "globals.h"
#include "ofColor.h"
#include "point.h"
#include "sprite.h"


class Destructible {
protected:
	Sprite sprite_;
	ofColor drawColor_ {ofColor::white};

	static constexpr float MOVE_SPEED {10};
	Rect <float> collider_;

	bool isLive_ {true};
public:
	Destructible(const float& x, const float& y);

	void kill();
	void draw(const int& spriteIndex);

	void setCoords(const float& x, const float& y, bool applyResize);
	void setCoords(const float& y, bool applyResize);
	static float applyResize(float value);
	static Point <float> applyResize(Point <float> value);
	static int getSpriteValue();

	static float getMoveSpeed() { return MOVE_SPEED; }

	Rect <float> getCollider() const;
	void setCollision();
	void setCollision(Point <float> xy, Point <float> wh);
	void setCollision(const float& x, const float& y, const float& w,
	                  const float& h);
};
