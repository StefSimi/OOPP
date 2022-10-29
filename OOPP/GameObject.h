#pragma once
#include "Game.h"
#include "ID.h"

class GameObject
{
	public:
		GameObject();
		GameObject(const char* texturesheet, int x, int y,int velx, int vely,SDL_Renderer* rend);
		~GameObject();

		void setX(int x);
		void setY(int y);
		void setID(ID id);
		void setVelX(int velx);
		void setVelY(int vely);

		int getX();
		int getY();
		ID getID();
		int getVelX();
		int getVelY();
		const int Clamp(int value, int min, int max);


		virtual void Update();//???????????????????????? "virtual methods must either be implemented or defined as pure." ce inseamna asta
		virtual void Render();//Ah nvm are sens //ba nu
		virtual SDL_Rect getBounds() = 0;



		//bool intersects (SDL_Rect a, SDL_Rect b)=0;
	
	protected:
		int xpos;
		int ypos;
		ID id;
		int velx=0, vely=0;

	//private:


		SDL_Texture* objTexture;
		SDL_Rect srcRect, destRect;
		SDL_Renderer* renderer;


};

