#include "EnemyDobrovat.h"

EnemyDobrovat::EnemyDobrovat(SDL_Texture* texturesheet, ID id, float x, float y, float velx, float vely, int HP, SDL_Renderer* rend, std::vector<GameObject*>& Entities,Room* room)
	: GameObject(texturesheet, id, x, y, velx, vely, HP, rend)
{
	this->room = room;
	for (int i = 0; i < Entities.size(); i++) {
		if (Entities[i]->getID() == Player1) {
			PlayerToChase = Entities[i];
			break;
		}

	}
	setFloor();
	killScore = 500;
	/*
	18 23
	1->8

	11->18
	*/
}

EnemyDobrovat::~EnemyDobrovat()
{
}

void EnemyDobrovat::Update(std::vector<GameObject*>& Entities,TextureFactory* TF)
{
	switch (state) {
	case 0:
		vely = 1;
		ypos += vely;
		if (ypos >= 250)
			state = 1;
		break;
	case 1:
		counter++;
		eyeCounter++;
		vely = 0;
		velx = 0;
		if (counter == 60||counter==180) {
			Entities.push_back(new Bullet(TF->getTexture("assets/Bullet.png"), EnemyBullet, xpos+24, ypos, 4, 0, 1, 120, renderer));
			Entities.push_back(new Bullet(TF->getTexture("assets/Bullet.png"), EnemyBullet, xpos+24, ypos, 0, 4, 1, 120, renderer));
			Entities.push_back(new Bullet(TF->getTexture("assets/Bullet.png"), EnemyBullet, xpos+24, ypos, -4, 0, 1, 120, renderer));
			Entities.push_back(new Bullet(TF->getTexture("assets/Bullet.png"), EnemyBullet, xpos+24, ypos, 0, -4, 1, 120, renderer));
			Entities.push_back(new Bullet(TF->getTexture("assets/Bullet.png"), EnemyBullet, xpos + 24, ypos, -4, 1.5, 1, 120, renderer));
			Entities.push_back(new Bullet(TF->getTexture("assets/Bullet.png"), EnemyBullet, xpos + 24, ypos, 4, 1.5, 1, 120, renderer));
			Entities.push_back(new Bullet(TF->getTexture("assets/Bullet.png"), EnemyBullet, xpos + 24, ypos , -4, -1.5, 1, 120, renderer));
			Entities.push_back(new Bullet(TF->getTexture("assets/Bullet.png"), EnemyBullet, xpos + 24, ypos , 4, -1.5, 1, 120, renderer));

		}
		if (counter == 120||counter==240) {
			Entities.push_back(new Bullet(TF->getTexture("assets/Bullet.png"), EnemyBullet, xpos+24, ypos, 3, 3, 1, 120, renderer));
			Entities.push_back(new Bullet(TF->getTexture("assets/Bullet.png"), EnemyBullet, xpos+24, ypos, -3, 3, 1, 120, renderer));
			Entities.push_back(new Bullet(TF->getTexture("assets/Bullet.png"), EnemyBullet, xpos+24, ypos, -3, -3, 1, 120, renderer));
			Entities.push_back(new Bullet(TF->getTexture("assets/Bullet.png"), EnemyBullet, xpos+24, ypos, 3, -3, 1, 120, renderer));
			
		}
		if (eyeCounter == 150) {
			eyeCounter = 0;
		}
		if (counter == 240) {
			counter = 0;
			hit = false;
			state = rand() % 3 + 1;
		}
		break;
	case 2:
		{
			float diffX = xpos - PlayerToChase->getX();
			float diffY = ypos - PlayerToChase->getY();
			distance = sqrt((xpos - PlayerToChase->getX()) * (xpos - PlayerToChase->getX()) + (ypos - PlayerToChase->getY()) * (ypos - PlayerToChase->getY()));

			velx = ((-1 / distance) * diffX * 2.2);
			vely = ((-1 / distance) * diffY * 2.2);
			xpos += velx;
			ypos += vely;

			counter++;
			eyeCounter++;
			if (counter % 60==0) {
				Entities.push_back(new Bullet(TF->getTexture("assets/Bullet.png"), EnemyBullet, xpos + 24, ypos, ((-1 / distance) * diffX * 4.2), ((-1 / distance) * diffY * 4.2), 1, 120, renderer));

			}
			if (eyeCounter == 150) {
				eyeCounter = 0;
			}
			if (counter >= 420) {
				counter = 0;
				hit = false;
				state = rand() % 3 + 1;
			}
		}
		break;
	case 3: {
			counter++;
			eyeCounter++;
			//250,360
			distance = sqrt((xpos - 360) * (xpos - 360) + (ypos - 250) * (ypos - 250));
			if (distance == 0) {
				distance ++;
			}
			velx = ((-1 / distance) * (xpos - 360) * 2.2);
			vely = ((-1 / distance) * (ypos - 250) * 2.2);
			xpos += velx;
			ypos += vely;
			if (eyeCounter == 150) {
				eyeCounter = 0;
			}
			if (distance <= 2) {
				choice = rand() % 4;
				counter = 0;
				hit = false;
				state = 4;
			}
			//std::cout << xpos << " " << ypos << std::endl;
		}
		break;
	case 4: {
		eyeCounter = choice * 30 + 30;
		counter++;
		if (counter == 150) {
			for (int i = 1; i <= 18; i++)
				for (int j = 1; j <= 23; j++) {
					if (i <= 8 && j <= 11&&choice==0)
						room->setMap(i, j, 11);
					else
					if (i <= 8 && j >= 13&&choice==1)
						room->setMap(i, j, 9);
					else
					if (i >= 11 && j <= 11&&choice==2)
						room->setMap(i, j, 12);
					else
					if (i >= 11 && j >= 13&&choice==3)
						room->setMap(i, j, 10);
					else
						room->setMap(i, j, 8);
				}
			
			



		}
		if (counter > 150) {
			switch (choice) {
			case 0:
				if (!(PlayerToChase->getX() < 334 && PlayerToChase->getY() < 180) && !hit) {
					PlayerToChase->setHP(PlayerToChase->getHP() - 1);
					hit = true;
					std::cout << "floor hit";
				}
				break;
			case 1:
				if (!(PlayerToChase->getX() > 418 && PlayerToChase->getY() < 180) && !hit) {
					PlayerToChase->setHP(PlayerToChase->getHP() - 1);
					hit = true;
					std::cout << "floor hit";
				}
				break;
			case 2:
				if (!(PlayerToChase->getX() < 334 && PlayerToChase->getY() > 351)&&!hit) {
					PlayerToChase->setHP(PlayerToChase->getHP() - 1);
					hit = true;
					std::cout << "floor hit";
				}
				break;
			case 3:
				if (!(PlayerToChase->getX() > 418 && PlayerToChase->getY() > 351)&&!hit) {
					PlayerToChase->setHP(PlayerToChase->getHP() - 1);
					hit = true;
					std::cout << "floor hit";
				}
				break;

			}
		}
		if (counter == 240) {
			setFloor();
			hit = false;
			counter = 0;
			state = rand()%3+1;
		}
		

		}
	}
	//std::cout << state<<" "<<counter<<" "<<eyeCounter<<std::endl;




}

