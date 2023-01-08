#include "HUD.h"


HUD::HUD(SDL_Texture* texturesheet, SDL_Renderer* ren) {
	renderer = ren;
	objTexture = texturesheet;
}



HUD::~HUD()
{
}

void HUD::render(int HP)
{
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;
	destRect.y = 0;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
	for (int i = 1; i <= HP+1; i++) {
		destRect.x=36*i;
		SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
	}

}
