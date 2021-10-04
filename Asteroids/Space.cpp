#include "Space.h"


Space::Space(int asteroidsCount, SDL_Renderer* renderer)
{
	mStarship = new Starship(renderer);
	

	SpacePoint sp;
	sp.X = (WINDOW_WIDTH - STARSHIP_SIZE) / 2;
	sp.Y = (WINDOW_HEIGHT - STARSHIP_SIZE) / 2;
	mStarship->setPosition(sp);

	addAsteroids(asteroidsCount, renderer);
}

Space::~Space()
{
	mStarship = NULL;
}

void Space::updateSpace()
{
	updateStarship();
	updateBullets();
	updateAsteroids();
}

void Space::render()
{
	mStarship->render();

	for (auto bullet : mBullets)
	{
		bullet.render();
	}

	for (auto asteroid : mAsteroids)
	{
		asteroid->render();
	}
}

void Space::updateStarship()
{
	SpacePoint starshipMovement = mStarship->getPositionChange();
	SpacePoint starshipPosition = mStarship->getPosition();
	starshipPosition.add(starshipMovement);
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
		if (bullet->getDistance() > WINDOW_HEIGHT)
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
void Space::updateAsteroids()
{
	auto asteroid = mAsteroids.begin();
	while (asteroid != mAsteroids.end())
	{
		(*asteroid)->rotate(1);
		SpacePoint asteroidMovement = (*asteroid)->getPositionChange();
		SpacePoint asteroidPosition = (*asteroid)->getPosition();
		asteroidPosition.add(asteroidMovement);
		(*asteroid)->setPosition(asteroidPosition);
		asteroid++;
	}
}
void Space::addBullet(Bullet bullet)
{
	mBullets.push_back(bullet);
}

void Space::addAsteroids(int asteroidsCount, SDL_Renderer* renderer)
{
	for (int i = 0; i < asteroidsCount; i++)
	{
		time_t tmp = time(NULL);
		srand(tmp + 10*i);
		int direction = rand() % 360;
		int x = 100;
		int y = 100;
		int axis = rand() % 2;
		if (axis == 0)
		{
			x = rand() % WINDOW_WIDTH;
		}
		else
		{
			y = rand() % WINDOW_HEIGHT;
		}

		Asteroid* asteroid = new Asteroid(direction, x, y, renderer);
		mAsteroids.push_back(asteroid);
	}
}

Starship* Space::getStarship()
{
	return mStarship;
}
