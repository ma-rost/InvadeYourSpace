#pragma once

#include <array>

#include "destructible.h"
#include "bullet.h"

class EnemyContainer;

class Character : public Destructible {
protected:
	///std::array<std::vector<Character>, 11>* enemies_;
	Character* player_;

	EnemyContainer* container_;


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



	void getAllDestructibles(Character& player, EnemyContainer& container);


	Character& operator++();
	Character& operator--();
private:
	void setBulletSpawn();
};
