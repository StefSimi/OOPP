#include "Bullet.h"


Bullet::Bullet(const char* texturesheet, int x, int y, int velx, int vely, SDL_Renderer* rend, int lifespan) : GameObject(texturesheet, x, y, velx, vely,rend) {
	this->lifespan = lifespan;
}
Bullet::~Bullet(){
	
}
SDL_Rect Bullet::getBounds() {
	SDL_Rect rect;
	rect.x = xpos;
	rect.y = ypos;
	rect.w = 32;
	rect.h = 32;
	return rect;
}
void Bullet::Update(TestEnemy* E[], int EnemySize) {
	//std::cout << "debug";
	
	
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	xpos += velx;
	ypos += vely;
	//testing123

	/*Ricochet
	if (xpos + srcRect.w > WIDTH || xpos < 0)
		velx *= -1;
	if (ypos + srcRect.h > HEIGHT || ypos < 0)
		vely *= -1;

	*/

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

	SDL_Rect A = getBounds();
	for (int i = 0; i < EnemySize; i++) {
		SDL_Rect B = E[i]->getBounds();
		if (A.x + A.w >= B.x && B.x + B.w >= A.x && A.y + A.h >= B.y && B.y + B.h >= A.y) {
			std::cout << "Hit Enemy " << i << std::endl;
			lifespan = 1;
		}
	}

	lifespan--;
	if (lifespan <= 0)
		delete this;
	

}
void Bullet::Render() {
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}


int Bullet::getLifespan()
{
	return lifespan;
}

void Bullet::setLifespan(int x)
{
	lifespan = x;
}
