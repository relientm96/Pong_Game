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

void Enemy::update(int ball_x, int ball_y, int* ball_Flag) {

	//Set Collision Coordinates as: 
	// x = (Right of Pad)
	collision_x = xpos + 60;
	// y = (Middle of Pad)
	collision_y = ypos + (destRect.h) / 2;

	std::cout << "Ball: x = " << ball_x << std::endl;

	//Guards to control boundaries
	if ((ypos + destRect.h > 600) || (ypos < 0)) {
		yspeed *= -1;
	}

	//Change Direction of ball when hits pad's surface
	if ( (ball_x == collision_x) && (inPadYRange(ball_y)) ) {
		*ball_Flag = 1;
	}

	//Set as new rendering position
	ypos = ypos + yspeed;
	destRect.y = ypos;

}

bool Enemy::inPadYRange(int ball_y) {
	if ((ball_y > ypos) && (ball_y < ypos + destRect.h)) return true;
	else return false;
}