#include "Starship.h"

Starship::Starship()
{
	mXPos = 0;
	mYPos = 0;

	mStarshipDirection = 0;
	mMovementDirection = 0;
	mSpeed = 0;
}

void Starship::rotate(double degrees)
{
	mStarshipDirection += degrees;
}

void Starship::thrust()
{
	++mSpeed;
}

double Starship::getStarshipDirection()
{
	return mStarshipDirection;
}

Uint8 Starship::getXPos()
{
	return mXPos;
}

Uint8 Starship::getYPos()
{
	return mYPos;
}

void Starship::calculateSpeed()
{

}

void Starship::calculatePosition()
{
}
