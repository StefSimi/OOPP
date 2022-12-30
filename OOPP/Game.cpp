#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "map.h"
#include "TestEnemy.h"
#include "Bullet.h"
#include "EnemyChaser.h"
#include "EnemyCrawler.h"
#include "TextureFactory.h"

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
bool spamfilter = 0;
Player* player;

std::vector <GameObject*>Entities;
std::vector <std::unique_ptr<SDL_Texture*>> Textures;

SDL_Event Game::event;
Map* map;

 SDL_Renderer* Game::getRenderer(){
	return renderer;
}
 TextureFactory* TF;

 Game* Game::instance = nullptr;

Game::Game(const char* title, int width, int height, bool fullscreen) {
	
	std::cout << "HP= 3\n";
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
	

	Entities.push_back(new Player(TF->getTexture("assets/Sprite2.png"), Player1, WIDTH/2, HEIGHT/2, 3, renderer));
	//For testing ID Generation
	//Entities.push_back(new Player(TF->getTexture("assets/Sprite2.png"), idg, WIDTH / 2, HEIGHT / 2, 3, renderer));

	
	Entities.push_back(new EnemyCrawler(TF->getTexture("assets/Cable.png"), Enemy, 700, 500, 20, renderer));
	Entities.push_back(new EnemyCrawler(TF->getTexture("assets/Cable.png"), Enemy, 100, 444, 20, renderer));
	Entities.push_back(new EnemyCrawler(TF->getTexture("assets/Cable.png"), Enemy, 299, 250, 20, renderer));
	Entities.push_back(new EnemyChaser(TF->getTexture("assets/Ionut.png"), Enemy, WIDTH -50, 50 / 2, 0, 0, 100, renderer, Entities));


	map = new Map(renderer);
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
{/*
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
			SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
		}

		isRunning = true;
	}*/
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
	//Entities.push_back(new EnemyCrawler(TF->getTexture("assets/Cable.png"), Enemy, 700, 500, 2, renderer));
	CurrentEnemies = 0;
	//For Debugging
	/*counter++;
	if (counter % 60 == 0) {
		for (int i = 0; i < E.size(); i++) {
			std::cout << i << " " << E[i]->getID() << std::endl;
		}
		counter = 1;
	}*/

	
	for (int i = 0; i < Entities.size(); i++) {
		switch (Entities[i]->getID()) {
		case Player1: {
			Player* p = reinterpret_cast<Player*>(Entities[i]);
			p->Update(TF, Entities, isRunning);
			//entityTest(p);
		}
					break;
		case Enemy:
			CurrentEnemies++;
			Entities[i]->Update();
			break;
		case PlayerBullet:
			Bullet* b = reinterpret_cast<Bullet*>(Entities[i]);
			b->Update(Entities, i);
			//entityTest(b);
			break;

		}
	}
	if (CurrentEnemies == 0 && spamfilter == false) {
		spamfilter = true;
		std::cout << "Room Clear" << std::endl;
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap(renderer);

	for (int i = 0; i < Entities.size(); i++)
		Entities[i]->Render();


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