void EnemyDobrovat::Render()
{
	
	srcRect.h = 64;
	srcRect.w = 40;
	srcRect.x = (int)(eyeCounter/30)*41;
	srcRect.y = 0;

	destRect.x = (int)xpos;
	destRect.y = (int)ypos;
	destRect.w = srcRect.w*2;
	destRect.h = srcRect.h*2;

	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

void EnemyDobrovat::OnHit()
{
}

SDL_Rect EnemyDobrovat::getBounds()
{
	SDL_Rect rect;
	rect.x = (int)xpos;
	rect.y = (int)ypos;
	rect.w = 80;
	rect.h = 128;
	return rect;
}

EnemyDobrovat* EnemyDobrovat::clone() const
{
	return new EnemyDobrovat(*this);
}

void EnemyDobrovat::setFloor()
{
	for (int i = 1; i <= 18; i++)
		for (int j = 1; j <= 23; j++) {
			if (i <= 8 && j <= 11)
				room->setMap(i, j, 11);
			else
				if (i <= 8 && j >= 13)
					room->setMap(i, j, 9);
				else
					if (i >= 11 && j <= 11)
						room->setMap(i, j, 12);
					else
						if (i >= 11 && j >= 13)
							room->setMap(i, j, 10);
						else
							room->setMap(i, j, 8);
		}
}
