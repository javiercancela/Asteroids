#include "Asteroid.h"

Asteroid::Asteroid(double xPos, double yPos, SDL_Renderer* renderer)
{
	mPosition.X = xPos;
	mPosition.Y = yPos;
	mRenderer = renderer;
	mRotationSpeed = 10; // Angular speed in degrees
	mSpeed = 4;

	loadTexture();
}

void Asteroid::loadTexture()
{
	if (!mTexture.loadFromFile("Resources/asteroid-l.png", mRenderer))
	{
		printf("Failed to load starship texture!\n");
	}
}
