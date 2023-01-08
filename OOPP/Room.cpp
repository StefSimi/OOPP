#include "Room.h"
#include "TextureManager.h"
#pragma warning(disable : 4996)

int lvl0[20][25] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,0},
	{0,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,0},
	{0,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,0},
	{0,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0},
	{0,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,0},
	{0,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,0},
	{0,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};


Room::Room(const char* RoomName, SDL_Renderer* rend, TextureFactory* TF, std::vector<GameObject*>& Entities) {
	tile[0] = TF->getTexture("assets/tile0.png");
	tile[1] = TF->getTexture("assets/tile1.png");
	tile[2] = TF->getTexture("assets/tile2.png");
	tile[3] = TF->getTexture("assets/tile3.png");
	tile[4] = TF->getTexture("assets/tile4.png");
	tile[5] = TF->getTexture("assets/tile5.png");
	tile[6] = TF->getTexture("assets/tile6.png");
	tile[7] = TF->getTexture("assets/tile7.png");
	tile[8] = TF->getTexture("assets/blackTile.png");
	tile[9] = TF->getTexture("assets/blueTile.png");
	tile[10] = TF->getTexture("assets/greenTile.png");
	tile[11] = TF->getTexture("assets/redTile.png");
	tile[12] = TF->getTexture("assets/yellowTile.png");

	LoadMap(lvl0);
	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;
	dest.x = dest.y = 0;
	
	
}

Room::~Room()
{
}



void Room::LoadMap(int arr[20][25]) {
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 25; j++)
			map[i][j] = arr[i][j];
}
void Room::DrawMap(SDL_Renderer* rend) {
	if (cleared) {
		for (int i = 11; i < 14; i++) {
			if (map[0][i] == 5)
				map[0][i] = 6;
			if (map[19][i] == 5)
				map[19][i] = 6;
		}
		for (int i = 8; i < 11; i++) {
			if (map[i][0] == 3)
				map[i][0] = 4;
			if (map[i][24] == 3)
				map[i][24] = 4;
		}
	}
	int type = 0;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 25; j++) {
			type = map[i][j];

			dest.x = j * 32;
			dest.y = i * 32;

			switch (type)
			{
			case 0:
				TextureManager::Draw(tile[0], src, dest,rend);
				break;
			case 1:
				TextureManager::Draw(tile[1], src, dest, rend);
				break;
			case 2:
				TextureManager::Draw(tile[2], src, dest, rend);
				break;
			case 3:
				TextureManager::Draw(tile[3], src, dest, rend);
				break;
			case 4:
				TextureManager::Draw(tile[4], src, dest, rend);
				break;
			case 5:
				TextureManager::Draw(tile[5], src, dest, rend);
				break;
			case 6:
				TextureManager::Draw(tile[6], src, dest, rend);
				break;
			case 7:
				TextureManager::Draw(tile[7], src, dest, rend);
				break;
			case 8:
				TextureManager::Draw(tile[8], src, dest, rend);
				break;
			case 9:
				TextureManager::Draw(tile[9], src, dest, rend);
				break;
			case 10:
				TextureManager::Draw(tile[10], src, dest, rend);
				break;
			case 11:
				TextureManager::Draw(tile[11], src, dest, rend);
				break;
			case 12:
				TextureManager::Draw(tile[12], src, dest, rend);
				break;
			default:
				break;
			}
		}
			
}

void Room::setcleared(bool clear)
{
	cleared = clear;
}

bool Room::getcleared()
{
	return cleared;
}

void Room::setNorth(Room* room)
{
	northRoom = room;
}

void Room::setSouth(Room* room)
{
	southRoom = room;
}

void Room::setEast(Room* room)
{
	eastRoom = room;
}

void Room::setWest(Room* room)
{
	westRoom = room;
}

void Room::setMap(int i, int j, int val)
{
	map[i][j] = val;
}

Room* Room::getNorth()
{
	return northRoom;
}

Room* Room::getSouth()
{
	return southRoom;
}

Room* Room::getEast()
{
	return eastRoom;
}

Room* Room::getWest()
{
	return westRoom;
}
