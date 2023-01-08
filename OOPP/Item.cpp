#include "Item.h"

Item::Item(SDL_Texture* texturesheet, ID id, float x, float y, SDL_Renderer* rend,int type): GameObject(texturesheet, id, x, y, velx, vely, HP, rend)
{
	this->type = type;
}

void Item::Update()
{
}

void Item::Render()
{
	switch (type) {
	case 1:
		srcRect.h = 64;
		srcRect.w = 64;
		break;
	case 2:
		srcRect.h = 32;
		srcRect.w = 32;
		break;
	default:
		break;
	}
	srcRect.x = 0;
	srcRect.y = 0;
	destRect.x = (int)xpos;
	destRect.y = (int)ypos;
	destRect.w = srcRect.w ;
	destRect.h = srcRect.h ;

	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

void Item::OnHit()
{
}

SDL_Rect Item::getBounds()
{
	SDL_Rect rect;
	rect.x = (int)xpos;
	rect.y = (int)ypos;
	rect.w = 64;
	rect.h = 64;
	return rect;
}

Item* Item::clone() const
{
	return new Item(*this);
}

int Item::getType()
{
	return type;
}
