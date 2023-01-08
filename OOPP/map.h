#pragma once
#include "Room.h"
#include "Game.h"
#include "GameObject.h"
#include <fstream>
#include <cstring>
#include "EnemyCrawler.h"
#include "EnemyChaser.h"
#include "EnemyBasic.h"
#include "Item.h"
#include "EnemyDobrovat.h"
class Map
{
public:
	Map(SDL_Renderer* rend, TextureFactory* TF, std::vector<GameObject*>& Entities);
	Room* getCurrentRoom();
	void enterRoom(Room* r, SDL_Renderer* rend, TextureFactory* TF, std::vector<GameObject*>& Entities,int entryway);
	void positionPlayer(int entryway, std::vector<GameObject*>& Entities);
private:
	Room* CurrentRoom;
	Room* r1=nullptr;
	Room* r2=nullptr;
	Room* r3=nullptr;
	Room* r4 = nullptr;
	Room* r5 = nullptr;
	Room* r6 = nullptr;
};

