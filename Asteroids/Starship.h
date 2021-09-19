#pragma once
#include <SDL.h>
#include <cmath>
#include <sstream>

class Starship
{
public:
	Starship();

	void rotate(double degrees);
	void thrust();

	double getStarshipDirection();
	Uint8 getXPos();
	Uint8 getYPos();

	void calculatePosition();
	std::stringstream getDebugText();

private:
	double mXPos;
	double mYPos;

	double mMovementDirection;
	double mStarshipDirection;
	double mSpeed;
	static const double baseThrust;
};