#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "SDL.h"
#include "TestEnemy.h"
#define WIDTH 800
#define HEIGHT 640
class Bullet : public GameObject
{
	public:
	Bullet(const char* texturesheet,ID id, int x, int y, int velx, int vely,int bulletDamage, int bulletRange, SDL_Renderer* rend);
	~Bullet();
	virtual void Update(std::vector<GameObject*> &E,int &index);
	virtual void Render();
	virtual void OnHit();
	virtual SDL_Rect getBounds();
	private:
		int damage;


};

