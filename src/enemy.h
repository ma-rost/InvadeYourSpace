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
	static std::vector<Enemy*> enemies_;

	//static std::array<std::array<Enemy, 5>, 11> enemyTest_;
	static Point<float> wholeCoordinate_; // The coordinate of the first enemy
	static Point<float> wholeSize_; // The size of all of the enemies compiled into one
	
	Enemy* enemy_;
	static bool isForwardMove_;
	int points_{30};
	bool isBottomMost_;


	static constexpr float MOVE_SPEED {24};

	int setupRows(int& setNum);


public:
	
	Enemy (const float& x, const float& y, int& spriteSet);

	void draw ();
	void move();

	void getSprite (bool isFirst, const int& setNum);

	void hitEvent(const bool& isTrue);


	#pragma region Static
	static std::vector<Enemy*> getAllObjects() {
		return enemies_;
	}

	static void isMovingRight();

	static void setWholeSize(int rowSize, int columnSize);
	static void setWholeCoordinate(const Point<float> coordinate);
	static void drawDebugRange();

	static void moveWhole();
	static float getMoveSpeed() { return MOVE_SPEED; }
	#pragma endregion

	Enemy& operator ++ ()
	{
		std::cout << "ENEMY";
		wholeCoordinate_.x += getMoveSpeed ();
		return *this;
	}

	Enemy& operator-- ()
	{
		std::cout << "ENEMY";
		wholeCoordinate_.x -= getMoveSpeed ();
		return *this;
	}

};


