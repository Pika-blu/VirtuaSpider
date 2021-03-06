#pragma once
#include <SDL_image.h>
#include <math.h>

class Bullet
{
	SDL_Texture* pSpriteTex = nullptr;
	SDL_Rect src;

	float dY;

public:
	SDL_Rect dst;


	float velX = -1000;

	Bullet();
	Bullet(SDL_Renderer* renderer, int x, int y);

	~Bullet();

	void update(float deltaTime);
	void draw(SDL_Renderer* renderer);

	void cleanup();

	bool outOfScreen() { return dst.y <= 0; }

	bool checkCollision(SDL_Rect r);

};