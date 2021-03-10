#include "Sprite.h"

//constructor
Sprite::Sprite()
{
}

//constructor
Sprite::Sprite(SDL_Renderer* renderer, const char* filename,
	int w, int h)
{
	pSpriteTex = IMG_LoadTexture(renderer, filename);

	SDL_QueryTexture(pSpriteTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.y = 0;

	dst.x = 0;
	dst.y = 0;
	dst.w = w;
	dst.h = h;
}

//constructor
Sprite::Sprite(SDL_Renderer* renderer, const char* filename,
	int srcX, int srcY, int srcW, int srcH,
	int dstX, int dstY, int dstW, int dstH)
{
	pSpriteTex = IMG_LoadTexture(renderer, filename);

	SDL_QueryTexture(pSpriteTex, NULL, NULL, &src.w, &src.h);

	src.x = srcX;
	src.y = srcY;
	src.w = srcW;
	src.h = srcH;


	dst.x = dstX;
	dst.y = dstY;
	dst.w = dstW;
	dst.h = dstH;
}


//destructor
Sprite::~Sprite()
{
}


void Sprite::cleanup()
{
	SDL_DestroyTexture(pSpriteTex);
}

void Sprite::setPosition(int x, int y)
{
	dst.x = x;
	dst.y = y;
}

void Sprite::setSize(int x, int y)
{
	dst.w = x;
	dst.h = y;
}

void Sprite::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, pSpriteTex, &src, &dst);
}
