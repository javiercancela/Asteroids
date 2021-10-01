#pragma once
#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 600

struct SpacePoint
{
	SpacePoint();

	void add(SpacePoint spaceDistance);
	double X;
	double Y;
};