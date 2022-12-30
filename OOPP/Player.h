#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "SDL.h"
#include "TestEnemy.h"
#include "Bullet.h"
#include "TextureFactory.h"
class Player :public GameObject
{
public:
	Player(SDL_Texture* texturesheet,ID id, float x, float y,int HP,SDL_Renderer* rend);
	Player(SDL_Texture* texturesheet,IDGenerator& id_generator, float x, float y, int HP, SDL_Renderer* rend);
	virtual void Update(TextureFactory *TF,std::vector<GameObject*> &Entities, bool &running);
	virtual void Render();
	virtual void OnHit();
	virtual Player* clone() const;



	virtual SDL_Rect getBounds();
	/*int getHP();
	void setHP(int HP);*/
	void setKeyDown(int index, bool value);
	bool getKeyDown(int index);
	friend std::ostream& operator<<(std::ostream& os,  Player* p);
private:
	
	/// Player stats 
	/// HP=HP from constructor
	int speed = 5;
	int hitDelay = 60;
	int bulletDelay = 20;
	int bulletDamage = 5;
	int bulletRange = 50;



	int currentbulletDelay = 0;
	int currenthitDelay = 0;

	bool keyDown[8] = { 0 };
};


