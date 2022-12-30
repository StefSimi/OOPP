#include "EnemyCrawler.h"

EnemyCrawler::EnemyCrawler(SDL_Texture* texturesheet, ID id, float x, float y, int HP, SDL_Renderer* rend) : GameObject(texturesheet, id, x, y,velx,vely, HP, rend) {
	this->HP = HP;
	active = false;
	frameCounter = rand() % 20;
}

SDL_Rect EnemyCrawler::getBounds() {
	SDL_Rect rect;
	rect.x = (int)xpos;
	rect.y = (int)ypos;
	rect.w = 32;
	rect.h = 32;
	return rect;


}

EnemyCrawler* EnemyCrawler::clone() const
{
	return new EnemyCrawler(*this);
}

EnemyCrawler::~EnemyCrawler() {
	SDL_DestroyTexture(objTexture);
	//delete this;
}


void EnemyCrawler::Update() {

	frameCounter++;
	/*if (frameCounter % 60 == 0) {
		if (active) {
			velx = 0;
			vely = 0;
			active = false;
		}
		else {
			velx = (rand() % 2 - 1) * 7;
			vely = (rand() % 2 - 1) * 7;
			
			active = true;
		}
		frameCounter = 0;
	}
	*/
	if (frameCounter % 23 == 0) {
		velx = 0;
		vely = 0;
		active = false;
	}
	if (frameCounter % 83 == 0) {
		while (velx == 0 && vely == 0) {
			velx = (rand() % 7 - 3) * 2;
			vely = (rand() % 7 - 3) * 2;
		}
		active = true;
		frameCounter = 0;
	}

	if (active) {
		xpos = Clamp(xpos + velx, 32, WIDTH - destRect.w - 32);
		ypos = Clamp(ypos + vely, 32, HEIGHT - destRect.h - 32);
		if (xpos + srcRect.w / 2 > WIDTH - 32 || xpos < 32)
			velx *= -1;
		if (ypos + srcRect.h / 2 > HEIGHT - 32 || ypos < 32)
			vely *= -1;
	}
	
	

	



	

}
void EnemyCrawler::Render() {
	srcRect.h = 128;
	srcRect.w = 128;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = (int)xpos;
	destRect.y = (int)ypos;
	destRect.w = srcRect.w / 4;
	destRect.h = srcRect.h / 4;

	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
void EnemyCrawler::OnHit() {

}
