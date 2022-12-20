#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "SDL.h"
#include <cmath>
class EnemyChaser :public GameObject
{
public:
	EnemyChaser(const char* texturesheet, ID id, float x, float y, float velx, float vely, int HP, SDL_Renderer* rend, std::vector<GameObject*> &Entities);
	~EnemyChaser();
	virtual void Update();
	virtual void Render();
	virtual void OnHit();
	virtual SDL_Rect getBounds();
	/*void setHP(int HP);
	int getHP();*/

private:
	int HP;
	GameObject* PlayerToChase;

};