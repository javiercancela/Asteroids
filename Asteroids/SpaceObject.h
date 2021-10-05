#pragma once
#include "SpacePoint.h"
#include "LTexture.h"
#include <SDL.h>


class SpaceObject
{
public:
	SpaceObject();
	~SpaceObject();

	SpacePoint getPositionChange();
	SpacePoint getPosition();
	int getWidth();
	int getHeight();
	double getDistance();
	void setPosition(SpacePoint position);
	double getOrientation();
	void rotate(int rotationDir);
	void render();
	bool collidesWithObject(double x, double y, int width, int height);


protected:
	double mDirection = 0.0;
	double mOrientation = 0.0;
	double mRotationSpeed = 0.0;
	double mDistance = 0.0;
	SpacePoint mPosition;
	double mSpeed = 0.0;
	LTexture mTexture;
	SDL_Renderer* mRenderer = NULL;
};