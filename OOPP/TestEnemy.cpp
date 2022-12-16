#include "TestEnemy.h"

TestEnemy::TestEnemy(const char* texturesheet,ID id, int x, int y, int velx, int vely,int HP, SDL_Renderer* rend) : GameObject(texturesheet,id, x, y, velx, vely,HP,rend) {
	this->HP = HP;

}

SDL_Rect TestEnemy::getBounds() {
	SDL_Rect rect;
	rect.x = xpos;
	rect.y = ypos;
	rect.w = 64;
	rect.h = 64;
	return rect;
	

}

TestEnemy::~TestEnemy() {
	//free texture
	delete this;
}

/*void TestEnemy::setHP(int HP) {
	this->HP = HP;
}

int TestEnemy::getHP() {
	return HP;
}*/

void TestEnemy::Update() {
	

	xpos += velx;
	ypos += vely;

	if (xpos + srcRect.w / 2 > WIDTH-32 || xpos < 32)
		velx *= -1;
	if (ypos + srcRect.h / 2 > HEIGHT-32 || ypos < 32)
		vely *= -1;



	

}
void TestEnemy::Render() {
	srcRect.h = 128;
	srcRect.w = 128;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w / 2;
	destRect.h = srcRect.h / 2;

	SDL_RenderCopy(renderer,objTexture, &srcRect, &destRect);
}
void TestEnemy::OnHit() {
	
}
