#include "EnemyChaser.h"
#include "TestEnemy.h"

EnemyChaser::EnemyChaser(SDL_Texture* texturesheet, ID id, float x, float y, float velx, float vely, int HP, SDL_Renderer* rend, std::vector<GameObject*> &Entities) : GameObject(texturesheet, id, x, y, velx, vely, HP, rend) {
	this->HP = HP;
	for (int i = 0; i < Entities.size(); i++) {
		if (Entities[i]->getID() == Player1) {
			PlayerToChase = Entities[i];
			break;
		}

	}

}

SDL_Rect EnemyChaser::getBounds() {
	SDL_Rect rect;
	rect.x = (int)xpos;
	rect.y = (int)ypos;
	rect.w = 64;
	rect.h = 64;
	return rect;


}

EnemyChaser* EnemyChaser::clone() const
{
	return new EnemyChaser(*this);
}

EnemyChaser::~EnemyChaser() {
	SDL_DestroyTexture(objTexture);
	//delete this;
}


void EnemyChaser::Update() {


	xpos += velx;
	ypos += vely;
	
	float diffX = xpos - PlayerToChase->getX();
	float diffY = ypos - PlayerToChase->getY();
	float distance = sqrt((xpos - PlayerToChase->getX()) * (xpos - PlayerToChase->getX()) + (ypos - PlayerToChase->getY()) * (ypos - PlayerToChase->getY()));

	velx = ((-1 / distance) * diffX*2.2);
	vely = ((-1 / distance) * diffY*2.2);

}
void EnemyChaser::Render() {
	srcRect.h = 128;
	srcRect.w = 128;
	srcRect.x = 0;
	srcRect.y = 32;

	destRect.x = (int)xpos;
	destRect.y = (int)ypos;
	destRect.w = srcRect.w / 2;
	destRect.h = srcRect.h / 2;

	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
void EnemyChaser::OnHit() {

}
