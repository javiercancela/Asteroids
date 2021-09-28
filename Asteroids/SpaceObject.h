#pragma once
#include "SpacePoint.h"

class SpaceObject
{
public:
	SpaceObject();
	SpaceObject(double direction, int xPos, int yPos);
	SpaceObject(double direction, int xPos, int yPos, double speed);

	SpacePoint getPositionChange();
	SpacePoint getPosition();
	void setPosition(SpacePoint position);

protected:
	double mDirection;
	SpacePoint mPosition;
	double mSpeed;
};