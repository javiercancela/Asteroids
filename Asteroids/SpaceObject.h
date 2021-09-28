#pragma once
#include "SpacePoint.h"

class SpaceObject
{
public:
	SpaceObject();

	SpacePoint getPositionChange();
	SpacePoint getPosition();
	void setPosition(SpacePoint position);

protected:
	double mDirection;
	SpacePoint mPosition;
	double mSpeed;
};