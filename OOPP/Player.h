#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "SDL.h"
#include "TestEnemy.h"

class Player :public GameObject
{
public:
	Player(const char* texturesheet, int x, int y,int HP,SDL_Renderer* rend);
	virtual void Update(TestEnemy *E[], int EnemySize);
	virtual void Render();
	virtual SDL_Rect getBounds();
	int getHP();
	void setHP(int HP);

	friend std::ostream& operator<<(std::ostream& os,  Player* p);
private:
	int HP;
	//REMOVE
	//TestEnemy* enemy[3];
	//int size;
};


