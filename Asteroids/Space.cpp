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
	updateStarship();
	updateBullets();
}

Starship* Space::getStarship()
{
	return mStarship;
}

std::vector<Bullet> Space::getBullets()
{
	return mBullets;
}

void Space::updateStarship()
{
	SpacePoint starshipMovement = mStarship->getPositionChange();
	SpacePoint starshipPosition = mStarship->getPosition();
	starshipPosition.add(starshipMovement);
	if (starshipPosition.X > mSpaceWidth)
	{
		starshipPosition.X = starshipPosition.X - mSpaceWidth;
	}
	else if (starshipPosition.X < 0)
	{
		starshipPosition.X = starshipPosition.X + mSpaceWidth;
	}
	if (starshipPosition.Y > mSpaceHeight)
	{
		starshipPosition.Y = starshipPosition.Y - mSpaceHeight;
	}
	else if (starshipPosition.Y < 0)
	{
		starshipPosition.Y = starshipPosition.Y + mSpaceHeight;
	}
	mStarship->setPosition(starshipPosition);
}

void Space::updateBullets()
{
	auto bullet = mBullets.begin();
	while (bullet != mBullets.end())
	{
		SpacePoint bulletMovement = bullet->getPositionChange();
		SpacePoint bulletPosition = bullet->getPosition();
		bulletPosition.add(bulletMovement);
		if (bulletPosition.X > mSpaceWidth || bulletPosition.X < 0  ||
			bulletPosition.Y > mSpaceHeight || bulletPosition.Y < 0)
		{
			bullet = mBullets.erase(bullet);
		}
		else 
		{
			bullet->setPosition(bulletPosition);
			bullet++;
		}
	}
}
void Space::addBullet(Bullet bullet)
{
	mBullets.push_back(bullet);;
}
