#include "Game.h"

Game* g_game = 0;

int main(int argc, char* args[])
{
	g_game = new Game();

	g_game->init("SpiderBeach", 100, 100, 640, 480, false);

	g_game->prepare();

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
		g_game->waitForNextFrame();
	}

	g_game->cleanup();

	return 0;
}







