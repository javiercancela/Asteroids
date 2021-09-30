#pragma once
#include "Starship.h"
#include "SpacePoint.h"
#include "Asteroid.h"
#include <vector>

class Space
{
public:
	Space(int spaceWidth, int spaceHeight, int spaceshipSize);

	void updateSpace();
	void render();
	void addBullet(Bullet bullet);
	std::vector<Bullet> getBullets();

private:
	Starship mStarship;
	Asteroid* mAsteroid;
	SpacePoint mSsPos;
	int mSpaceWidth;
	int mSpaceHeight;
	int mSpaceshipSize;
	std::vector<Bullet> mBullets;
	void updateStarship();
	void updateBullets();
};