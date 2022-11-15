#pragma once
#include "character.h"

// THINGS TO DO /////
// - Make enemies move down when hitting right side
//		- only rightmost enemies slide down
// - Only bottom most enemy has (Working) bullets
//		- Hide bullets on enemies not bottommost 

class Enemy : public Character {
	Character& player_;

	Point <int> placeValue_;
	Point <float> selfCoord_;

	int points_ {30};
	bool isBottomMost_;


	int setupRows(int& setNum);

public:
	Enemy(const float& x, const float& y, int& rowNum, Character& player);

	void draw();
	void move(Point <float> refCoord);
	void fire();

	void getSprite(bool isFirst, const int& setNum);

	void hitEvent(const bool& isTrue);

	void setNewBottom(const bool& val);

	bool canShoot();
};
