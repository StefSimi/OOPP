#include "Bullet.h"


Bullet::Bullet(SDL_Texture* texturesheet,ID id, float x, float y, float velx, float vely, int bulletDamage, int bulletRange, SDL_Renderer* rend) : GameObject(texturesheet,id, x, y, velx, vely,HP,rend) {
	HP = bulletRange;
	damage = bulletDamage;
}
Bullet::~Bullet(){
	//SDL_DestroyTexture(objTexture);
	//delete this;
}
SDL_Rect Bullet::getBounds() {
	SDL_Rect rect;
	rect.x = xpos;
	rect.y = ypos;
	rect.w = 32;
	rect.h = 32;
	return rect;
}
void Bullet::Update(std::vector<GameObject*>& Entities,TextureFactory* TF, int &index, bool rico) {
	bool del = false;
	if (HP > 0) {

		if (rico&&id==PlayerBullet) {

			if (xpos + srcRect.w > WIDTH-32 || xpos < 32)
				velx *= -1;
			if (ypos + srcRect.h > HEIGHT-32 || ypos < 32)
				vely *= -1;
		}
		
		
		xpos += velx;
		ypos += vely;

		SDL_Rect A = getBounds();
		for (int i = 0; i < Entities.size(); i++) {
			if (id==PlayerBullet&& (Entities[i]->getID() == Enemy|| Entities[i]->getID() == Boss)) {
				SDL_Rect B = Entities[i]->getBounds();
				if (A.x + A.w >= B.x && B.x + B.w >= A.x && A.y + A.h >= B.y && B.y + B.h >= A.y) {

					Entities[i]->setHP(Entities[i]->getHP() - damage);
					if (Entities[i]->getHP() <= 0) {
						if (rand() % 4 == 2) {
							Entities.push_back(new Item(TF->getTexture("assets/Heart.png"), PassiveItem, Entities[i]->getX(),Entities[i]->getY(), renderer, 2));
						}
						//std::cout << "Killed Enemy " << i << std::endl;
						Game::score += Entities[i]->getKillScore();
						Entities.erase(Entities.begin() + i);
						Entities.shrink_to_fit();
						
						index--;
						HP = 1;
						break;
					}
					else {
						//std::cout << "Hit Enemy " << i << std::endl;
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

	
	destRect.x = (int)xpos;
	destRect.y = (int)ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
	
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

void Bullet::OnHit() {

}

Bullet* Bullet::clone() const
{
	return new Bullet(*this);
}

