#include "TextureFactory.h"

TextureFactory::TextureFactory(SDL_Renderer* ren)
{
	this->ren = ren;
}

SDL_Texture* TextureFactory::getTexture(const char* texturesheet)
{
	
	if (this->Fw.find(texturesheet) == this->Fw.end()) {
		SDL_Surface* tempSurface = IMG_Load(texturesheet);
		SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
		this->Fw.insert(std::make_pair(texturesheet, tex));
		SDL_FreeSurface(tempSurface);
	}
	return this->Fw.at(texturesheet);
}
