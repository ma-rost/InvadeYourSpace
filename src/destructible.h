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

	/**
	 * \brief Set isLive_ to false
	 */
	void kill();
	void draw(const int& spriteIndex);

	/**
	 * \brief updates the coordinates of a destructible
	 * \param x The new x location of the object
	 * \param y The new y location of the object
	 * \param applyResize decides if the location should be multiplied by the global resize value
	 */
	void setCoords(const float& x, const float& y, bool applyResize);
	/**
	 * \brief updates the coordinates of a destructible, only on y
	 * \param y The new y location of the object
	 * \param applyResize decides if the location should be multiplied by the global resize value
	 */
	void setCoords(const float& y, bool applyResize);

	static float applyResize(float value);
	static Point <float> applyResize(Point <float> value);
	/**
	 * \brief Determines which sprite should display based on frame num
	 * \return Which sprite should be displayed
	 */
	static int getSpriteValue();

	Rect <float> getCollider() const;
	/** \brief Sets the collision for an object. */
	void setCollision();
	void setCollision(Point <float> xy, Point <float> wh);
	void setCollision(const float& x, const float& y, const float& w,
	                  const float& h);
};
