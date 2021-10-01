#pragma once
#include "Starship.h"
#include "SpacePoint.h"
#include "Asteroid.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

#define STARSHIP_SIZE 40

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
	
private:
	Starship* mStarship;
	Asteroid* mAsteroid;
	std::vector<Bullet> mBullets;
	std::vector<Asteroid> mAsteroids;
	void updateStarship();
	void updateBullets();
	void updateAsteroids();
};