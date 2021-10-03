#include "Starship.h"

#define PI 3.14159265

const double Starship::baseThrust = 0.02;
const double Starship::maxSpeed = 5;

Starship::Starship(SDL_Renderer* renderer)
{
	mRenderer = renderer;
	mRotationSpeed = 2; // Angular speed in degrees

	loadTexture();
}

Starship::~Starship()
{
	mThrustTexture.free();
}

void Starship::loadTexture()
{
	if (!mTexture.loadFromFile("Resources/starship.png", mRenderer))
	{
		printf("Failed to load starship texture!\n");
	}
	if (!mThrustTexture.loadFromFile("Resources/starship-thrust.png", mRenderer))
	{
		printf("Failed to load starship thrust texture!\n");
	}
}


void Starship::thrust()
{
	double currentSpeedX = mSpeed * cos(mDirection * PI / 180);
	double currentSpeedY = mSpeed * sin(mDirection * PI / 180);

	double xThrust = baseThrust * cos(mOrientation * PI / 180);
	double yThrust = baseThrust * sin(mOrientation * PI / 180);

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

	isThrusting = true;
}

void Starship::stopThrust()
{
	isThrusting = false;
}

Bullet Starship::shoot()
{
	double gunX = 20 * cos(mOrientation * PI / 180) + (STARSHIP_SIZE / 2);
	double gunY = 20 * sin(mOrientation * PI / 180) + (STARSHIP_SIZE / 2);

	Bullet bullet(mOrientation, mPosition.X + gunX, mPosition.Y + gunY, mRenderer);
	return bullet;
}
 
SpacePoint Starship::getGunPosition()
{
	SpacePoint spacePoint;
	spacePoint.X += 20 * cos(mOrientation * PI / 180);
	spacePoint.Y += 20 * sin(mOrientation * PI / 180);
	return spacePoint;
}

void Starship::render()
{
	LTexture* texture = NULL;
	if (isThrusting)
	{
		texture = &mThrustTexture;
	}
	else
	{
		texture = &mTexture;
	}
	
	texture->render(mPosition.X, mPosition.Y, mRenderer, NULL, mOrientation, NULL, SDL_FLIP_NONE);
}
