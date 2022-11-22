#pragma once

#include <array>

#include "destructible.h"
#include "bullet.h"

class EnemyContainer;

class Character : public Destructible
{
	bool hasPlayedDeathAnimation_{false};
protected:
	const bool isPlayer_;
	Point<float> bulletSpawn_;
	int value_{0};

public:
	static Character* player_;
	static EnemyContainer* container_;
	Bullet bullet_;

	Character(const float& x, const float& y, const bool& isPlayer);
	Character(const float& x, const float& y, const bool& isPlayer,
	          const float& moveSpeed);

	void move(const bool& isMoveRight);
	void moveBullet();
	void draw(const int& spriteIndex);
	void kill();
	void fire();
	bool checkCollider(Bullet& bullet);

	Point<float> getCoordinate();

	static void setDestructibles(Character& player, EnemyContainer& container);

	Character& operator++()
	{
		this->collider_.x += this->MOVE_SPEED;
		return *this;
	}

	Character& operator--()
	{
		this->collider_.x -= this->MOVE_SPEED;
		return *this;
	}

private:
	void setBulletSpawn();
};
