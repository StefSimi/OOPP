#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "SDL.h"
#include "TestEnemy.h"

class Player :public GameObject
{
public:
	Player(const char* texturesheet, int x, int y,int HP,SDL_Renderer* rend);
	virtual void Update(std::vector<GameObject*> &E,bool &running);
	virtual void Render();
	virtual SDL_Rect getBounds();
	/*int getHP();
	void setHP(int HP);*/
	void setKeyDown(int index, bool value);
	bool getKeyDown(int index);
	friend std::ostream& operator<<(std::ostream& os,  Player* p);
private:
	bool keyDown[4] = {0};
	int hitDelay=0;
};


