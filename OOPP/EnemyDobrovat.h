#pragma once
#include "GameObject.h"
#include "Room.h"
#include "Bullet.h"
class EnemyDobrovat :
    public GameObject
{
public:
	EnemyDobrovat(SDL_Texture* texturesheet, ID id, float x, float y, float velx, float vely, int HP, SDL_Renderer* rend, std::vector<GameObject*>& Entities, Room* room);
	~EnemyDobrovat();
	virtual void Update(std::vector<GameObject*>& Entities,TextureFactory* TF);
	virtual void Render();
	virtual void OnHit();
	virtual SDL_Rect getBounds();
	virtual EnemyDobrovat* clone() const;

private:
	void setFloor();
	bool hit;
	int state=0;
	int counter = 0;
	int eyeCounter = 0;
	int HP;
	float distance;
	int choice;
	GameObject* PlayerToChase;
	Room* room;
};

