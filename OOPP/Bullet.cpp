#include "Bullet.h"


Bullet::Bullet(const char* texturesheet,ID id, int x, int y, int velx, int vely, int bulletDamage, int bulletRange, SDL_Renderer* rend) : GameObject(texturesheet,id, x, y, velx, vely,HP,rend) {
	HP = bulletRange;
	damage = bulletDamage;
}
Bullet::~Bullet(){
	SDL_DestroyTexture(objTexture);
}
SDL_Rect Bullet::getBounds() {
	SDL_Rect rect;
	rect.x = xpos;
	rect.y = ypos;
	rect.w = 32;
	rect.h = 32;
	return rect;
}
void Bullet::Update(std::vector<GameObject*>& Entities, int &index) {
	bool del = false;
	if (HP > 0) {

		/*
		srcRect.h = 32;
		srcRect.w = 32;
		srcRect.x = 0;
		srcRect.y = 0;

		xpos += velx;
		ypos += vely;
		/*
		//Ricochet
		if (xpos + srcRect.w > WIDTH || xpos < 0)
			velx *= -1;
		if (ypos + srcRect.h > HEIGHT || ypos < 0)
			vely *= -1;

		*/
		/*
		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = srcRect.w;
		destRect.h = srcRect.h;*/

		xpos += velx;
		ypos += vely;

		SDL_Rect A = getBounds();
		for (int i = 0; i < Entities.size(); i++) {
			if (Entities[i]->getID() == Enemy) {
				SDL_Rect B = Entities[i]->getBounds();
				if (A.x + A.w >= B.x && B.x + B.w >= A.x && A.y + A.h >= B.y && B.y + B.h >= A.y) {

					Entities[i]->setHP(Entities[i]->getHP() - damage);
					if (Entities[i]->getHP() <= 0) {
						std::cout << "Killed Enemy " << i << std::endl;
						Entities.erase(Entities.begin() + i);
						//std::cout << "Test";
						//delete E[i];
						Entities.shrink_to_fit();
						//i--;
						index--;
						HP = 1;
						break;
					}
					else {
						std::cout << "Hit Enemy " << i << std::endl;
						Entities[i]->OnHit(); //For sound effects and particles
						HP = 1;
					}

					//HP = 1;
				}
			}
		}

		HP--;

		if (HP <= 0) {
			del = true;
			//delete this;
		}

		if (del) {
			Entities.erase(Entities.begin() + index);
			index--;
			//E.shrink_to_fit();//Maybe?
			delete this;
		}


	}
	else {
		Entities.erase(Entities.begin() + index);
		delete this;
	}
	

}
void Bullet::Render() {

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
	
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

void Bullet::OnHit() {

}

