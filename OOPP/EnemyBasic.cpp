#include "EnemyBasic.h"

EnemyBasic::EnemyBasic(SDL_Texture* texturesheet,ID id, float x, float y, float velx, float vely,int HP, SDL_Renderer* rend) : GameObject(texturesheet,id, x, y, velx, vely,HP,rend) {
	this->HP = HP;

}

SDL_Rect EnemyBasic::getBounds() {
	SDL_Rect rect;
	rect.x = (int)xpos;
	rect.y = (int)ypos;
	rect.w = 64;
	rect.h = 64;
	return rect;
	

}

EnemyBasic* EnemyBasic::clone() const
{
	return new EnemyBasic(*this);
}

EnemyBasic::~EnemyBasic() {
	//SDL_DestroyTexture(objTexture);
	//delete this;
}

/*void TestEnemy::setHP(int HP) {
	this->HP = HP;
}

int TestEnemy::getHP() {
	return HP;
}*/

void EnemyBasic::Update() {
	

	xpos += velx;
	ypos += vely;

	if (xpos + srcRect.w / 2 > WIDTH-32 || xpos < 32)
		velx *= -1;
	if (ypos + srcRect.h / 2 > HEIGHT-32 || ypos < 32)
		vely *= -1;



	

}
void EnemyBasic::Render() {
	srcRect.h = 128;
	srcRect.w = 128;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x =(int) xpos;
	destRect.y =(int) ypos;
	destRect.w = srcRect.w / 2;
	destRect.h = srcRect.h / 2;

	SDL_RenderCopy(renderer,objTexture, &srcRect, &destRect);
}
void EnemyBasic::OnHit() {
	
}
