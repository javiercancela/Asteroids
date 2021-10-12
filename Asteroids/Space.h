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
	Space(int asteroidsCount, SDL_Renderer* renderer, int width, int height);
	~Space();

	void updateSpace();
	void render();
	void addBullet(Bullet bullet);
	void addAsteroids();
	Starship* getStarship();
	int getPoints();
	
private:
	Starship* mStarship;
	std::vector<Bullet> mBullets;
	std::vector<Asteroid*> mAsteroids;
	int mPoints = 0;
	int mScreenWidth = 0;
	int mScreenHeight = 0;
	int mNewAsteroids = 0;
	SDL_Renderer* mRenderer;
	void updateStarship();
	void updateBullets();
	bool checkBulletHitAsteroid(Bullet bullet);
	bool checkAsteroidHitStarship(Asteroid* asteroid);
	void updateAsteroids();
};