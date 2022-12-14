#include "Player.h"
#include "Bullet.h"

//Bullet* b;
//int testbullet = 0;
Player::Player(const char* texturesheet,ID id, int x, int y,int HP, SDL_Renderer* rend) : GameObject(texturesheet,id, x, y, velx, vely,HP,rend) {
	this->HP = HP;

}
/*
void Player::setHP(int HP) {
	this->HP = HP;
}

int Player::getHP(){
	return HP;
}
*/
SDL_Rect Player::getBounds() {
	SDL_Rect rect;
	rect.x = xpos;
	rect.y = ypos;
	rect.w = 12*4;//Perhaps *4
	rect.h = 27*4;
	return rect;

}
std::ostream& operator<<(std::ostream& os,   Player* p) {
	if (p->HP<0) {
		os << "You died.\n";
		return os;
	}
	os<<"HP= " <</*reinterpret_cast<int*>*/ p->HP<<"\n";
	return os;
}

void Player::setKeyDown(int index, bool value) {
	keyDown[index] = value;
}
bool Player::getKeyDown(int index) {
	return keyDown[index];
}


void Player::Update(std::vector<GameObject*>&Enemies, std::vector<Bullet*>& Bullets, bool &running ) {
	

	currenthitDelay = Clamp(currenthitDelay-1, 0, 60);
	currentbulletDelay = Clamp(currentbulletDelay - 1, 0, 100);

	if (Game::event.type == SDL_KEYDOWN) {
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			vely = -speed;
			keyDown[0] = true;
			break;
		case SDLK_s:
			vely = speed;
			keyDown[1] = true;
			break;
		case SDLK_a:
			velx = -speed;
			keyDown[2] = true;
			break;
		case SDLK_d:
			velx = speed;
			keyDown[3] = true;
			break;
		case SDLK_UP:
			if (currentbulletDelay == 0) {
				currentbulletDelay = bulletDelay;
				Enemies.push_back(new Bullet("assets/Bullet.png", PlayerBullet, xpos, ypos, 0 + velx, -speed-3 + vely / 2,bulletDamage, bulletRange, renderer));
			}
			break;
		case SDLK_DOWN:
			if (currentbulletDelay == 0) {
				currentbulletDelay = bulletDelay;
				Enemies.push_back(new Bullet("assets/Bullet.png", PlayerBullet, xpos, ypos, 0 + velx, speed+3 + vely / 2, bulletDamage, bulletRange, renderer));
			}
			break;
		case SDLK_LEFT:
			if (currentbulletDelay == 0) {
				currentbulletDelay = bulletDelay;;
				Enemies.push_back(new Bullet("assets/Bullet.png", PlayerBullet, xpos, ypos, -speed-3 + velx / 2, 0 + vely, bulletDamage, bulletRange, renderer));
			}
			break;
		case SDLK_RIGHT:
			if (currentbulletDelay == 0) {
				currentbulletDelay = bulletDelay;
				Enemies.push_back(new Bullet("assets/Bullet.png", PlayerBullet, xpos, ypos, speed+3 + velx / 2, 0 + vely, bulletDamage, bulletRange, renderer));
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
			//vely = 0;
			keyDown[0] = false;
			break;
		case SDLK_s:
			//vely = 0;
			keyDown[1] = false;
			break;
		case SDLK_a:
			//velx = 0;
			keyDown[2] = false;
			break;
		case SDLK_d:
			//velx = 0;
			keyDown[3] = false;
			break;
		default:
			break;
		}
		if (!keyDown[0] && !keyDown[1])
			vely = 0;
		if (!keyDown[2] && !keyDown[3])
			velx = 0;
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

	
	xpos=Clamp(xpos+velx, 32, WIDTH - destRect.w-32);
	ypos=Clamp(ypos+vely, 32, HEIGHT - destRect.h-32);


	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w *4;
	destRect.h = srcRect.h *4;


	SDL_Rect A = getBounds();
	for (int i = 0; i < Enemies.size(); i++) {
		if (Enemies[i]->getID() == Enemy) {
			SDL_Rect B = Enemies[i]->getBounds();
			if (A.x + A.w >= B.x && B.x + B.w >= A.x && A.y + A.h >= B.y && B.y + B.h >= A.y && currenthitDelay == 0) {
				HP--;
				currenthitDelay = hitDelay;

				std::cout << this;
			}
		}
	}

	//COMMENT IF DEBUGGING
	if (HP < 0) { running = false; }
		
	

	


	/*for (int bull = 0; bull < Bullets.size(); bull++) {//DO NOT TOUCH CURSED AF
		bool del = false;
		//std::cout << Bullets.size()<<std::endl;

		if (Bullets[bull]->getHP() > 0) {
			Bullets[bull]->Update(Enemies, del);
			if (del == true) {
				Bullets.erase(Bullets.begin() + bull);
				bull--;//Maybe
				Bullets.shrink_to_fit();
				delete Bullets[bull];
			}

		}
		else {
			Bullets.erase(Bullets.begin() + bull);
		}

	}*/

	
}

void Player::Render() {
	/*for (int bull = 0; bull < Bullets.size(); bull++) {
		if(Bullets[bull]->getHP()>=0)
			Bullets[bull]->Render();

	}*/

	/*
	if (testbullet)
		if (b->getHP() >= 0)
			b->Render();
		else
			testbullet = 0;
	*/
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
	
}

void Player::OnHit() {

}
