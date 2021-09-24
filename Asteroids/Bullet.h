#pragma once
#include "SpacePoint.h"
#include "Bullet.h"

class Bullet
{
public:
	Bullet(double direction, int xPos, int yPos);

	SpacePoint getPositionChange();
	SpacePoint getPosition();
	void setPosition(SpacePoint position);

private:
	double mDirection;
	SpacePoint mPosition;
	static const double speed;
};