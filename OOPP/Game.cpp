#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "map.h"
#include "TestEnemy.h"
#include "Bullet.h"

int size = 3, bulletsize = 1;
Player* player;
//Handler* handler;
TestEnemy* E[3];
//Bullet* B[10];
SDL_Event Game::event; //TODO Make variable private
Map* map;
//SDL_Renderer* Game::renderer=nullptr; //TODO Make variable private

 SDL_Renderer* Game::getRenderer(){
	return renderer;
}

Game::Game(const char* title, int width, int height, bool fullscreen) {
	//Player player("assets/Sprite2.png", 0, 0, 100, renderer);
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
	player = new Player("assets/Sprite2.png",0,0,100,renderer);
	//handler->addObject(player);
	E[0] = new TestEnemy("assets/PC.png", 125, 25, 3, 0,renderer);
	E[1] = new TestEnemy("assets/Laptop.png", 530, 80, -2, 4,renderer);
	E[2] = new TestEnemy("assets/Router.png", 121, 337, 5, -3,renderer);
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
	//handler->Update();

	player->Update(E,3);
	//B[0]->Update();
	
	
		
	
	for (int i = 0; i < size; i++)
		E[i]->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap(renderer);
	//SDL_RenderCopy(renderer, playerTex, NULL, &destR);
	player->Render();
	//handler->Render();
	//B[0]->Render();
	for (int i = 0; i < size; i++)
		E[i]->Render();

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

