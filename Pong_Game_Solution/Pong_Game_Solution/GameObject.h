#pragma once

#include "C:\DOCUMENTS\C++_Projects\Pong_Game\Pong_Game_Solution\Pong_Game_Solution\Game.h"

class GameObject{

protected:

	int xpos;
	int ypos;
	int xspeed = 1;
	int yspeed = 1;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;

public:
	GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~GameObject();

	void update();
	void render();

	int getxpos() { return xpos; }
	int getypos() { return ypos; }
	int getxspeed() { return xspeed; }
	int getyspeed() { return yspeed; }


};

