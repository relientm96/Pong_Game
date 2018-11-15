#include "Ball.h"

//Constructor for Ball Object
Ball::Ball(const char* texturesheet, SDL_Renderer* ren, int x, int y):
	GameObject(texturesheet, ren, x, y){
	destRect.w = 64;
	destRect.h = 64;
}

//Own Update Function
void Ball::update() {

	//Boundary Checking for ball movement
	if ((xpos + destRect.w > 800)  || (xpos < 0)) {
		xspeed *= -1;
	}
	if ((ypos + destRect.h) > 600 || (ypos < 0) ) {
		yspeed *= -1;
	}

	//Update Ball Positions
	xpos += xspeed;
	ypos += yspeed;
	destRect.x = xpos;
	destRect.y = ypos;

}

//Reset Position
void Ball::reset() {
	xpos = 400;
	ypos = 300;
}

