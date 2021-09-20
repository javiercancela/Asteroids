#include "Space.h"

Space::Space(int spaceWidth, int spaceHeight, int spaceshipSize, Starship* starship)
{
	mSpaceHeight = spaceHeight;
	mSpaceWidth = spaceWidth;
	mSpaceshipSize = spaceshipSize;
	mSsXPos = (mSpaceWidth - mSpaceshipSize) / 2;
	mSsYPos = (mSpaceHeight - mSpaceshipSize) / 2;
	mStarship = starship;
}

void Space::updateSpace()
{
	SpacePoint starshipMovement = mStarship->getPositionChange();

}

