#pragma once
#include "Starship.h"
#include "SpacePoint.h"
#include <vector>

class Space
{
public:
	Space(int spaceWidth, int spaceHeight, int spaceshipSize, Starship* starship);

	void updateSpace();
	void addBullet(Bullet bullet);
	Starship* getStarship();
	std::vector<Bullet> getBullets();
private:
	Starship* mStarship;
	SpacePoint mSsPos;
	int mSpaceWidth;
	int mSpaceHeight;
	int mSpaceshipSize;
	std::vector<Bullet> mBullets;
	void updateStarship();
	void updateBullets();
};