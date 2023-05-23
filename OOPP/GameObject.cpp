#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject() {
	objTexture = NULL;
	xpos = 0;
	ypos = 0;
}

GameObject::GameObject(SDL_Texture* texturesheet,ID id, float x, float y, float velx, float vely,int HP, SDL_Renderer* ren) {
	renderer = ren;
	objTexture = texturesheet;
	xpos = x;
	ypos = y;
	this->velx = velx;
	this->vely = vely;
	this->HP = HP;
	this->id = id;

}
GameObject::~GameObject() {
	//SDL_DestroyTexture(objTexture);
}

void GameObject::Update() {
	
}


void GameObject::Render() {
	//SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);


}

void GameObject::setX(float x) {
	xpos = x;
}
void GameObject::setY(float y) {
	ypos = y;
}
void GameObject::setID(ID id) {
	this->id = id;
}
void GameObject::setVelX(float velx) {
	this->velx = velx;
}
void GameObject::setVelY(float vely) {
	this->vely = vely;
}
void GameObject::setHP(int HP) {
	this->HP = HP;
}

float GameObject::getX() {
	return xpos;
}
float GameObject::getY() {
	return ypos;
}
ID GameObject::getID() {
	return id;
}
float GameObject::getVelX() {
	return velx;
}
float GameObject::getVelY() {
	return vely;
}


int GameObject::getHP() {
	return HP;
}

int GameObject::getKillScore()
{
	return killScore;
}


const float GameObject::Clamp(float value, float min, float max) {
	if (value >= max)
		return value = max;
	else if (value <= min)
		return value = min;
	else return value;
}