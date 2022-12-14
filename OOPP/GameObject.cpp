#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject() {
	objTexture = NULL;
	xpos = 0;
	ypos = 0;
}

GameObject::GameObject(const char* texturesheet,ID id, int x, int y, int velx, int vely,int HP, SDL_Renderer* ren) {
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);
	xpos = x;
	ypos = y;
	this->velx = velx;
	this->vely = vely;
	this->HP = HP;
	this->id = id;

}
GameObject::~GameObject() {
	SDL_DestroyTexture(objTexture);
}

void GameObject::Update() {
	
}


void GameObject::Render() {
	//SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);


}

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
void GameObject::setHP(int HP) {
	this->HP = HP;
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


int GameObject::getHP() {
	return HP;
}


const int GameObject::Clamp(int value, int min, int max) {
	if (value >= max)
		return value = max;
	else if (value <= min)
		return value = min;
	else return value;
}