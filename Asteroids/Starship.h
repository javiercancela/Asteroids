#pragma once
#include <SDL.h>
#include <cmath>
#include <sstream>
#include "SpacePoint.h"
#include "Bullet.h"

#define STARSHIP_SIZE 24
#define EXPLODING_SPRITES 7
#define FRAMES_PER_SPRITE 10

class Starship : public SpaceObject
{
public:
	Starship(SDL_Renderer* renderer);
	~Starship();

	void thrust();
	void stopThrust();
	Bullet shoot();
	SpacePoint getGunPosition();
	void startExploding();
	void stopExploding();
	void render();

private:
	static const double baseThrust;
	static const double maxSpeed;
	LTexture mThrustTexture;
	LTexture mExplodingTexture;
	bool isThrusting = false;
	bool isExploding = false;
	int mExplodingFrame = 0;
	SDL_Rect mExplosionSprite[EXPLODING_SPRITES];

	void loadTexture();
};