#include "Game.h"
#include <time.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <nlohmann/json.hpp>
#include "JsonObject.h"


using json = nlohmann::json;


#define WIDTH 800
#define HEIGHT 640

Game* game = nullptr;
int publicscore = 0;
JsonObject jo;
int main(int argc, char* argv[])
{
	srand(time(NULL));
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;
    std::string playerName;
    std::cout << "Enter player name:\n";
    std::cin >> playerName;


	//game = new Game("Window", WIDTH, HEIGHT, false);
	game = Game::getInstance("OOPP", WIDTH, HEIGHT, false);
	//game->init("GameWindow", 800, 600, false);
    //game->score = 0;
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
    std::cout << Game::score<<"\n";
    jo.updateTop5Scores(playerName, Game::score);
    jo.updatePlayerHighestScore(playerName,Game::score);
	delete game;





	return 0;
}