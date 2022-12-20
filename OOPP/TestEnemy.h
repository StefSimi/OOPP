#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "SDL.h"
#define WIDTH 800
#define HEIGHT 640

class TestEnemy :public GameObject
{
public:
	TestEnemy(const char* texturesheet,ID id, float x, float y, float velx, float vely,int HP, SDL_Renderer* rend);
	~TestEnemy();
	virtual void Update();
	virtual void Render();
	virtual void OnHit();
	virtual SDL_Rect getBounds();
	/*void setHP(int HP);
	int getHP();*/

private:
	int HP;

};