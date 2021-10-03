#pragma once
#include <SDL.h>
#include <cmath>
#include <sstream>
#include "SpacePoint.h"
#include "Bullet.h"

#define STARSHIP_SIZE 24


class Starship : public SpaceObject
{
public:
	Starship(SDL_Renderer* renderer);
	~Starship();

	void thrust();
	void stopThrust();
	Bullet shoot();
	SpacePoint getGunPosition();
	void render();

private:
	static const double baseThrust;
	static const double maxSpeed;
	LTexture mThrustTexture;
	bool isThrusting = false;
	
	void loadTexture();
};