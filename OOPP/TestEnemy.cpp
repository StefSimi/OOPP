#include "TestEnemy.h"

TestEnemy::TestEnemy(const char* texturesheet, int x, int y, int velx, int vely,int HP, SDL_Renderer* rend) : GameObject(texturesheet, x, y, velx, vely,HP,rend) {
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
	//delete this;
}

/*void TestEnemy::setHP(int HP) {
	this->HP = HP;
}

int TestEnemy::getHP() {
	return HP;
}*/

void TestEnemy::Update() {
	srcRect.h = 128;
	srcRect.w = 128;
	srcRect.x = 0;
	srcRect.y = 0;

	xpos += velx;
	ypos += vely;

	if (xpos + srcRect.w / 2 > WIDTH-32 || xpos < 32)
		velx *= -1;
	if (ypos + srcRect.h / 2 > HEIGHT-32 || ypos < 32)
		vely *= -1;



	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w /2;
	destRect.h = srcRect.h /2;

}
void TestEnemy::Render() {
	SDL_RenderCopy(renderer,objTexture, &srcRect, &destRect);
}