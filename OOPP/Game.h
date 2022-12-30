#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>
#include <list>
#include <memory>

class Game
{
protected:
	Game(const char* title, int width, int height, bool fullscreen);
	static Game* instance;
	

public:
	static Game *getInstance(const char* title, int width, int height, bool fullscreen);

	void operator=(const Game&) = delete;
	Game(Game& game) = delete;

	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	bool running() { return isRunning; } //inline foarte fancy;
	void render();
	void clean();

	SDL_Renderer* getRenderer();



	static SDL_Event event;
	
private:
	
	//Handler handler;
	bool isRunning = false;
	float cnt = 0;
	int testing = 1;
	SDL_Window* window;
	SDL_Renderer* renderer;
};