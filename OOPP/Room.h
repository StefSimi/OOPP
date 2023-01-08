#pragma once
#include "Game.h"
#include "GameObject.h"
#include <fstream>
#include <cstring>
class Room
{
public:
	Room(const char* RoomName, SDL_Renderer* rend, TextureFactory* TF, std::vector<GameObject*>& Entities);
	~Room();
	void LoadMap(int arr[20][25]);
	void DrawMap(SDL_Renderer* rend);
	void setcleared(bool clear);
	bool getcleared();
	void setNorth(Room* room);
	void setSouth(Room* room);
	void setEast(Room* room);
	void setWest(Room* room);
	void setMap(int i, int j, int val);
	Room* getNorth();
	Room* getSouth();
	Room* getEast();
	Room* getWest();

private:
	Room* northRoom= nullptr;
	Room* southRoom= nullptr;
	Room* westRoom= nullptr;
	Room* eastRoom= nullptr;

	SDL_Rect src, dest;
	SDL_Texture* tile[13];
	int map[20][25];
	bool cleared = false;
};

