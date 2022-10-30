#include "Player.h"
#include "Bullet.h"

Bullet* b;
int testbullet = 0;
Player::Player(const char* texturesheet, int x, int y,int HP, SDL_Renderer* rend) : GameObject(texturesheet, x, y, velx, vely,rend) {
	this->HP = HP;

}

void Player::setHP(int HP) {
	this->HP = HP;
}

int Player::getHP(){
	return HP;
}

SDL_Rect Player::getBounds() {
	SDL_Rect rect;
	rect.x = xpos;
	rect.y = ypos;
	rect.w = 12*4;//Perhaps *4
	rect.h = 27*4;
	return rect;

}
std::ostream& operator<<(std::ostream& os,   Player* p) {
	if (!p->HP) {
		os << "H(o)P(e) Missing";
		return os;
	}
	os<<"HP= " <</*reinterpret_cast<int*>*/ p->HP<<"\n";
	return os;
}



void Player::Update(TestEnemy* E[], int EnemySize) {
	

	if (Game::event.type == SDL_KEYDOWN) {
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			vely = -5;
			break;
		case SDLK_s:
			vely = 5;
			break;
		case SDLK_a:
			velx = -5;
			break;
		case SDLK_d:
			velx = 5;
			break;
		case SDLK_UP:
			if (testbullet == 0) {
				testbullet = 1;
				b = new Bullet("assets/Bullet.png", xpos, ypos, 0+velx, -8+vely/2, renderer, 50);
			}
			break;
		case SDLK_DOWN:
			if (testbullet == 0) {
				testbullet = 1;
				b = new Bullet("assets/Bullet.png", xpos, ypos, 0+velx, 8+vely/2, renderer, 50);
			}
			break;
		case SDLK_LEFT:
			if (testbullet == 0) {
				testbullet = 1;
				b = new Bullet("assets/Bullet.png", xpos, ypos, -8+velx/2, 0+vely, renderer, 50);
			}
			break;
		case SDLK_RIGHT:
			if (testbullet == 0) {
				testbullet = 1;
				b = new Bullet("assets/Bullet.png", xpos, ypos, 8+velx/2, 0+vely, renderer, 50);
			}
			break;
		default:
			break;
		
		}
	}
	if (Game::event.type == SDL_KEYUP) {
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			vely = 0;
			break;
		case SDLK_s:
			vely = 0;
			break;
		case SDLK_a:
			velx = 0;
			break;
		case SDLK_d:
			velx = 0;
			break;
		default:
			break;
		}
	}
	if (velx < 0)
		srcRect.x = 13;
	else
		if(velx>0)
		srcRect.x = 0;


	srcRect.h = 27;
	srcRect.w = 12;
	//srcRect.x = 0;
	srcRect.y = 0;

	
	xpos=Clamp(xpos+velx, 0, WIDTH - destRect.w);
	ypos=Clamp(ypos+vely, 0, HEIGHT - destRect.h);


	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w *4;
	destRect.h = srcRect.h *4;


	SDL_Rect A = getBounds();
	for (int i = 0; i < EnemySize; i++) {
		SDL_Rect B = E[i]->getBounds();
		if (A.x + A.w >= B.x && B.x + B.w >= A.x && A.y + A.h >= B.y && B.y + B.h >= A.y) {
			HP--;
			std::cout << this;
		}
	}
	if (HP <= 0) {
		//delete E[2];
		//size--;
		
		HP = 100;
	}

	//collision(enemy, size);
	if(testbullet)
		if (b->getLifespan() >= 0)
			b->Update(E,3);
		
	

}

void Player::Render() {
	if (testbullet)
		if (b->getLifespan() >= 0)
			b->Render();
		else
			testbullet = 0;
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}