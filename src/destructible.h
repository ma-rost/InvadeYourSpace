#pragma once
#include "ofColor.h"
#include "point.h"
#include "sprite.h"

class Destructible {
protected:
	Sprite sprite_;

	ofColor drawColor_{ ofColor::white };

	static constexpr float MOVE_SPEED{ 10 };
	Point <float> coordinate_;
	static constexpr Point <float> DRAW_RESTRICTIONS{ 20, 670 };

	bool isLive_{ true };
public:
	Destructible(const float& x, const float& y);

	void setCoords(const float& x, const float& y, bool applyResize);
	void setCoords(const float& y, bool applyResize);
	float applyResize(float value);
	int getSpriteValue () const;

	void kill();
	void draw(const int& spriteIndex);

	static float getMoveSpeed() { return MOVE_SPEED;}
};
