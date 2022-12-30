#include "Game.h"
#include <time.h>
#define WIDTH 800
#define HEIGHT 640

Game* game = nullptr;

int main(int argc, char* argv[])
{
	srand(time(NULL));
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;


	//game = new Game("Window", WIDTH, HEIGHT, false);
	game = Game::getInstance("Window", WIDTH, HEIGHT, false);
	//game->init("GameWindow", 800, 600, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks()-frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}

	}

	//game->clean();
	delete game;
	return 0;
}