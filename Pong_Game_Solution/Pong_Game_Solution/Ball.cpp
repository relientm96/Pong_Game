#include "Ball.h"

//Constructor for Ball Object
Ball::Ball(const char* texturesheet, SDL_Renderer* ren, int x, int y):
	GameObject(texturesheet, ren, x, y){
	destRect.w = 64;
	destRect.h = 64;
}

//Own Update Function
void Ball::update() {

	if ((xpos > 700) || (xpos < 0)) {
		xspeed *= -1;
	}
	if ((ypos > 550) || (ypos < 0)) {
		yspeed *= -1;
	}

	xpos += xspeed;
	ypos += yspeed;

	destRect.x = xpos;
	destRect.y = ypos;

}

//Reset Position
void Ball::reset() {
	xpos = 300;
	ypos = 400;
}

