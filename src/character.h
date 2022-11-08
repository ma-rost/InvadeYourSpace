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
	Point <float> bulletSpawn_;

	bool isLive_{true};
public:
	Character (const float& x, const float& y);
	Character(const float& x, const float& y, const float& moveSpeed);

	void setCoords (const float& x, const float& y, bool applyResize);
	void setCoords (const float& y, bool applyResize);

	void setBulletSpawn(const bool& isPlayer);

	int getSpriteValue () const;

	void kill();
	void draw(const int& spriteIndex);
	void move(const bool& isMoveRight);
	void fire();

	Character& operator++ ();
	Character  operator++ (int);
	Character& operator-- ();
	Character  operator-- (int);
};


