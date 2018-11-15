#ifndef BALL

#define BALL

#include "C:\DOCUMENTS\C++_Projects\Pong_Game\Pong_Game_Solution\Pong_Game_Solution\GameObject.h"
#include <C:\DOCUMENTS\C++_Projects\Pong_Game\Pong_Game_Solution\Pong_Game_Solution\TextureManager.h>
#include <ctime>

//A Ball is a type of Game Object
class Ball : public GameObject {

public:
	Ball(const char* texturesheet, SDL_Renderer* ren, int x, int y); //Constructor
	void update();
	void reset();
	float getBallX() { return xpos; }
	float getBallY() { return ypos; }
	int getBallDestRectH() { return destRect.h; }
	int getBallDestRectW() { return destRect.w; }
	int directionFlag;
};


#endif //BALL

