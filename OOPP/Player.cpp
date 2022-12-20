#include "Player.h"
#include "Bullet.h"

Player::Player(const char* texturesheet,ID id, float x, float y,int HP, SDL_Renderer* rend) : GameObject(texturesheet,id, x, y, velx, vely,HP,rend) {
	this->HP = HP;

}

SDL_Rect Player::getBounds() {
	SDL_Rect rect;
	rect.x = (int)xpos;
	rect.y = (int)ypos;
	rect.w = 12*4;
	rect.h = 27*4;
	return rect;

}
std::ostream& operator<<(std::ostream& os,   Player* p) {
	if (p->HP<0) {
		os << "You died.\n";
		return os;
	}
	os<<"HP= " << p->HP<<"\n";
	return os;
}

void Player::setKeyDown(int index, bool value) {
	keyDown[index] = value;
}
bool Player::getKeyDown(int index) {
	return keyDown[index];
}


void Player::Update(std::vector<GameObject*>&Entities, bool &running ) {
	try {
		xpos = Clamp(xpos + velx, 32, WIDTH - destRect.w - 32);
		ypos = Clamp(ypos + vely, 32, HEIGHT - destRect.h - 32);


		currenthitDelay = Clamp(currenthitDelay - 1, 0, 60);
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
					Entities.push_back(new Bullet("assets/Bullet.png", PlayerBullet, xpos, ypos, 0 + velx, -speed - 3 + vely / 2, bulletDamage, bulletRange, renderer));
				}
				break;
			case SDLK_DOWN:
				if (currentbulletDelay == 0) {
					currentbulletDelay = bulletDelay;
					Entities.push_back(new Bullet("assets/Bullet.png", PlayerBullet, xpos, ypos, 0 + velx, speed + 3 + vely / 2, bulletDamage, bulletRange, renderer));
				}
				break;
			case SDLK_LEFT:
				if (currentbulletDelay == 0) {
					currentbulletDelay = bulletDelay;;
					Entities.push_back(new Bullet("assets/Bullet.png", PlayerBullet, xpos, ypos, -speed - 3 + velx / 2, 0 + vely, bulletDamage, bulletRange, renderer));
				}
				break;
			case SDLK_RIGHT:
				if (currentbulletDelay == 0) {
					currentbulletDelay = bulletDelay;
					Entities.push_back(new Bullet("assets/Bullet.png", PlayerBullet, xpos, ypos, speed + 3 + velx / 2, 0 + vely, bulletDamage, bulletRange, renderer));
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
				keyDown[0] = false;
				break;
			case SDLK_s:
				keyDown[1] = false;
				break;
			case SDLK_a:
				keyDown[2] = false;
				break;
			case SDLK_d:
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
		


		SDL_Rect A = getBounds();
		for (int i = 0; i < Entities.size(); i++) {
			if (Entities[i]->getID() == Enemy) {
				SDL_Rect B = Entities[i]->getBounds();
				if (A.x + A.w >= B.x && B.x + B.w >= A.x && A.y + A.h >= B.y && B.y + B.h >= A.y && currenthitDelay == 0) {
					HP--;
					currenthitDelay = hitDelay;

					std::cout << this;
				}
			}
		}

		//COMMENT IF DEBUGGING
		if (HP < 0) { running = false; }

		if (xpos<0 || xpos>WIDTH || ypos < 0 ||ypos>HEIGHT)
			throw(xpos);

	}
	catch (int pos){
		std::cout << "Player out of bounds." << std::endl << "Xpos= " << xpos << std::endl << "Ypos= " << ypos << std::endl;

	}
	
}

void Player::Render() {
	if (velx < 0)
		srcRect.x = 13;
	else
		if (velx > 0)
			srcRect.x = 0;


	srcRect.h = 27;
	srcRect.w = 12;
	//srcRect.x = 0;
	srcRect.y = 0;


	


	destRect.x = (int)xpos;
	destRect.y = (int)ypos;
	destRect.w = srcRect.w * 4;
	destRect.h = srcRect.h * 4;
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
	
}

void Player::OnHit() {

}
