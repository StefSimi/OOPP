#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "Handler.h"
#include <vector>
#include <list>

class Game
{
public:
	Game(const char* title, int width, int height, bool fullscreen);
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