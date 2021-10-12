#include "Space.h"


Space::Space(int asteroidsCount, SDL_Renderer* renderer, int width, int height)
{
	mStarship = new Starship(renderer);
	mScreenWidth= width;
	mScreenHeight = height;
	mNewAsteroids = asteroidsCount;
	mRenderer = renderer;

	SpacePoint sp;
	sp.X = (mScreenWidth - STARSHIP_SIZE) / 2;
	sp.Y = (mScreenHeight - STARSHIP_SIZE) / 2;
	mStarship->setPosition(sp);

	addAsteroids();
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
	starshipPosition.add(starshipMovement, mScreenWidth, mScreenHeight);
	mStarship->setPosition(starshipPosition);
}

void Space::updateBullets()
{
	auto bullet = mBullets.begin();
	while (bullet != mBullets.end())
	{
 		SpacePoint bulletMovement = bullet->getPositionChange();
		SpacePoint bulletPosition = bullet->getPosition();
		bulletPosition.add(bulletMovement, mScreenWidth, mScreenHeight);

		// If bullet dies (too much distance) or hits asteroid -> delete bullet
		if (bullet->getDistance() > mScreenHeight || checkBulletHitAsteroid(*bullet))
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

bool Space::checkBulletHitAsteroid(Bullet bullet)
{
	bool hit = false;
	auto asteroid = mAsteroids.begin();
	std::vector<Asteroid*> newAsteroids;
	while (asteroid != mAsteroids.end())
	{
		SpacePoint asteroidPosition = (*asteroid)->getPosition();
		if (bullet.collidesWithObject(asteroidPosition.X, asteroidPosition.Y,
			(*asteroid)->getWidth(), (*asteroid)->getWidth()))
		{
			hit = true;
			mPoints += 10;
			std::vector<Asteroid*> childrenAsteroids = (*asteroid)->hit();
			newAsteroids.insert(newAsteroids.end(), childrenAsteroids.begin(), childrenAsteroids.end());
			*asteroid = nullptr;
			asteroid = mAsteroids.erase(asteroid);
		}
		else
		{
			asteroid++;
		}
	}

	if (newAsteroids.size() > 0)
	{
		auto newAsteroid = newAsteroids.begin();
		while (newAsteroid != newAsteroids.end())
		{
			mAsteroids.push_back(*newAsteroid);
			newAsteroid++;
		}
	}
	return hit;
}

bool Space::checkAsteroidHitStarship(Asteroid* asteroid)
{
	bool hit = false;

	if (asteroid->collidesWithObject(mStarship->getPosition().X, mStarship->getPosition().Y,
		mStarship->getWidth(), mStarship->getHeight()))
	{
		hit = true;
		mStarship->startExploding();
	}
	return hit;
}

void Space::updateAsteroids()
{
	if (mAsteroids.size() == 0)
	{
		mNewAsteroids++;
		addAsteroids();

	}
	auto asteroid = mAsteroids.begin();
	while (asteroid != mAsteroids.end())
	{
		(*asteroid)->rotate(1);
		SpacePoint asteroidMovement = (*asteroid)->getPositionChange();
		SpacePoint asteroidPosition = (*asteroid)->getPosition();
		asteroidPosition.add(asteroidMovement, mScreenWidth, mScreenHeight);
		(*asteroid)->setPosition(asteroidPosition);
		checkAsteroidHitStarship(*asteroid);
		asteroid++;
	}
}

void Space::addBullet(Bullet bullet)
{
	mBullets.push_back(bullet);
}

void Space::addAsteroids()
{
	for (int i = 0; i < mNewAsteroids; i++)
	{
		time_t tmp = time(NULL);
		srand(tmp + 10*i);
		int direction = rand() % 360;
		int x = 100;
		int y = 100;
		int axis = rand() % 2;
		if (axis == 0)
		{
			x = rand() % mScreenWidth;
		}
		else
		{
			y = rand() % mScreenHeight;
		}

		Asteroid* asteroid = new Asteroid(direction, x, y, mRenderer);
		mAsteroids.push_back(asteroid);
	}
}

Starship* Space::getStarship()
{
	return mStarship;
}

int Space::getPoints()
{
	return mPoints;
}
