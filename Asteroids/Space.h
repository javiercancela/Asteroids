#pragma once
#include "Starship.h"
#include "SpacePoint.h"
#include "Asteroid.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

class Space
{
public:
	Space(int asteroidsCount, SDL_Renderer* renderer);
	~Space();

	void updateSpace();
	void render();
	void addBullet(Bullet bullet);
	void addAsteroids(int asteroidsCount, SDL_Renderer* renderer);
	Starship* getStarship();
	int getPoints();
	
private:
	Starship* mStarship;
	std::vector<Bullet> mBullets;
	std::vector<Asteroid*> mAsteroids;
	int mPoints = 0;
	void updateStarship();
	void updateBullets();
	bool checkBulletHitAsteroid(Bullet bullet);
	bool checkAsteroidHitStarship(Asteroid* asteroid);
	void updateAsteroids();
};