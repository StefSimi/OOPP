#pragma once
#include "Game.h"
#include "ID.h"
#include "TextureFactory.h"
#include "IDGenerator.h"
class GameObject
{
	public:
		GameObject();
		GameObject(SDL_Texture* texturesheet,ID id, float x, float y,float velx, float vely,int HP,SDL_Renderer* rend);
		~GameObject();

		void setX(float x);
		void setY(float y);
		void setID(ID id);
		void setVelX(float velx);
		void setVelY(float vely);
		void setHP(int HP);

		float getX();
		float getY();
		ID getID();
		float getVelX();
		float getVelY();
		int getHP();
		const float Clamp(float value, float min, float max);


		virtual void Update();
		virtual void Render()=0;
		virtual void OnHit()=0;
		virtual SDL_Rect getBounds() = 0;
		virtual GameObject* clone() const = 0;



		//bool intersects (SDL_Rect a, SDL_Rect b)=0;
	
	protected:
		float xpos;
		float ypos;
		ID id;
		float velx=0, vely=0;
		int HP;

	//private:


		SDL_Texture* objTexture;
		SDL_Rect srcRect, destRect;
		SDL_Renderer* renderer;


};

