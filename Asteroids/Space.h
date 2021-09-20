#pragma once
#include "Starship.h"
#include "SpacePoint.h"

class Space
{
public:
	Space(int spaceWidth, int spaceHeight, int spaceshipSize, Starship* starship);

	void updateSpace();

private:
	Starship* mStarship;
	Uint8 mSsXPos;
	Uint8 mSsYPos;
	int mSpaceWidth;
	int mSpaceHeight;
	int mSpaceshipSize;

};