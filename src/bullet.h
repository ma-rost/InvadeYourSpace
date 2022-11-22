#pragma once
#include "destructible.h"


class Character;
class EnemyContainer;

class Bullet : public Destructible {

	const bool isPlayer_;
	bool isFired_ {false};
	bool isActive_ {false};
	Point <float> bulletOrigin_;

	static constexpr float MOVE_SPEED {10};

public:
	std::string memoryAddress_;
	explicit Bullet();
	explicit Bullet(const bool& isPlayer);
	Bullet(const float& x, const float& y, const bool& isPlayer);

	void move();
	void fire();

	/**
	 * \brief move the bullet to its origin and mark isFired_ = false;
	 */
	void resetBullet();
	/**
	 * \brief set a new point for the bullet to rest (x,y)
	 * \param bulletOrigin the coordinate of where the origin should be
	 */
	void setBulletOrigin(Point <float> bulletOrigin);
	/**
	 * \brief set if the bullet should be able to shoot
	 * \param isBottom is the bullet on the bottom row of enemies
	 */
	void setIsActive(const bool& isBottom);

	/**
	 * \brief checks if the bullet is within a given collider
	 * \param col the collider of the hittable object
	 * \param isLive if the hittable object is living
	 * \return if the bullet is within the hittable object
	 */
	bool hasHitOppos(Rect<float> col, bool isLive);

	Bullet& operator++()
	{
		isPlayer_ ? collider_.y -= MOVE_SPEED :
					collider_.y += MOVE_SPEED;
		return *this;
	}

private:
	/**
	 * \brief Determine if the bullet is within the glb::DRAW_RESTRICTIONS
	 * \return If the bullet is within the glb::DRAW_RESTRICTIONS.
	 *		If it is, return true. Otherwise return false
	 */
	bool isHitValid();
};
