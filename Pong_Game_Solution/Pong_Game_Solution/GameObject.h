#pragma once

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

class GameObject{

protected:

	float xpos;
	float ypos;
	float xspeed = 1;
	float yspeed = 1;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;

public:
	GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~GameObject();

	void update();
	void render();

	float getxpos() { return xpos; }
	float getypos() { return ypos; }
	float getxspeed() { return xspeed; }
	float getyspeed() { return yspeed; }


};

