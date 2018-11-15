#ifndef PLAYER

#define PLAYER

#include "GameObject.h"
#include "TextureManager.h"

//Constants for Direction
constexpr auto UP = 1;
constexpr auto DOWN = 2;

class Player: public GameObject{
public:
	Player(const char* texturesheet, SDL_Renderer* ren, int x, int y); //Constructor
	unsigned char direction; //Direction Flag
	
	void update();
	int getCollisionX() { return collision_x; }
	int getCollisionY() { return collision_y; }

private:
	int collision_x; 
	int collision_y;
};

#endif //PLAYER

