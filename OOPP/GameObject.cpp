#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject() {
	objTexture = NULL;
	xpos = 0;
	ypos = 0;
}

GameObject::GameObject(const char* texturesheet, int x, int y,int velx, int vely, SDL_Renderer* ren) {
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet,ren);
	xpos = x;
	ypos = y;
	this->velx = velx;
	this->vely = vely;

}

/*void GameObject::Update() {
	

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	if (Game::event.type == SDL_KEYDOWN) {
		switch (Game::event.key.keysym.sym)
		{
			case SDLK_w:
				//velx = 0;
				vely = -3;
				break;
			case SDLK_s:
				//velx = 0;
				vely = 3;
				break;
			case SDLK_a:
				velx = -3;
				//vely = 0;
				break;
			case SDLK_d:
				velx = 3;
				//vely = 0;
				break;
			default:
				break;
		}
	}
	if (Game::event.type == SDL_KEYUP) {
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			//velx = 0;
			vely = 0;
			break;
		case SDLK_s:
			//velx = 0;
			vely = 0;
			break;
		case SDLK_a:
			velx = 0;
			//vely = 0;
			break;
		case SDLK_d:
			velx = 0;
			//vely = 0;
			break;
		default:
			break;
		}
	}


	xpos += velx;
	ypos += vely;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 6;
	destRect.h = srcRect.h * 6;

}*/

/*void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);


}*/

void GameObject::setX(int x) {
	xpos = x;
}
void GameObject::setY(int y) {
	ypos = y;
}
void GameObject::setID(ID id) {
	this->id = id;
}
void GameObject::setVelX(int velx) {
	this->velx = velx;
}
void GameObject::setVelY(int vely) {
	this->vely = vely;
}

int GameObject::getX() {
	return xpos;
}
int GameObject::getY() {
	return ypos;
}
ID GameObject::getID() {
	return id;
}
int GameObject::getVelX() {
	return velx;
}
int GameObject::getVelY() {
	return vely;
}

const int GameObject::Clamp(int value, int min, int max) {
	if (value >= max)
		return value = max;
	else if (value <= min)
		return value = min;
	else return value;
}