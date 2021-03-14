#pragma once
#include <SDL_image.h>

class Sprite
{
	SDL_Texture* pSpriteTex = nullptr;
	SDL_Rect src;

public:
	SDL_Rect dst;

	Sprite();
	Sprite(SDL_Renderer* renderer, const char* filename,
		int w, int h);
	Sprite(SDL_Renderer* renderer, const char* filename,
		int srcX, int srcY, int srcW, int srcH,
		int dstX, int dstY, int dstW, int dstH);

	~Sprite();

	void draw(SDL_Renderer* renderer);

	void cleanup();
};