#include "Asteroid.h"

Asteroid::Asteroid(double direction, double xPos, double yPos, SDL_Renderer* renderer)
{
	mDirection = direction;
	mPosition.X = xPos;
	mPosition.Y = yPos;
	mRenderer = renderer;
	mRotationSpeed = 0.5; // Angular speed in degrees
	mSpeed = 1;

	loadTexture();
}

void Asteroid::loadTexture()
{
	if (!mTexture.loadFromFile("Resources/asteroid-l.png", mRenderer))
	{
		printf("Failed to load starship texture!\n");
	}
}
