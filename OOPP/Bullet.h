#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "SDL.h"
#include "TestEnemy.h"
#define WIDTH 800
#define HEIGHT 640
class Bullet : public GameObject
{
	private:
		int lifespan=0;
	public:
	Bullet(const char* texturesheet, int x, int y, int velx, int vely, SDL_Renderer* rend, int lifespan);
	~Bullet();
	virtual void Update(TestEnemy* E[], int EnemySize);
	virtual void Render();
	virtual SDL_Rect getBounds();
	int getLifespan();
	void setLifespan(int x);

};

