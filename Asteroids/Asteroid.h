#pragma once
#include<vector>
#include "SpaceObject.h"

enum class AsteroidSize { large, medium, small };

class Asteroid : public SpaceObject
{
public:
	Asteroid(double direction, double xPos, double yPos, SDL_Renderer* renderer);
	std::vector<Asteroid*> hit();
private:
	Asteroid(AsteroidSize size, double direction, double xPos, double yPos, SDL_Renderer* renderer);
	void loadTexture();
	AsteroidSize mSize;
};
