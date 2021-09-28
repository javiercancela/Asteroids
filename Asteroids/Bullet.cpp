#include "Bullet.h"

Bullet::Bullet(double direction, int xPos, int yPos)
{
	mDirection = direction;
	mPosition.X = xPos;
	mPosition.Y = yPos;
	mSpeed = 15.0;
}
