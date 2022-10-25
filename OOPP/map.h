#pragma once
#include "Game.h"
class Map
{
public:
	Map(SDL_Renderer* rend);
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap(SDL_Renderer* rend);
private:
	SDL_Rect src, dest;
	SDL_Texture* tile1;

	int map[20][25];
};

