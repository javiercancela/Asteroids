#pragma once
#include <SDL.h>

class Starship
{
public:
	Starship();

	void rotate(double degrees);
	void thrust();

	double getStarshipDirection();
	Uint8 getXPos();
	Uint8 getYPos();

	void calculateSpeed();
	void calculatePosition();

private:
	Uint8 mXPos;
	Uint8 mYPos;

	double mMovementDirection;
	double mStarshipDirection;
	double mSpeed;
};