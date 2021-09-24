#pragma once
#include <SDL.h>
#include <cmath>
#include <sstream>
#include "SpacePoint.h"
#include "Bullet.h"

class Starship
{
public:
	Starship(int xPos, int yPos);

	void rotate(double degrees);
	void thrust();
	Bullet shoot();
	double getStarshipDirection();

	SpacePoint getPositionChange();
	SpacePoint getPosition();
	void setPosition(SpacePoint position);
	SpacePoint getGunPosition();
	std::stringstream getDebugText();

private:
	double mMovementDirection;
	double mStarshipDirection;
	SpacePoint mPosition;
	double mSpeed;
	static const double baseThrust;
	static const double maxSpeed;
};