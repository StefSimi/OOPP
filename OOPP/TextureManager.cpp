#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture,SDL_Renderer* rend) {
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_Renderer* rend)
{
	SDL_RenderCopy(rend, tex, &src, &dest);
}
