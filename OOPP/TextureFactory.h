#pragma once
#ifndef B_Included
#define B_Included


#include "Game.h"
#include "TextureManager.h"
#include <unordered_map>


class TextureFactory {


	public: 
		TextureFactory(SDL_Renderer* ren);
		SDL_Texture* getTexture(const char *texturesheet);
	private:
		std::unordered_map<const char*, SDL_Texture*> Fw;
		SDL_Renderer* ren;

};
#endif