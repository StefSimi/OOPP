#pragma once
#include "Game.h"
#include "ID.h"

class GameObject
{
	public:
		GameObject();
		GameObject(const char* texturesheet,ID id, int x, int y,int velx, int vely,int HP,SDL_Renderer* rend);
		~GameObject();

		void setX(int x);
		void setY(int y);
		void setID(ID id);
		void setVelX(int velx);
		void setVelY(int vely);
		void setHP(int HP);

		int getX();
		int getY();
		ID getID();
		int getVelX();
		int getVelY();
		int getHP();
		const int Clamp(int value, int min, int max);


		virtual void Update();
		virtual void Render()=0;
		virtual void OnHit()=0;
		virtual SDL_Rect getBounds() = 0;



		//bool intersects (SDL_Rect a, SDL_Rect b)=0;
	
	protected:
		int xpos;
		int ypos;
		ID id;
		int velx=0, vely=0;
		int HP;

	//private:


		SDL_Texture* objTexture;
		SDL_Rect srcRect, destRect;
		SDL_Renderer* renderer;


};

