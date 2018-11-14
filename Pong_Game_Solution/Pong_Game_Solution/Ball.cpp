#include "Ball.h"

Ball::Ball(const char* texturesheet, SDL_Renderer* ren, int x, int y):
	GameObject(texturesheet, ren, x, y){
}

//Own Update Function
void Ball::update() {

	if ((xpos > 800) || (xpos < 0)) {
		xspeed *= -1;
	}
	if ((ypos > 600) || (ypos < 0)) {
		yspeed *= -1;
	}

	xpos += xspeed;
	ypos += yspeed;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 64;
	destRect.h = 64;
}

