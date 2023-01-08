#include "Player.h"
#include "Bullet.h"

Player::Player(SDL_Texture* texturesheet,ID id, float x, float y,int HP, SDL_Renderer* rend) : GameObject(texturesheet,id, x, y, velx, vely,HP,rend) {
	this->HP = HP;

}
Player::Player(SDL_Texture* texturesheet,IDGenerator &id_generator, float x, float y, int HP, SDL_Renderer* rend) : GameObject(texturesheet, id, x, y, velx, vely, HP, rend) {
	this->HP = HP;
	id = (ID) id_generator.getNextID();
	std::cout << id << "Testing" << std::endl;

}

SDL_Rect Player::getBounds() {
	SDL_Rect rect;
	rect.x = (int)xpos;
	rect.y = (int)ypos;
	rect.w = 16*3;
	rect.h = 32*3;
	return rect;

}
std::ostream& operator<<(std::ostream& os, Player* p) {
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
void Player::clearBullets(std::vector<GameObject*>& Entities)
{
	for (int i = 0; i < Entities.size(); i++) {
		if (Entities[i]->getID() == PlayerBullet) {
			Entities[i]->setHP(1);
		}
	}
}
bool Player::getKeyDown(int index) {
	return keyDown[index];
}

bool Player::getRico()
{
	return hasRico;
}


void Player::Update(TextureFactory* TF,std::vector<GameObject*>&Entities, bool &running,Map *map) {
	try {


	

		xpos = Clamp(xpos + velx, 32, WIDTH - destRect.w - 32);
		ypos = Clamp(ypos + vely, 32, HEIGHT - destRect.h - 32);
		//std::cout << map->getCurrentRoom()->getcleared();
		if (map->getCurrentRoom()->getcleared()) {
			if (ypos <= 32 && xpos >= 336 && xpos <= 400&&map->getCurrentRoom()->getNorth()!=nullptr) {
				positionPlayer(2);
				clearBullets(Entities);
				map->enterRoom(map->getCurrentRoom(),renderer,TF,Entities,1);

			}
			if (ypos >= 500 && xpos >= 336 && xpos <= 400 && map->getCurrentRoom()->getSouth ()!= nullptr) {
				positionPlayer(1);
				clearBullets(Entities);
				map->enterRoom(map->getCurrentRoom(), renderer, TF, Entities, 2);
			}

			if (xpos >= 720 && ypos >= 206 && ypos <= 270 && map->getCurrentRoom()->getEast() != nullptr) {
				positionPlayer(4);
				clearBullets(Entities);
				map->enterRoom(map->getCurrentRoom(), renderer, TF, Entities, 3);
			}

			if (xpos <= 32 && ypos >= 206 && ypos <= 270 && map->getCurrentRoom()->getWest() != nullptr) {
				positionPlayer(3);
				clearBullets(Entities);
				map->enterRoom(map->getCurrentRoom(), renderer, TF, Entities, 4);
			}

		}

		currenthitDelay = Clamp(currenthitDelay - 1, 0, 60);
		currentbulletDelay = Clamp(currentbulletDelay - 1, 0, 100);
		
		if (Game::event.type == SDL_KEYDOWN) {
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				keyDown[0] = true;
				break;
			case SDLK_s:
				keyDown[1] = true;
				break;
			case SDLK_a:
				keyDown[2] = true;
				break;
			case SDLK_d:
				keyDown[3] = true;
				break;
			case SDLK_UP:
				keyDown[4] = true;
				break;
			case SDLK_DOWN:
				keyDown[5] = true;
				break;
			case SDLK_LEFT:
				keyDown[6] = true;
				break;
			case SDLK_RIGHT:
				keyDown[7] = true;
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
			case SDLK_UP:
				keyDown[4] = false;
				break;
			case SDLK_DOWN:
				keyDown[5] = false;
				break;
			case SDLK_LEFT:
				keyDown[6] = false;
				break;
			case SDLK_RIGHT:
				keyDown[7] = false;
				break;

			default:
				break;
			}
			

			

		}
		if (!keyDown[0] && !keyDown[1])
			vely = 0;
		if (!keyDown[2] && !keyDown[3])
			velx = 0;
		if (keyDown[0] == true) {
			vely = -speed;
		}
		if (keyDown[1] == true) {
			vely = speed;
		}
		if (keyDown[2] == true) {
			velx = -speed;
		}
		if (keyDown[3] == true) {
			velx = speed;
		}
		if (keyDown[0] && keyDown[1]) {
			vely = 0;
		}
		if (keyDown[2] && keyDown[3]) {
			velx = 0;
		}
		if (keyDown[0] && keyDown[2]) {
			vely= -speed / sqrt(2);
			velx = -speed / sqrt(2);
		}
		if (keyDown[0] && keyDown[3]) {
			vely = -speed / sqrt(2);
			velx = speed / sqrt(2);
		}
		if (keyDown[1] && keyDown[2]) {
			vely = speed / sqrt(2);
			velx = -speed / sqrt(2);
		}
		if (keyDown[1] && keyDown[3]) {
			vely = speed / sqrt(2);
			velx = speed / sqrt(2);
		}
		//std::cout << velx << " " << vely << std::endl;

		if (keyDown[4] == true && currentbulletDelay == 0) {
			Entities.push_back(new Bullet(TF->getTexture("assets/Bullet.png"), PlayerBullet, xpos, ypos, 0 + velx, -speed - 3 + vely / 2, bulletDamage, bulletRange, renderer));
			currentbulletDelay = bulletDelay;
		}
		if (keyDown[5] == true && currentbulletDelay == 0) {
			Entities.push_back(new Bullet(TF->getTexture("assets/Bullet.png"), PlayerBullet, xpos, ypos, 0 + velx, speed + 3 + vely / 2, bulletDamage, bulletRange, renderer));
			currentbulletDelay = bulletDelay;
		}
		if (keyDown[6] == true && currentbulletDelay == 0) {
			Entities.push_back(new Bullet(TF->getTexture("assets/Bullet.png"), PlayerBullet, xpos, ypos, -speed - 3 + velx / 2, 0 + vely, bulletDamage, bulletRange, renderer));
			currentbulletDelay = bulletDelay;
		}
		if (keyDown[7] == true && currentbulletDelay == 0) {
			Entities.push_back(new Bullet(TF->getTexture("assets/Bullet.png"), PlayerBullet, xpos, ypos, speed + 3 + velx / 2, 0 + vely, bulletDamage, bulletRange, renderer));
			currentbulletDelay = bulletDelay;
		}
		
		

		SDL_Rect A = getBounds();
		for (int i = 0; i < Entities.size(); i++) {
			if (Entities[i]->getID() == Enemy|| Entities[i]->getID() == EnemyBullet || Entities[i]->getID() == Boss) {
				SDL_Rect B = Entities[i]->getBounds();
				if (A.x + A.w >= B.x && B.x + B.w >= A.x && A.y + A.h >= B.y && B.y + B.h >= A.y && currenthitDelay == 0) {
					getHit();
					//std::cout << "test in pll";
					//std::cout << this;
					if (Entities[i]->getID() == EnemyBullet)
						Entities[i]->setHP(1);
				}
			}
			if (Entities[i]->getID() == PassiveItem) {
				SDL_Rect B = Entities[i]->getBounds();
				if (A.x + A.w >= B.x && B.x + B.w >= A.x && A.y + A.h >= B.y && B.y + B.h >= A.y && currenthitDelay == 0) {
					Item* item = reinterpret_cast<Item*>(Entities[i]);
					switch (item->getType()) {
					case 1:
						hasRico = true;
						bulletRange += 40;
						break;
					case 2:
						HP++;
						break;
					default:
						break;
					}
					Entities.erase(Entities.begin() + i);
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
	
	//std::cout << xpos << " " << ypos << std::endl;
}

void Player::Render() {
	if (velx < 0)
		srcRect.x = 17;
	else
		if (velx > 0)
			srcRect.x = 0;


	srcRect.h = 32;
	srcRect.w = 16;
	//srcRect.x = 0;
	srcRect.y = 0;


	


	destRect.x = (int)xpos;
	destRect.y = (int)ypos;
	destRect.w = srcRect.w * 3;
	destRect.h = srcRect.h * 3;
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
	
}

void Player::OnHit() {

}

Player* Player::clone() const
{
	return new Player(*this);
}

void Player::getHit()
{
	if (currenthitDelay == 0) {
		HP--;
		currenthitDelay = hitDelay;
	}
}

void Player::positionPlayer(int entryway)
{
	switch (entryway) {
	case 1:
		//goes down
		xpos=(380);
		ypos=(33);
		break;
	case 2:
		//goes up
		xpos=(380);
		ypos=(499);
		break;
	case 3:
		//right
		xpos=(719);
		ypos=(250);
		break;
	case 4:
		//left
		xpos=(33);
		ypos=(250);
		break;
	default:
		break;

	}
}
