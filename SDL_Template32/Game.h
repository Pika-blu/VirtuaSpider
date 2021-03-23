#ifndef __GAME__
#define __GAME__

#include "SDL.h"
#include "Sprite.h"
#include "Hero.h"
#include "BulletList.h"

class Game
{

public:

	Game();
	~Game();

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void prepare();

	void handleEvents();
	void update();
	void render();
	void waitForNextFrame();

	void cleanup();

	bool running() { return m_bRunning; }





private:

	Hero hero;
	Sprite background;
	BulletList bullets;
	/*Asteroid obstacle;*/

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;

	int targetFramerate = 60;
	int frameDelayMs = 1000 / targetFramerate;

	Uint32 currentFrameEndTime;
	Uint32 currentFrameStartTime;
	Uint32 timeSinceLastFrame;

	float deltaTime;

	float gameTime = 0;
};


#endif 

