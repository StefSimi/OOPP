#pragma once
#include "SDL.h"
class HUD {
	public:
	HUD(SDL_Texture* texturesheet, SDL_Renderer* ren);
	~HUD();
	void render(int HP);
	private:
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};