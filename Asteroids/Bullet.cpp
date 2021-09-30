#include "Bullet.h"

Bullet::Bullet(double direction, double xPos, double yPos, SDL_Renderer* renderer)
{
	mDirection = direction;
	mPosition.X = xPos;
	mPosition.Y = yPos;
	mSpeed = 15.0;
	mRenderer = renderer;
}

void Bullet::render()
{
	SDL_RenderDrawPointF(mRenderer, mPosition.X, mPosition.Y);
}
