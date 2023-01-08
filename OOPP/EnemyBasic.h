#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "SDL.h"
#define WIDTH 800
#define HEIGHT 640

class EnemyBasic :public GameObject
{
public:
	EnemyBasic(SDL_Texture* texturesheet,ID id, float x, float y, float velx, float vely,int HP, SDL_Renderer* rend);
	~EnemyBasic();
	virtual void Update();
	virtual void Render();
	virtual void OnHit();
	virtual SDL_Rect getBounds();
	virtual EnemyBasic* clone() const;
	/*void setHP(int HP);
	int getHP();*/

private:
	int HP;

};