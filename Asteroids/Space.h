#pragma once
#include "Starship.h"
#include "SpacePoint.h"
#include <vector>

class Space
{
public:
	Space(int spaceWidth, int spaceHeight, int spaceshipSize, Starship* starship);

	void updateSpace();
	SpacePoint getStarshipPosition();
	void addBullet(Bullet bullet);

private:
	Starship* mStarship;
	SpacePoint mSsPos;
	int mSpaceWidth;
	int mSpaceHeight;
	int mSpaceshipSize;
	std::vector<Bullet> mBullets;
};