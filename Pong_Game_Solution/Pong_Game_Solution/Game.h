#ifndef GAME

#define GAME

/*Standard Libraries and SDL Libraries*/
#include <iostream>
#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"

/*Externally Defined Header Files*/
#include "TextureManager.h"
#include "GameObject.h"

/*Macros*/
#define LOG(message) std::cout << message << std::endl;

class Game {

private:
	bool isRunning = true;
	int cnt = 0;
	SDL_Window* window;
	SDL_Renderer* renderer;

public:

	//Constructor
	Game();
	//Deconstructor
	~Game();

	//Initialize Windows and Subsystem
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	//Update
	void update();

	//Render
	void render();

	//Clean
	void clean();

	//Handle Events
	void handleEvents();

	//Return Running Status of Game
	bool running() {
		return isRunning;
	}

};

#endif //GAME
