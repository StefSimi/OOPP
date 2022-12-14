#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "map.h"
#include "TestEnemy.h"
#include "Bullet.h"


int counter = 0;
int size = 3, bulletsize = 1;
Player* player;
//Handler* handler;


//TestEnemy* E[3];
std::vector <GameObject*>E;
std::vector <Bullet*>B;

//Bullet* B[10];
SDL_Event Game::event; //TODO Make variable private
Map* map;
//SDL_Renderer* Game::renderer=nullptr; //TODO Make variable private

 SDL_Renderer* Game::getRenderer(){
	return renderer;
}

Game::Game(const char* title, int width, int height, bool fullscreen) {
	std::cout << "HP= 3\n";
	//handler = new Handler();
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
	//player = TextureManager::LoadTexture("assets/Sprite1.png", renderer);
	//handler->addObject(new Player("assets/Sprite2.png", 0, 0, 100, renderer));
	player = new Player("assets/Sprite2.png",Player1,50,50,3,renderer);
	E.push_back(new Player("assets/Sprite2.png", Player1, 50, 50, 3, renderer));
		//handler->addObject(player);
	//E[0] = new TestEnemy("assets/PC.png", 125, 32, 3, 0,renderer);
	E.push_back(new TestEnemy("assets/PC.png",Enemy, 125, 32, 3, 0,20, renderer));
	//E[1] = new TestEnemy("assets/Laptop.png", 530, 80, -2, 4,renderer);
	E.push_back(new TestEnemy("assets/Laptop.png", Enemy, 530, 80, -2, 4,40, renderer));
	//E[2] = new TestEnemy("assets/Router.png", 121, 337, 5, -3,renderer);
	E.push_back (new TestEnemy("assets/Router.png", Enemy, 121, 337, 5, -3,60, renderer));
	//E.push_back(new Bullet("assets/Bullet.png", xpos, ypos, 0 + velx, speed + 3 + vely / 2, bulletDamage, bulletRange, renderer));
	//handler->addObject(new TestEnemy("assets/Router.png", 121, 337, 5, -3, renderer));
		//B[0] = new Bullet("assets/Bullet.png", 121, 337, 0, 2, renderer, 180);
	map = new Map(renderer);
}

Game::~Game()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
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
	}
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
	counter++;
	if (counter % 60 == 0) {
		for (int i = 0; i < E.size(); i++) {
			std::cout << i << " " << E[i]->getID() << std::endl;
		}
		counter = 1;
	}

	//player->Update(E,B,isRunning);
	
	for (int i = 0; i < E.size(); i++)
		switch (E[i]->getID()) {
		case Player1: {
			Player* p = reinterpret_cast<Player*>(E[i]);
			p->Update(E, B, isRunning);
		}
			break;

		case Enemy:
			E[i]->Update();
			break;
		case PlayerBullet:
			Bullet* b = reinterpret_cast<Bullet*>(E[i]);
			b->Update(E,i);
			break;

		}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap(renderer);
	//player->Render(E,B);
	for (int i = 0; i < E.size(); i++)
		switch (E[i]->getID()) {
		case Player1: {
			Player* p = reinterpret_cast<Player*>(E[i]);
			p->Render();
			}break;
		case Enemy:
			E[i]->Render();
			break;
		case PlayerBullet:
			
			E[i]->Render();
			break;
		}


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

