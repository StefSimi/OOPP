#pragma once
#include "GameObject.h"
#include "Room.h"
#include "Map.h"
#include "TextureManager.h"
#include "SDL.h"
#include "Bullet.h"
#include "TextureFactory.h"
#include <cmath>
#include "Item.h"

class Player :public GameObject
{
public:
	Player(SDL_Texture* texturesheet,ID id, float x, float y,int HP,SDL_Renderer* rend);
	Player(SDL_Texture* texturesheet,IDGenerator& id_generator, float x, float y, int HP, SDL_Renderer* rend);
	virtual void Update(TextureFactory *TF,std::vector<GameObject*> &Entities, bool &running,Map *map);
	virtual void Render();
	virtual void OnHit();
	virtual Player* clone() const;

	void getHit();
	void positionPlayer(int entryway);



	virtual SDL_Rect getBounds();
	/*int getHP();
	void setHP(int HP);*/
	void setKeyDown(int index, bool value);
	void clearBullets(std::vector<GameObject*>& Entities);

	bool getKeyDown(int index);
	bool getRico();
	friend std::ostream& operator<<(std::ostream& os,  Player* p);
private:
	
	/// Player stats 
	/// HP=HP from constructor
	int speed = 6;
	int hitDelay = 60;
	int bulletDelay = 20;
	int bulletDamage = 5;
	int bulletRange = 50;
	int frame = 0;
	


	int currentbulletDelay = 0;
	int currenthitDelay = 0;

	bool hasRico=false;
	bool keyDown[8] = { 0 };
};


