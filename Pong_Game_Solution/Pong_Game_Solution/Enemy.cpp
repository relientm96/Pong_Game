#include "Enemy.h"

Enemy::Enemy(const char* texturesheet, SDL_Renderer* ren, int x, int y):
	GameObject(texturesheet,ren,x,y){

	//Initial Enemy Coordinates and Size
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 64;
	destRect.h = 160;
	yspeed = 1;

}

void Enemy::update() {

	//Guards to control boundaries
	if ((ypos > 450) || (ypos < 0)) {
		yspeed *= -1;
	}

	//Set as new rendering position
	ypos += yspeed;
	destRect.y = ypos;

	//Log out Current Position
	std::cout << "y = " << destRect.y << std::endl;
}
