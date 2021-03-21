#include "Game.h"
#include <iostream>

Game::Game()
{
}

Game::~Game()
{
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		int flags = 0;

		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}

		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);



		if (m_pWindow != 0)
		{
			
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{
	
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 255, 255);
			}
			else
			{
			
				return false;
			}
		}
		else
		{
	
			return false;
		}

		return true;
	}

	return false;
}

void Game::prepare()
{
	background = Sprite(m_pRenderer, "newBackground.png", 0, 0, 640, 480, 0, 0, 640, 480);
	hero = Hero(m_pRenderer, "hero2.png",0,0,40,55, 0, 195,85,85);
	spider1 = Sprite(m_pRenderer, "spider.png", 0, 34, 46, 47, 250, 250, 85, 85);
	spider2 = Sprite(m_pRenderer, "spider.png", 0, 34, 46, 47, 300, 220, 85, 85);
	bullets = BulletList();

	deltaTime = 1.0f / targetFramerate;
	currentFrameStartTime = SDL_GetTicks();

	m_bRunning = true;
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			m_bRunning = false;
		}
		else if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				hero.velY = -1;
				break;

			case SDLK_s:
				hero.velY = 1;
				break;

			case SDLK_a:
				hero.velX = -1;
				break;

			case SDLK_d:
				hero.velX = 1;
				break;

			case SDLK_SPACE:
				bullets.AddBullet(m_pRenderer, hero.getWeaponX(), hero.getWeaponY());
				break;

			default:
				break;
			}

		}
		else if (event.type == SDL_KEYUP)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				hero.velY = 0;
				break;

			case SDLK_s:
				hero.velY = 0;
				break;

			case SDLK_a:
				hero.velX = 0;
				break;

			case SDLK_d:
				hero.velX = 0;
				break;

			case SDLK_ESCAPE:
				m_bRunning = false;
				break;

			default:
				break;
			}
		}
	}

}

void Game::update()
{
	hero.moveBy(hero.velX, hero.velY);
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	background.draw(m_pRenderer);

	hero.draw(m_pRenderer);

	spider1.draw(m_pRenderer);

	spider2.draw(m_pRenderer);

	bullets.UpdateBullets(m_pRenderer);

	SDL_RenderPresent(m_pRenderer);
}

void Game::waitForNextFrame()
{
	Uint32 gameTimeMs = SDL_GetTicks();

	timeSinceLastFrame = gameTimeMs - currentFrameStartTime;

	if (timeSinceLastFrame < frameDelayMs)
	{
		SDL_Delay(frameDelayMs - timeSinceLastFrame);
	}

	currentFrameEndTime = SDL_GetTicks();

	deltaTime = (currentFrameEndTime - currentFrameStartTime) / 1000.f;

	gameTime = currentFrameEndTime / 1000.0f;

	currentFrameStartTime = currentFrameEndTime;
}

void Game::cleanup()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
