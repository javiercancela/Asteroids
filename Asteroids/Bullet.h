#pragma once
#include "SpacePoint.h"
#include "SpaceObject.h"	

class Bullet : public SpaceObject
{
public:
	Bullet(double direction, double xPos, double yPos, SDL_Renderer* renderer);
	void render();
};