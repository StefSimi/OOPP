#include "Map.h"

Map::Map(SDL_Renderer* rend, TextureFactory* TF, std::vector<GameObject*>& Entities)
{
	r1= new Room("Room1", rend, TF, Entities);
	r2 = new Room("Room1", rend, TF, Entities);
	r3 = new Room("Room1", rend, TF, Entities);
	r4 = new Room("Room1", rend, TF, Entities);
	r5 = new Room("Room1", rend, TF, Entities);
	r6 = new Room("Room1", rend, TF, Entities);
	/*
			5
			4
		3	2
			1	6
	*/

	CurrentRoom = r1;

	
	//Entities.push_back(new EnemyDobrovat(TF->getTexture("assets/Dobrovat3.png"), Boss, 360, 0, 0, 0, 400, rend, Entities, CurrentRoom));
	r1->setNorth(r2);
	r1->setEast(r6);

	//North Door
	r1->setMap(0, 11, 5);
	r1->setMap(0, 12, 5);
	r1->setMap(0, 13, 5);
	//East DOOR
	r1->setMap(8, 24, 3);
	r1->setMap(9, 24, 3);
	r1->setMap(10, 24, 3);

	
	r2->setSouth(r1);
	r2->setWest(r3);
	r2->setNorth(r4);
	//South Door
	r2->setMap(19, 11, 5);
	r2->setMap(19, 12, 5);
	r2->setMap(19, 13, 5);
	//West Door
	r2->setMap(8, 0, 3);
	r2->setMap(9, 0, 3);
	r2->setMap(10, 0, 3);

	r2->setMap(0, 11, 5);
	r2->setMap(0, 12, 5);
	r2->setMap(0, 13, 5);

	r3->setEast(r2);

	r3->setMap(8, 24, 3);
	r3->setMap(9, 24, 3);
	r3->setMap(10, 24, 3);

	r4->setSouth(r2);
	r4->setNorth(r5);

	r4->setMap(0, 11, 5);
	r4->setMap(0, 12, 5);
	r4->setMap(0, 13, 5);

	r4->setMap(19, 11, 5);
	r4->setMap(19, 12, 5);
	r4->setMap(19, 13, 5);

	r5->setSouth(r4);

	r5->setMap(19, 11, 5);
	r5->setMap(19, 12, 5);
	r5->setMap(19, 13, 5);

	r6->setWest(r1);

	r6->setMap(8, 0, 3);
	r6->setMap(9, 0, 3);
	r6->setMap(10, 0, 3);
}

Room* Map::getCurrentRoom()
{
	return CurrentRoom;
}

void Map::enterRoom(Room* r, SDL_Renderer* rend, TextureFactory* TF, std::vector<GameObject*>& Entities,int entryway)
{
	switch (entryway) {
	case 1:
		CurrentRoom = r->getNorth();
		break;
	case 2:
		CurrentRoom = r->getSouth();
		break;
	case 3:
		CurrentRoom = r->getEast();
		break;
	case 4:
		CurrentRoom = r->getWest();
		break;
	default:
		break;
	}
	//WIDTH 800
	//HEIGHT 640
	positionPlayer(entryway, Entities);
	if (CurrentRoom->getcleared()==false) {
		if (CurrentRoom == r2) {
			Entities.push_back(new EnemyCrawler(TF->getTexture("assets/Cable.png"), Enemy, 100, 100, 20, rend));
			Entities.push_back(new EnemyCrawler(TF->getTexture("assets/Cable.png"), Enemy, 700, 100, 20, rend));
			Entities.push_back(new EnemyCrawler(TF->getTexture("assets/Cable.png"), Enemy, 250, 350, 20, rend));
			Entities.push_back(new EnemyCrawler(TF->getTexture("assets/Cable.png"), Enemy, 550, 350, 20, rend));
			
		}
		else if (CurrentRoom == r3) {
			Entities.push_back(new Item(TF->getTexture("assets/Rico.png"), PassiveItem, 368, 288, rend, 1));
		}
		else if (CurrentRoom == r4) {
			Entities.push_back(new EnemyBasic(TF->getTexture("assets/PC.png"), Enemy, 123, 45, 1, 5, 50, rend));
			Entities.push_back(new EnemyBasic(TF->getTexture("assets/Router.png"), Enemy, 224, 412, 3, -2, 50, rend));
			Entities.push_back(new EnemyBasic(TF->getTexture("assets/Laptop.png"), Enemy, 400, 300, 2, -4, 50, rend));

			Entities.push_back(new EnemyCrawler(TF->getTexture("assets/Cable.png"), Enemy, 250, 350, 20, rend));
			Entities.push_back(new EnemyCrawler(TF->getTexture("assets/Cable.png"), Enemy, 550, 350, 20, rend));
		}
		else if (CurrentRoom == r5) {
			Entities.push_back(new EnemyDobrovat(TF->getTexture("assets/Dobrovat3.png"), Boss, 360, 0, 0, 0, 400, rend, Entities, CurrentRoom));
		}
		else if (CurrentRoom == r6) {
			Entities.push_back(new EnemyChaser(TF->getTexture("assets/Diana.png"), Enemy, 700, 256, 0, 0, 75, rend, Entities));
			Entities.push_back(new EnemyBasic(TF->getTexture("assets/PC.png"), Enemy, 64, 64, 5, 5, 50, rend));
			Entities.push_back(new EnemyBasic(TF->getTexture("assets/Router.png"), Enemy, 64, 512, 5, -5, 50, rend));
			
		}
		
			
	}
		
}

void Map::positionPlayer(int entryway, std::vector<GameObject*>& Entities)
{
	
}
