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
void Bullet::Update(std::vector<GameObject*>& E, int &index) {
	bool del = false;
	if (HP > 0) {
		//std::cout << "debug";


		srcRect.h = 32;
		srcRect.w = 32;
		srcRect.x = 0;
		srcRect.y = 0;

		xpos += velx;
		ypos += vely;

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
		for (int i = 0; i < E.size(); i++) {
			if (E[i]->getID() == Enemy) {
				SDL_Rect B = E[i]->getBounds();
				if (A.x + A.w >= B.x && B.x + B.w >= A.x && A.y + A.h >= B.y && B.y + B.h >= A.y) {

					E[i]->setHP(E[i]->getHP() - damage);
					if (E[i]->getHP() <= 0) {
						std::cout << "Killed Enemy " << i << std::endl;
						E.erase(E.begin() + i);
						//std::cout << "Test";
						//delete E[i];
						E.shrink_to_fit();
						//i--;
						index--;
						HP = 1;
						break;
					}
					else {
						std::cout << "Hit Enemy " << i << std::endl;
						E[i]->OnHit(); //For sound effects and particles
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
			E.erase(E.begin() + index);
			index--;
			//E.shrink_to_fit();//Maybe?
			delete this;
		}


	}
	else {
		E.erase(E.begin() + index);
		delete this;
	}
	

}
void Bullet::Render() {
	if (HP>=0)
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

void Bullet::OnHit() {

}

