#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Room.h"
#include "EnemyBasic.h"
#include "Bullet.h"
#include "EnemyChaser.h"
#include "EnemyCrawler.h"
#include "TextureFactory.h"
#include "EnemyBasic.h"

template <class T>
void entityTest(T a) {
	std::cout << "Invalid entity"<<std::endl;
}
template<>
void entityTest(Player* p) {
	std::cout << "Player. HP= "<<p->getHP()<<", xpos= "<<p->getX()<<", ypos= "<<p->getY()<<std::endl;
}
template<>
void entityTest(Bullet* b) {
	std::cout << "Bullet"<<std::endl;
}


int counter = 0;
int CurrentEnemies=0;
int size = 3, bulletsize = 1;
bool rico = 0;
Player* player;

std::vector <GameObject*>Entities;
std::vector <std::unique_ptr<SDL_Texture*>> Textures;

SDL_Event Game::event;
Room* room;
Map* map;
 SDL_Renderer* Game::getRenderer(){
	return renderer;
}
 TextureFactory* TF;

 Game* Game::instance = nullptr;

Game::Game(const char* title, int width, int height, bool fullscreen) {
	//handler = new Handler();
	IDGenerator idg;
	Game::renderer = nullptr;
	
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}
	
	//WIDTH 800
	//HEIGHT 640

	TF = new TextureFactory(renderer);
	TF->getTexture("assets/Sprite2.png");
	


	Entities.push_back(new Player(TF->getTexture("assets/Player.png"), Player1, WIDTH/2, HEIGHT/2, 3, renderer));

	hud = new HUD(TF->getTexture("assets/Heart.png"), renderer);
	map = new Map(renderer, TF, Entities);
}

Game* Game::getInstance(const char* title, int width, int height, bool fullscreen)
{
	if (instance == nullptr) {
		instance = new Game(title, width, height, fullscreen);
	}
	return instance;
}


Game::~Game()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
}

void Game::handleEvents()
{
	

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	CurrentEnemies = 0;
	//For Debugging

	//Entities.push_back(new EnemyCrawler(TF->getTexture("assets/Cable.png"), Enemy, 700, 500, 2, renderer));
	
	for (int i = 0; i < Entities.size(); i++) {
		switch (Entities[i]->getID()) {
		case Player1: {
			Player* p = reinterpret_cast<Player*>(Entities[i]);
			rico = p->getRico();
			p->Update(TF, Entities, isRunning,map);
			//entityTest(p);
		}
					break;
		case Enemy:
			CurrentEnemies++;
			Entities[i]->Update();
			break;
		case PlayerBullet: {
			Bullet* b = reinterpret_cast<Bullet*>(Entities[i]);
			b->Update(Entities, TF, i, rico);
			//entityTest(b);
		}
			break;
		case EnemyBullet: {
			Bullet* b = reinterpret_cast<Bullet*>(Entities[i]);
			b->Update(Entities, TF, i, rico);
		}
			break;
		case Boss: {
			CurrentEnemies++;
			EnemyDobrovat* d = reinterpret_cast<EnemyDobrovat*>(Entities[i]);
			d->Update(Entities,TF);
		}
			break;
		}
	}
	if (CurrentEnemies == 0) {
		map->getCurrentRoom()->setcleared(true);
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->getCurrentRoom()->DrawMap(renderer);
	//room->DrawMap(renderer);

	for (int i = 0; i < Entities.size(); i++)
		Entities[i]->Render();
	Player* p = reinterpret_cast<Player*>(Entities[0]);
	
	hud->render(p->getHP());

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	isRunning = false;
	std::cout << "Restanta Domnule Student"<<std::endl;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

