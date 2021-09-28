#include "Starship.h"

#define PI 3.14159265

const double Starship::baseThrust = 0.1;
const double Starship::maxSpeed = 10;

Starship::Starship(int xPos, int yPos)
{
	mDirection = 0.0;
	mStarshipDirection = 0;
	mPosition.X = xPos;
	mPosition.Y = yPos;
}

void Starship::rotate(double degrees)
{
	mStarshipDirection += degrees;
	if (mStarshipDirection > 360)
	{
		mStarshipDirection -= 360;
	}
	else if (mStarshipDirection < 0)
	{
		mStarshipDirection += 360;
	}
}

void Starship::thrust()
{
	double currentSpeedX = mSpeed * cos(mDirection * PI / 180);
	double currentSpeedY = mSpeed * sin(mDirection * PI / 180);

	double xThrust = baseThrust * cos(mStarshipDirection * PI / 180);
	double yThrust = baseThrust * sin(mStarshipDirection * PI / 180);

	double newSpeedX = currentSpeedX + xThrust;
	double newSpeedY = currentSpeedY + yThrust;

	mSpeed = sqrt(pow(newSpeedX, 2.0) + pow(newSpeedY, 2.0));
	mDirection = atan2(newSpeedY, newSpeedX) * 180 / PI;
	mSpeed = (mSpeed > maxSpeed ? maxSpeed : mSpeed);
	if (mDirection > 360)
	{
		mDirection -= 360;
	}
	else if (mDirection < 0)
	{
		mDirection += 360;
	}
}

Bullet Starship::shoot()
{
	double gunX = 20 * cos(mStarshipDirection * PI / 180) + 20;
	double gunY = 20 * sin(mStarshipDirection * PI / 180) + 20;

	Bullet bullet(mStarshipDirection, mPosition.X + gunX, mPosition.Y + gunY);
	return bullet;
}

double Starship::getStarshipDirection()
{
	return mStarshipDirection;
}
SpacePoint Starship::getGunPosition()
{
	SpacePoint spacePoint;
	spacePoint.X += 20 * cos(mStarshipDirection * PI / 180);
	spacePoint.Y += 20 * sin(mStarshipDirection * PI / 180);
	return spacePoint;
}