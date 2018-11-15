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

	if (direction == UP) {
		ypos--;
	}

	if (direction == DOWN) {
		ypos++;
	}

	//Guards to control boundaries
	if (ypos > 450) ypos = 450;
	if (ypos < 0) ypos = 0;

	//Set as new rendering position
	destRect.y = ypos;

}