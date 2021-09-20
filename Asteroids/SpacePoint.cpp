#include "SpacePoint.h"

SpacePoint::SpacePoint()
{
	X = 0;
	Y = 0;
}

void SpacePoint::add(SpacePoint spaceDistance)
{
	X += spaceDistance.X;
	Y += spaceDistance.Y;
}
