#pragma once
#include "character.h"

// THINGS TO DO /////
// - Make enemies move down when hitting right side
//		- only rightmost enemies slide down
// - Only bottom most enemy has (Working) bullets
//		- Hide bullets on enemies not bottommost

class Enemy : public Character {
	Point <int> placeValue_;
	Point <float> selfCoord_;
	int setupRows(int& setNum);

public:
	bool isBottomMost_;
	bool canBeKilled_ = false;

	Enemy(const float& x, const float& y, int& rowNum, Character& player);

	/**
	 * \brief Move individual enemy object
	 * \param refCoord coordinates to base new location off of
	 */
	void move(Point<float> refCoord);
	/**
	 * \brief Kill the enemy
	 */
	void kill();
	/**
	 * \brief when an enemy is killed, the enemy above (this object) is set as the 'bottom' enemy 
	 */
	void setNewBottom();
	/**
	 * \brief determines if the enemy is valid to shoot
	 * \return if the enemy is still alive and marked as bottom, return true. Otherwise return false
	 */
	bool canShoot();

private:
	/**
	 * \brief creates a new sprite location
	 * \param isFirst if the sprite is on the upper row or lower row
	 * \param setNum which sprite set to use (0, 1, 2)
	 */
	void getSprite(bool isFirst, const int& setNum);
};

class EnemyContainer {
	Rect <float> wholeCollision_;
	constexpr static float MOVE_SPEED {8};
	// The amount of times the enemy will move per half second
	static int moveInterval_;
	// Is the container moving forwards or back
	static bool isForwardMove_;

	std::array <std::vector <Enemy>, 11> enemyTest_;
public:
	explicit EnemyContainer(Character& player);

	/**
	 * \brief Draw Each enemy
	 */
	void draw();
	
	/**
	 * \brief Move the container which holds the enemies
	 */
	void moveWhole();
	
	/**
	 * \brief Randomly chooses a bullet for one of the enemies to fire
	 */
	void fireEvent();
	/**
	 * \brief check if a bullet has collided with the opposing character type (enemy -> player) (player -> enemy)
	 */
	void checkForHit();
	/**
	 * \brief When a enemy is killed, set a new 'bottom most' enemy; which is above the current
	 */
	void enemyKilled();
	/**
	 * \brief determines how many enemies are alive
	 * \return if there are no more living enemies, return false. Otherwise return true
	 */
	bool enemiesLive();
	

	std::array<std::vector<Enemy>, 11>& getAllEnemies();

	/**
	 * \brief Kills each enemy to test the 'Win' game state
	 */
	void debugKillAllEnemies();
	/**
	 * \brief Checks a boolean, must be entered before runtime
	 */
	void debugPrintStates();

private:

	/**
	 * \brief Draws a rectangle using wholeCollision_
	 */
	void drawDebugRange() const;

	/**
	 * \brief Increases the size of the collider
	 */
	void setWholeSize();
	/**
	 * \brief change the XY Rect Variables to a given Point
	 * \param coordinate the Point to change the collision to
	 */
	void setWholeCoordinate(const Point <float> coordinate);

	/**
	 * \brief checks if the container should be moving left or right
	 */
	void isMovingRight();
};
