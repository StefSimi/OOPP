#include "TestEnemy.h"

TestEnemy::TestEnemy(const char* texturesheet, int x, int y, int velx, int vely, SDL_Renderer* rend) : GameObject(texturesheet, x, y, velx, vely,rend) {


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

void TestEnemy::Update() {
	srcRect.h = 128;
	srcRect.w = 128;
	srcRect.x = 0;
	srcRect.y = 0;

	xpos += velx;
	ypos += vely;

	if (xpos + srcRect.w / 2 > WIDTH || xpos < 0)
		velx *= -1;
	if (ypos + srcRect.h / 2 > HEIGHT || ypos < 0)
		vely *= -1;



	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w /2;
	destRect.h = srcRect.h /2;

}
void TestEnemy::Render() {
	SDL_RenderCopy(renderer,objTexture, &srcRect, &destRect);
}