#pragma once
#include "SpaceObject.h"

class Asteroid : public SpaceObject
{
public:
	Asteroid(double direction, double xPos, double yPos, SDL_Renderer* renderer);
	void loadTexture();
};
