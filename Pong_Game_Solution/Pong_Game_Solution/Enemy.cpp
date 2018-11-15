#include "Enemy.h"

Enemy::Enemy(const char* texturesheet, SDL_Renderer* ren, int x, int y):
	GameObject(texturesheet,ren,x,y){

	//Initial Enemy Coordinates, Speed and Size
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 64;
	destRect.h = 160;
	yspeed = 1;

}

void Enemy::update() {

	//Guards to control boundaries
	if ((ypos + destRect.h > 600) || (ypos < 0)) {
		yspeed *= -1;
	}

	//Set as new rendering position
	ypos += yspeed;
	destRect.y = ypos;

	//Log out Current Position
	std::cout << "Enemy: x = " << destRect.x << ", y = " << destRect.y << std::endl;
}
