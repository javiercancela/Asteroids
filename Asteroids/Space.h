#pragma once
#include "Starship.h"
#include "SpacePoint.h"

class Space
{
public:
	Space(int spaceWidth, int spaceHeight, int spaceshipSize, Starship* starship);

	void updateSpace();
	SpacePoint getStarshipPosition();

private:
	Starship* mStarship;
	SpacePoint mSsPos;
	int mSpaceWidth;
	int mSpaceHeight;
	int mSpaceshipSize;

};