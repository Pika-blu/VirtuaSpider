#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

bool Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		//initialization successful
		
		int flags = 0;

		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}


		//initialize the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);



		if (m_pWindow != 0)
		{
			//window creation successful

			//set up renderer
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{
				//renderer creation successful
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 255, 255);
			}
			else
			{
				//renderer init failed
				return false;
			}
		}
		else
		{
			//SDL Init failed
			return false;
		}

		//init success! start running the main loop
		m_bRunning = true;

		return true;
	}

	//init failed
	return false;
}

void Game::prepare()
{
	//spider = Sprite(m_pRenderer, "spider.png" <- file, (0<-starting corner_>, 34,) (45, 45square height and width),
	//( 320, 240) destinate locations top left corner, (52, 52)destinated size);
	background = Sprite(m_pRenderer, "newbackground.png", 0, 0, 640, 480, 0, 0, 640, 480);
	spider1 = Sprite(m_pRenderer, "spider.png", 0,34,45, 45, 420,240,100,100);
	spider2 = Sprite(m_pRenderer, "spider.png", 0, 197, 40, 62, 220, 0, 100, 100);
	spider3 = Sprite(m_pRenderer, "spider.png", 481, 39, 39, 39, 75, 300, 80, 80);
	projectile = Sprite(m_pRenderer, "web.png", 26, 14, 82, 84, 220, 150, 100, 100);
	hero = Sprite(m_pRenderer, "web.png", 26, 14, 82, 84, 220, 150, 100, 100);
	deltaTime = 1.0f / targetFramerate;
	cFStartTime = SDL_GetTicks();

	//we are ready to start our game loop
}

void Game::handleEvents()
{ 
	SDL_Event event;
	if (event.type == SDL_QUIT)
	{
		m_bRunning = false;
	}
	else if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			hero.velY = -1;
			break;

		case SDLK_DOWN:
			hero.velY = 1;
			break;

		case SDLK_LEFT:
			hero.velX = -1;
			break;

		case SDLK_RIGHT:
			hero.velX = 1;
			break;

		default:
			break;
		}

	}
}

void Game::update()
{
	hero.moveBy(hero.velX, hero.velY);

}

void Game::render()
{
	//clear the renderer to draw color
	SDL_RenderClear(m_pRenderer);

	//render the background
	background.draw(m_pRenderer);

	//render the shark
	spider1.draw(m_pRenderer);
	spider2.draw(m_pRenderer); 
	spider3.draw(m_pRenderer);
	projectile.draw(m_pRenderer);
	hero.draw(m_pRenderer);
	obstacle.draw(m_pRenderer);
	//draw to the screen
	SDL_RenderPresent(m_pRenderer);
}

void Game::waitForFrame()
{
	Uint32 gameTimeMs = SDL_GetTicks();

	//Step 2: Calculate how much time has passed since the current frame started
	tSinceLastFrame = gameTimeMs - cFStartTime;

	//Step 3: If the frame started less than the total allocated time for the frame
	if (tSinceLastFrame < frameDelayMs)
	{
		//Step 4: Halt the execution until the allocated time for the frame passes
		SDL_Delay(frameDelayMs - tSinceLastFrame);
	}

	//Step 5: Store the time when this frame ends
	cFEndTime = SDL_GetTicks();

	//Step 6: Calculate deltaTime (how much time it took for the frame to be completed)
	deltaTime = (cFEndTime - cFStartTime) / 1000.f;

	//Step 7: Set current game time (in seconds)
	gameTime = cFEndTime / 1000.0f;

	//Step 8: Set the start time of the current frame to be the end time, so that the next time this function runs, 
	//		  we take the current end time as the new frame's start time
	cFStartTime = cFEndTime;

	//for testing:
	//std::cout << gameTime << " - " << deltaTime << std::endl;
}


void Game::cleanup()
{
	//cleaning game

	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

