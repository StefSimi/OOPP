#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "SDL.h"
#define WIDTH 800
#define HEIGHT 640

class TestEnemy :public GameObject
{
public:
	TestEnemy(const char* texturesheet, int x, int y, int velx, int vely, SDL_Renderer* rend);
	virtual void Update();
	virtual void Render();
	virtual SDL_Rect getBounds();


};