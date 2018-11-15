#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren,  int x, int y){
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet,ren);
	xpos = x;
	ypos = y;
}

//Overriden by Specific Game Objects
void GameObject::update() {

}

//Render is the same for all game objects
void GameObject::render() {
	SDL_RenderCopy(renderer, objTexture, NULL, &destRect);
}


