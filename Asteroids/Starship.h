#pragma once
#include <SDL.h>
#include <cmath>
#include <sstream>
#include "SpacePoint.h"

class Starship
{
public:
	Starship();

	void rotate(double degrees);
	void thrust();

	double getStarshipDirection();

	SpacePoint getPositionChange();
	std::stringstream getDebugText();

private:
	double mMovementDirection;
	double mStarshipDirection;
	double mSpeed;
	static const double baseThrust;
};