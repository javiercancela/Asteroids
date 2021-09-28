#pragma once
#include "SpacePoint.h"
#include "SpaceObject.h"	

class Bullet : public SpaceObject
{
public:
	Bullet(double direction, int xPos, int yPos);
};