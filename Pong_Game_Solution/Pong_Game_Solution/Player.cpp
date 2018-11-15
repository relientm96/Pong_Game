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

void Player::update() {

	//Set Collision Coordinates as: 
	// x = (Right of Pad)
	collision_x = xpos + destRect.w;
	// y = (Middle of Pad)
	collision_y = ypos + (destRect.h)/2;

	//Behaviour of Pad
	if (direction == UP) {
		ypos--;
	}

	if (direction == DOWN) {
		ypos++;
	}

	//Guards to control boundaries
	if (ypos + destRect.h > 600) ypos = 600 - destRect.h;
	if (ypos < 0) ypos = 0;

	//Set as new rendering position
	destRect.y = ypos;

	//Log Position
	std::cout << "Player: x = " << destRect.x << " ,y = " << destRect.y << std::endl;


}