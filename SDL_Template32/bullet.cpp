#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(SDL_Renderer* renderer, int x, int y)
{
	pSpriteTex = IMG_LoadTexture(renderer, "CD.png");

	SDL_QueryTexture(pSpriteTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.y = 0;


	dst.x = x;
	dst.y = y+20;
	dst.w = 10;
	dst.h = 10;
}

Bullet::~Bullet()
{
}

void Bullet::update()
{
	dst.x -= velX;
}

void Bullet::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, pSpriteTex, &src, &dst);
}

void Bullet::cleanup()
{
}