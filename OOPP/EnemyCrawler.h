#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "SDL.h"

#define WIDTH 800
#define HEIGHT 640

class EnemyCrawler :public GameObject
{
public:
	EnemyCrawler(SDL_Texture* texturesheet, ID id, float x, float y, int HP, SDL_Renderer* rend);
	~EnemyCrawler();
	virtual void Update();
	virtual void Render();
	virtual void OnHit();
	virtual SDL_Rect getBounds();
	virtual EnemyCrawler* clone() const;
	/*void setHP(int HP);
	int getHP();*/

private:
	int HP, frameCounter;
	bool active;
	

};