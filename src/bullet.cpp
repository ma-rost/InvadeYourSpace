#include "bullet.h"

Bullet::Bullet (const float& x, const float& y): Character(x, y)
{
	sprite_.clearCoords();
	sprite_.setSize({ 3,8 });
	sprite_.newCoords({ 41,21 });
}
