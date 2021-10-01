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

	if (X > WINDOW_WIDTH)
	{
		X = X - WINDOW_WIDTH;
	}
	else if (X < 0)
	{
		X = X + WINDOW_WIDTH;
	}
	if (Y > WINDOW_HEIGHT)
	{
		Y = Y - WINDOW_HEIGHT;
	}
	else if (Y < 0)
	{
		Y = Y + WINDOW_HEIGHT;
	}

}
