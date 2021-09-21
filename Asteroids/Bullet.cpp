#include "Bullet.h"
#include <cmath>
#define PI 3.14159265

const double speed = 15;
Bullet::Bullet(double direction)
{
	mDirection = direction;
}

SpacePoint Bullet::getPositionChange()
{
	SpacePoint spacePoint;
	spacePoint.X += speed * cos(mDirection * PI / 180);
	spacePoint.Y += speed * sin(mDirection * PI / 180);
	return spacePoint;

}
