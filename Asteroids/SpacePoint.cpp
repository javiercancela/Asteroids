#include "SpacePoint.h"

SpacePoint::SpacePoint()
{
	X = 0;
	Y = 0;
}

void SpacePoint::add(SpacePoint spaceDistance, int spaceWidth, int spaceHeight)
{
	X += spaceDistance.X;
	Y += spaceDistance.Y;

	if (X > spaceWidth)
	{
		X = X - spaceWidth;
	}
	else if (X < 0)
	{
		X = X + spaceWidth;
	}
	if (Y > spaceHeight)
	{
		Y = Y - spaceHeight;
	}
	else if (Y < 0)
	{
		Y = Y + spaceHeight;
	}

}
