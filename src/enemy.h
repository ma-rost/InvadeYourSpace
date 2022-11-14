#pragma once
#include "character.h"
#include <algorithm>
#include <array>

// THINGS TO DO /////
	// - Make enemies move down when hitting right side
	//		- only rightmost enemies slide down
	// - Only bottom most enemy has (Working) bullets
	//		- Hide bullets on enemies not bottommost 

class Enemy : public Character {

	Point<float> selfCoord_;
	
	Enemy* enemy_;
	int points_{30};
	bool isBottomMost_;

	int setupRows(int& setNum);

public:
	
	Enemy (const float& x, const float& y, int& spriteSet);

	void draw ();
	void move(Point<float> refCoord);

	void getSprite (bool isFirst, const int& setNum);

	void hitEvent(const bool& isTrue);

	bool canShoot();


};


