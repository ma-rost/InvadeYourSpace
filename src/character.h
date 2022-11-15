#pragma once

#include "destructible.h"
#include "bullet.h"

class Character : public Destructible {
protected:
	const bool isPlayer_;
	Point <float> bulletSpawn_;
	Bullet bullet_;
public:
	Character(const float& x, const float& y, const bool& isPlayer);
	Character(const float& x, const float& y, const bool& isPlayer,
	          const float& moveSpeed);

	void move(const bool& isMoveRight);
	void draw(const int& spriteIndex);
	void fire();

	Point <float> getCoordinate();


	bool checkCollide(const Destructible& obj);

	Character& operator++();
	Character& operator--();
private:
	void setBulletSpawn();
};
