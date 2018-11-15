#ifndef BALL

#define BALL

#include "C:\DOCUMENTS\C++_Projects\Pong_Game\Pong_Game_Solution\Pong_Game_Solution\GameObject.h"
#include <C:\DOCUMENTS\C++_Projects\Pong_Game\Pong_Game_Solution\Pong_Game_Solution\TextureManager.h>

//A Ball is a type of Game Object
class Ball : public GameObject {

public:
	Ball(const char* texturesheet, SDL_Renderer* ren, int x, int y); //Constructor
	void update();
	void reset();
	int getCollisionBallX() { return collisionBall_x; }
	int getCollisionBallY() { return collisionBall_y; }
private:
	int collisionBall_x;
	int collisionBall_y;
};


#endif //BALL

