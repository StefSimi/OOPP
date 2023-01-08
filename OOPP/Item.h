#pragma once
#include "GameObject.h"

class Item : public GameObject
{
	public:
	Item(SDL_Texture* texturesheet, ID id, float x, float y,SDL_Renderer* rend,int type);
	virtual void Update();
	virtual void Render();
	virtual void OnHit();
	virtual SDL_Rect getBounds();
	virtual Item* clone() const;
	int getType();
	private:
		int type;

};

