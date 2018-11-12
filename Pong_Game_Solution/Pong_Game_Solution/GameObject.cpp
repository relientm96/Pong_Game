#include "C:\DOCUMENTS\C++_Projects\Pong_Game\Pong_Game_Solution\Pong_Game_Solution\GameObject.h"
#include <C:\DOCUMENTS\C++_Projects\Pong_Game\Pong_Game_Solution\Pong_Game_Solution\TextureManager.h>

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren,  int x, int y){
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet,ren);
	xpos = x;
	ypos = y;
}

void GameObject::update() {

	if( (xpos > 800) || (xpos <0) ) {
		xspeed*=-1;
	}
	if( (ypos > 600) || (ypos < 0) ){
		yspeed*=-1;
	}

	xpos += xspeed;
	ypos += yspeed;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 64;
	destRect.h = 64;

}

void GameObject::render() {
	SDL_RenderCopy(renderer, objTexture, NULL, &destRect);
}
