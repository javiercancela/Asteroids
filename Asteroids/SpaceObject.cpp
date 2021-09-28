#include "SpaceObject.h"
#include <cmath>
#define PI 3.14159265

SpaceObject::SpaceObject() : mSpeed(0.0), mDirection(0.0), mPosition(SpacePoint())
{

}

SpacePoint SpaceObject::getPositionChange()
{
	SpacePoint spacePoint;
	spacePoint.X += mSpeed * cos(mDirection * PI / 180);
	spacePoint.Y += mSpeed * sin(mDirection * PI / 180);
	return spacePoint;
}

SpacePoint SpaceObject::getPosition()
{
	return mPosition;
}

void SpaceObject::setPosition(SpacePoint position)
{
	mPosition = position;
}
