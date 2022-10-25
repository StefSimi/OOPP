#include "Player.h"


Player::Player(const char* texturesheet, int x, int y,int HP, SDL_Renderer* rend) : GameObject(texturesheet, x, y, velx, vely,rend) {
	this->HP = HP;

}

void Player::setHP(int HP) {
	this->HP = HP;
}

int Player::getHP(){
	return HP;
}

SDL_Rect Player::getBounds() {
	SDL_Rect rect;
	rect.x = xpos;
	rect.y = ypos;
	rect.w = 12*4;//Perhaps *4
	rect.h = 27*4;
	return rect;

}



void Player::Update() {
	

	if (Game::event.type == SDL_KEYDOWN) {
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			vely = -5;
			break;
		case SDLK_s:
			vely = 5;
			break;
		case SDLK_a:
			velx = -5;
			break;
		case SDLK_d:
			velx = 5;
			break;
		default:
			break;
		}
	}
	if (Game::event.type == SDL_KEYUP) {
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			vely = 0;
			break;
		case SDLK_s:
			vely = 0;
			break;
		case SDLK_a:
			velx = 0;
			break;
		case SDLK_d:
			velx = 0;
			break;
		default:
			break;
		}
	}
	if (velx < 0)
		srcRect.x = 13;
	else
		if(velx>0)
		srcRect.x = 0;


	srcRect.h = 27;
	srcRect.w = 12;
	//srcRect.x = 0;
	srcRect.y = 0;

	
	xpos=Clamp(xpos+velx, 0, WIDTH - destRect.w);
	ypos=Clamp(ypos+vely, 0, HEIGHT - destRect.h);


	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w *4;
	destRect.h = srcRect.h *4;

	//collision(enemy, size);

	std::cout << HP<<std::endl;

}

void Player::Render() {
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}