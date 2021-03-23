#pragma once
#include <SDL_image.h>
#include <math.h>
#include "Sprite.h"
class Hero
{
	SDL_Texture* pSpriteTex = nullptr;
	SDL_Rect src;

public:
	SDL_Rect dst;

	float velX = 0;
	float velY = 0;

	Hero();
	Hero(SDL_Renderer* renderer, const char* filename,
		int w, int h);
	Hero(SDL_Renderer* renderer, const char* filename,
		int srcX, int srcY, int srcW, int srcH,
		int dstX, int dstY, int dstW, int dstH);

	~Hero();

	void setPosition(int x, int y);
	void moveBy(int x, int y);
	void draw(SDL_Renderer* renderer);

	void cleanup();

	int getWeaponX() { return dst.x + dst.w / 2; }
	int getWeaponY() { return dst.y; };


	float speedX = 10.0f;
	float speedY = 10.0f;
	Sprite sprite;
};

