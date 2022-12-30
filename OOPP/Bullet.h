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
	Bullet(SDL_Texture* texturesheet, ID id, float x, float y, float velx, float vely, int bulletDamage, int bulletRange, SDL_Renderer* rend);
	~Bullet();
	virtual void Update(std::vector<GameObject*> &Entities,int &index);
	virtual void Render();
	virtual void OnHit();
	virtual Bullet* clone() const;
	virtual SDL_Rect getBounds();
	private:
		int damage;


};

