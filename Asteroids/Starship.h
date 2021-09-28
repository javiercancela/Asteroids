#pragma once
#include <SDL.h>
#include <cmath>
#include <sstream>
#include "SpacePoint.h"
#include "Bullet.h"

class Starship : public SpaceObject
{
public:
	Starship(int xPos, int yPos);

	void rotate(double degrees);
	void thrust();
	Bullet shoot();
	double getStarshipDirection();

	SpacePoint getGunPosition();

private:
	double mStarshipDirection;
	static const double baseThrust;
	static const double maxSpeed;
};