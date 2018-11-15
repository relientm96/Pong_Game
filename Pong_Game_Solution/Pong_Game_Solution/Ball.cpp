#include "Ball.h"

//Constructor for Ball Object
Ball::Ball(const char* texturesheet, SDL_Renderer* ren, int x, int y):
	GameObject(texturesheet, ren, x, y){
	destRect.w = 64;
	destRect.h = 64;
	directionFlag = 0;
	//Random Number Generation
	srand(time(NULL));
}

//Own Update Function
void Ball::update() {

	//Boundary Checking for ball movement
	if (directionFlag) {
		xspeed *= -1;
		directionFlag = 0;
	}

	//Boundary Checking for ball movement
	if ((ypos + destRect.h) > 600 || (ypos < 0) ) {
		yspeed *= -1;
	}

	//Reset Ball if Ball goes out of bounds
	if ((xpos < -100) || (xpos + destRect.w > 1000)) {
		reset();
	}

	//Update Ball Positions
	xpos = xpos + xspeed;
	ypos = ypos + yspeed;
	destRect.x = (int)xpos;
	destRect.y = (int)ypos;

}

//Reset Position
void Ball::reset() {
	xpos = 400;
	ypos = 300;
	xspeed = (rand() % 2)? 1.0 : -1.0;
}

