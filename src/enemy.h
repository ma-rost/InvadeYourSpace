#pragma once
#include "character.h"
#include <algorithm>

class Enemy : public Character {
	static std::vector<Enemy*> enemies_;
	static Point<float> wholeCoordinate_; // The coordinate of the first enemy
	static Point<float> wholeSize_; // The size of all of the enemies compiled into one
	Enemy* enemy_;
	static bool isForwardMove_;
	int points_{30};
	bool isBottomMost_;


	static float moveSpeed_;
public:
	
	Enemy (const float& x, const float& y, int& spriteSet);

	

	void draw ();
	void move();

	void getSprite (bool isFirst, const int& setNum);

	void hitEvent(const bool& isTrue);

	static std::vector<Enemy*> getAllObjects() {
		return enemies_;
	}

	// THINGS TO DO /////
	// - Make enemies move down when hitting right side
	//		- only rightmost enemies slide down
	// - Only bottom most enemy has (Working) bullets
	//		- Hide bullets on enemies not bottommost 


	static float getMoveSpeed() {
		return moveSpeed_;
	}

	static bool isMoveValid();

	static void setWholeSize(int rowSize, int columnSize);
	static void setWholeCoordinate(const Point<float> coordinate);
	static void drawDebugRange();

	static void moveWhole();

};


