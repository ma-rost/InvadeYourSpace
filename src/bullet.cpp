#include "bullet.h"

#include "ofGraphics.h"

Bullet::Bullet ():Bullet(4, 5, true)
{
}

Bullet::Bullet (const bool& isPlayer):
	Bullet (4,5,isPlayer)
{

}

Bullet::Bullet (const float& x, const float& y, const bool& isPlayer):
	Destructible(x, y),  isPlayer_ (isPlayer)
{
	drawColor_ = ofColor::white;

	sprite_.clearCoords();
	sprite_.setSize({ 3,7 });
	sprite_.newCoords({ 41,21 }); // Default
	sprite_.newCoords({ 16,21 }); // Death
}

void Bullet::move ()
{
	draw();
}

void Bullet::draw ()
{
	Destructible::draw(isLive_ ? 0 : 1);
}

void Bullet::fire ()
{
	/*if(!isFired_) {
		isFired_ = true;
		drawColor_ = ofColor::white;
	}*/
	if ( !isFired_ ) {
		std::cout << "FIRE\n";
	}
}

bool Bullet::checkHit ()
{
	return false;
}

void Bullet::resetBullet ()
{
	drawColor_  = ofColor::white;
	coordinate_ = bulletOrigin_;
}


void Bullet::setBulletOrigin (const Point<float> bulletOrigin)
{
	bulletOrigin_ = bulletOrigin;
	coordinate_ = bulletOrigin_;
	draw();
}
