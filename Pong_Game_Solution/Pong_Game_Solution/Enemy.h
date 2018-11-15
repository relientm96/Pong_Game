#ifndef ENEMY

#define ENEMY

#include "GameObject.h"

class Enemy : public GameObject{
public:
	Enemy(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~Enemy();
	void update(int ball_x, int ball_y, int* ball_Flag);
	bool inPadYRange(int ball_y);
private:
	int collision_x;
	int collision_y;
};

#endif //ENEMY
