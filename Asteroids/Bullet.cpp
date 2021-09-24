#include "Bullet.h"
#include <cmath>
#define PI 3.14159265

const double Bullet::speed = 15;
Bullet::Bullet(double direction, int xPos, int yPos)
{
	mDirection = direction;
	mPosition.X = xPos;
	mPosition.Y = yPos;
}

SpacePoint Bullet::getPosition()
{
	return mPosition;
}

void Bullet::setPosition(SpacePoint position)
{
	mPosition = position;
}

SpacePoint Bullet::getPositionChange()
{
	SpacePoint spacePoint;
	spacePoint.X += speed * cos(mDirection * PI / 180);
	spacePoint.Y += speed * sin(mDirection * PI / 180);
	return spacePoint;
}

