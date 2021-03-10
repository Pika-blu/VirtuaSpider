#ifndef __GAME__
#define __GAME__

#include "SDL.h"
#include "Sprite.h"

class Game
{

public:

	Game();
	~Game();

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	//We do one time preparation stuff here
	void prepare();

	void render();
	void update();
	void handleEvents();
	void cleanup();
	void waitForFrame();

	//function to aaccess the running variable
	bool running() { return m_bRunning; }
private:

	Sprite background;
	Sprite spider1, spider2, spider3;
	Sprite hero;
	Sprite projectile;
	Sprite obstacle;
	Sprite dragon;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	
	bool m_bRunning;


	int targetFramerate = 30;
	int frameDelayMs = 1000 / targetFramerate;

	Uint32 cFEndTime;
	Uint32 cFStartTime;
	Uint32 tSinceLastFrame;

	//for gameplay
	float deltaTime;

	//Keep gameTime in seconds
	float gameTime = 0;
};

#endif /* defined (__Game__) */

