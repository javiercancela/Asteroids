#pragma once
#include "SpacePoint.h"

class Bullet
{
public:
	Bullet(double direction);

	SpacePoint getPositionChange();

private:
	double mDirection;
	static const double speed;
};