#include "Starship.h"

#define PI 3.14159265

const double Starship::baseThrust = 0.1;
const double Starship::maxSpeed = 10;

Starship::Starship(int xPos, int yPos)
{
	mStarshipDirection = 0;
	mMovementDirection = 0;
	mSpeed = 0;
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
	double currentSpeedX = mSpeed * cos(mMovementDirection * PI / 180);
	double currentSpeedY = mSpeed * sin(mMovementDirection * PI / 180);

	double xThrust = baseThrust * cos(mStarshipDirection * PI / 180);
	double yThrust = baseThrust * sin(mStarshipDirection * PI / 180);

	double newSpeedX = currentSpeedX + xThrust;
	double newSpeedY = currentSpeedY + yThrust;

	mSpeed = sqrt(pow(newSpeedX, 2.0) + pow(newSpeedY, 2.0));
	mMovementDirection = atan2(newSpeedY, newSpeedX) * 180 / PI;
	mSpeed = (mSpeed > maxSpeed ? maxSpeed : mSpeed);
	if (mMovementDirection > 360)
	{
		mMovementDirection -= 360;
	}
	else if (mMovementDirection < 0)
	{
		mMovementDirection += 360;
	}
}

Bullet Starship::shoot()
{
	//double gunX = 20;
	//double gunY = 20;
	double gunX = 20 * cos(mStarshipDirection * PI / 180) + 20;
	double gunY = 20 * sin(mStarshipDirection * PI / 180) + 20;

	Bullet bullet(mStarshipDirection, mPosition.X + gunX, mPosition.Y + gunY);
	return bullet;
}

double Starship::getStarshipDirection()
{
	return mStarshipDirection;
}

SpacePoint Starship::getPositionChange()
{
	SpacePoint starshipMovement;
	starshipMovement.X += mSpeed * cos(mMovementDirection * PI / 180);
	starshipMovement.Y += mSpeed * sin(mMovementDirection * PI / 180);

	return starshipMovement;
}

SpacePoint Starship::getPosition()
{
	return mPosition;
}

void Starship::setPosition(SpacePoint position)
{
	mPosition = position;
}

std::stringstream Starship::getDebugText()
{
	std::stringstream debugText;
	debugText << "speed: " << mSpeed << " - movementDirection: " << mMovementDirection << " - starshipDirection: " << mStarshipDirection;
	return debugText;
}

SpacePoint Starship::getGunPosition()
{
	SpacePoint spacePoint;
	spacePoint.X += 20 * cos(mStarshipDirection * PI / 180);
	spacePoint.Y += 20 * sin(mStarshipDirection * PI / 180);
	return spacePoint;
}