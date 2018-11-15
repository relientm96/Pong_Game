#include "Player.h"

//Constructor for Player
Player::Player(const char* texturesheet, SDL_Renderer* ren, int x, int y):
	GameObject(texturesheet,ren,x,y){

	//Initial Player Coordinates and Size
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 64;
	destRect.h = 160;

	//Initialize Player Direction Flag
	direction = 0;
}

void Player::update(int ball_x, int ball_y, int* ball_Flag) {

	//Set Collision Coordinates as: 
	// x = (Right of Pad)
	collision_x = xpos + destRect.w - 15;
	// y = (Middle of Pad)
	collision_y = ypos + (destRect.h)/2;

	//Behaviour of Pad
	if (direction == UP) {
		ypos--;
	}

	if (direction == DOWN) {
		ypos++;
	}
	//Change Direction of ball when hits pad's surface
	if ( (ball_x == collision_x) && (inPadYRange(ball_y)) ) {
		*ball_Flag = 1;
		//std::cout << "Ball Direction Changed!..." << std::endl;
	}

	//Guards to control boundaries
	if (ypos + destRect.h > 600) ypos = 600 - destRect.h;
	if (ypos < 0) ypos = 0;

	//Set as new rendering position
	destRect.y = ypos;	

}

bool Player::inPadYRange(int ball_y) {
	if ((ball_y > ypos) && (ball_y < ypos + destRect.h)) return true;
	else return false;
}