#include "Asteroid.h"

Asteroid::Asteroid(double direction, double xPos, double yPos, SDL_Renderer* renderer)
{
	mDirection = direction;
	mPosition.X = xPos;
	mPosition.Y = yPos;
	mRenderer = renderer;
	mRotationSpeed = 0.5; // Angular speed in degrees
	mSpeed = 1;
	mSize = AsteroidSize::large;

	loadTexture();
}

std::vector<Asteroid*> Asteroid::hit()
{
	std::vector<Asteroid*> children;
	
	if (mSize == AsteroidSize::large) 
	{
		for (int i = 0; i < 3; i++)
		{
			double direction = mDirection + 60 + i * 120;
			Asteroid* asteroid = new Asteroid(AsteroidSize::medium, direction, mPosition.X, mPosition.Y, mRenderer);
			children.push_back(asteroid);
		}
	}
	else if (mSize == AsteroidSize::medium)
	{
		for (int i = 0; i < 3; i++)
		{
			double direction = mDirection + 60 + i * 120;
			Asteroid* asteroid = new Asteroid(AsteroidSize::small, direction, mPosition.X, mPosition.Y, mRenderer);
			children.push_back(asteroid);
		}
	}

	return children;
}



Asteroid::Asteroid(AsteroidSize size, double direction, double xPos, double yPos, SDL_Renderer* renderer)
{
	mDirection = direction;
	mPosition.X = xPos;
	mPosition.Y = yPos;
	mRenderer = renderer;
	mRotationSpeed = 0.5; // Angular speed in degrees
	mSpeed = 1;
	mSize = size;

	loadTexture();
}

void Asteroid::loadTexture()
{
	switch (mSize)
	{
	case AsteroidSize::large:
		if (!mTexture.loadFromFile("Resources/asteroid-l.png", mRenderer))
		{
			printf("Failed to load starship texture!\n");
		}
		break;
	case AsteroidSize::medium:
		if (!mTexture.loadFromFile("Resources/asteroid-m.png", mRenderer))
		{
			printf("Failed to load starship texture!\n");
		}
		break;
	case AsteroidSize::small:
		if (!mTexture.loadFromFile("Resources/asteroid-s.png", mRenderer))
		{
			printf("Failed to load starship texture!\n");
		}
		break;
	}
}
