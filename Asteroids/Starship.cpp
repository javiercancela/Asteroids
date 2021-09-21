#include "Starship.h"

#define PI 3.14159265

const double Starship::baseThrust = 0.1;

Starship::Starship()
{
	mStarshipDirection = 0;
	mMovementDirection = 0;
	mSpeed = 0;
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
	double currentSpeedX = mSpeed * cos(mMovementDirection * PI / 180);
	double currentSpeedY = mSpeed * sin(mMovementDirection * PI / 180);

	double xThrust = baseThrust * cos(mStarshipDirection * PI / 180);
	double yThrust = baseThrust * sin(mStarshipDirection * PI / 180);

	double newSpeedX = currentSpeedX + xThrust;
	double newSpeedY = currentSpeedY + yThrust;

	mSpeed = sqrt(pow(newSpeedX, 2.0) + pow(newSpeedY, 2.0));
	mMovementDirection = atan2(newSpeedY, newSpeedX) * 180 / PI;
	if (mMovementDirection > 360)
	{
		mMovementDirection -= 360;
	}
	else if (mMovementDirection < 0)
	{
		mMovementDirection += 360;
	}
}

double Starship::getStarshipDirection()
{
	return mStarshipDirection;
}

SpacePoint Starship::getPositionChange()
{
	SpacePoint spacePoint;
	spacePoint.X += mSpeed * cos(mMovementDirection * PI / 180);
	spacePoint.Y += mSpeed * sin(mMovementDirection * PI / 180);
	return spacePoint;
}

std::stringstream Starship::getDebugText()
{
	std::stringstream debugText;
	debugText << "speed: " << mSpeed << " - movementDirection: " << mMovementDirection << " - starshipDirection: " << mStarshipDirection;
	return debugText;
}

