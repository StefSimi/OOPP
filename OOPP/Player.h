#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "SDL.h"
#include "TestEnemy.h"
#include "Bullet.h"

class Player :public GameObject
{
public:
	Player(const char* texturesheet, int x, int y,int HP,SDL_Renderer* rend);
	virtual void Update(std::vector<GameObject*> &Enemies,std::vector<Bullet*>& Bullets, bool &running);
	virtual void Render(std::vector<GameObject*>& Enemies,std::vector<Bullet*>& Bullets);
	virtual void OnHit();
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

	bool keyDown[4] = { 0 };
};


