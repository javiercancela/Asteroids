#include "SpaceObject.h"
#include <cmath>
#define PI 3.14159265

SpaceObject::SpaceObject()
{

}

SpaceObject::~SpaceObject()
{
	mTexture.free();
}


SpacePoint SpaceObject::getPositionChange()
{
	SpacePoint spacePoint;
	spacePoint.X += mSpeed * cos(mDirection * PI / 180);
	spacePoint.Y += mSpeed * sin(mDirection * PI / 180);
	mDistance += mSpeed;
	return spacePoint;
}

SpacePoint SpaceObject::getPosition()
{
	return mPosition;
}

int SpaceObject::getWidth()
{
	return mTexture.getWidth();
}

int SpaceObject::getHeight()
{
	return mTexture.getHeight();
}

double SpaceObject::getDistance()
{
	return mDistance;
}

void SpaceObject::setPosition(SpacePoint position)
{
	mPosition = position;
}

double SpaceObject::getOrientation()
{
	return mOrientation;
}

void SpaceObject::rotate(int rotationDir)
{
	mOrientation += rotationDir * mRotationSpeed;
	if (mOrientation > 360)
	{
		mOrientation -= 360;
	}
	else if (mOrientation < 0)
	{
		mOrientation += 360;
	}
}

void SpaceObject::render()
{
	mTexture.render(mPosition.X, mPosition.Y, mRenderer, NULL, mOrientation, NULL, SDL_FLIP_NONE);
}

bool SpaceObject::collidesWithObject(double x, double y, int width, int height)
{
	// Check that the object is not totally to the left or to the right of this object
	bool xAxisCollision = !(x + width < mPosition.X || x > mPosition.X + mTexture.getWidth());

	// Check that the object is not totally above or bellow this object
	bool yAxisCollision = !(y + height < mPosition.Y || y > mPosition.Y + mTexture.getHeight());

	return xAxisCollision && yAxisCollision;
}

