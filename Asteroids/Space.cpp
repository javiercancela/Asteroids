#include "Space.h"

Space::Space(int spaceWidth, int spaceHeight, int spaceshipSize, Starship* starship)
{
	mSpaceHeight = spaceHeight;
	mSpaceWidth = spaceWidth;
	mSpaceshipSize = spaceshipSize;
	
	mSsPos.X = (mSpaceWidth - mSpaceshipSize) / 2;
	mSsPos.Y = (mSpaceHeight - mSpaceshipSize) / 2;
	mStarship = starship;
}

void Space::updateSpace()
{
	SpacePoint starshipMovement = mStarship->getPositionChange();
	mSsPos.add(starshipMovement);
	if (mSsPos.X > mSpaceWidth)
	{
		mSsPos.X = mSsPos.X - mSpaceWidth;
	}
	if (mSsPos.Y > mSpaceHeight)
	{
		mSsPos.Y = mSsPos.Y - mSpaceHeight;
	}
}

SpacePoint Space::getStarshipPosition()
{
	return mSsPos;
}

