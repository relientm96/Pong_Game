#ifndef ENEMY

#define ENEMY

#include "GameObject.h"

class Enemy : public GameObject{
public:
	Enemy(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~Enemy();
	void update();
};

#endif //ENEMY
