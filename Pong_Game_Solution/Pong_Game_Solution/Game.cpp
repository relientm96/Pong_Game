#include "Game.h"
#include "Ball.h"
#include "Player.h"
#include "Enemy.h"

/*Object Initializations*/
Ball* ball;
Player* player;
Enemy* enemy;
/*---------------------*/

Game::Game() {
	LOG("Game Created...");
}

Game::~Game() {
	LOG("Game Destroyed...");
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	//Flags for window creation (if fullscreen or not)
	int flags = 0;

	//If we want fullscreen, set window to full screen mode
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//Initialize SDL Window and Renderer
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		//Window has been succesfully initialized here...
		std::cout << "Subsystems Initialized!..." << std::endl;
		//Insert parameters used to create the window
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		//Insert Parameters to Create Renderer
		renderer = SDL_CreateRenderer(window, -1, 0);

		//Succesfully Created Window
		if (window){
			std::cout << "Window Created!..." << std::endl;
		}

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 128, 0, 182, 5);
			std::cout << "Renderer Created!..." << std::endl;
		}

		isRunning = true;
	}

	/*--------Creating objects here--------------*/
	ball = new Ball("res/ball.png", renderer, 300, 400);
	player = new Player("res/Bar.png", renderer, -43 , 200);
	enemy = new Enemy("res/Bar.png", renderer, 735, 200);
	/*-------------------------------------------*/

}

//Handle Events in game
void Game::handleEvents() {

	SDL_Event event;

	//Continuously Poll Events in Game
	SDL_PollEvent(&event);

	//Handle Different Event Types 
	switch (event.type){

	//Quit Event, close game by changing flag
	case SDL_QUIT:
		isRunning = false;
		break;
	
	//Handle Up and Down Movement of Player Pad
	case SDL_KEYDOWN:
		/* Check the SDLKey values and change player's direction flag */
		switch (event.key.keysym.sym) {
			case SDLK_UP:
				player->direction = 1;
				break;
			case SDLK_DOWN:
				player->direction = 2;
				break;
			default:
				break;
		}
	default:
		break;
	}


}

//Update objects in game every tick
void Game::update() {

	//Counter storing current number of ticks in game
	cnt++;

	/*---------Update Objects---------*/
	ball->update();
	player->update();
	enemy->update();
	/*--------------------------------*/

	//Display Ticks
	//LOG(cnt); 
}

//Add Stuff to render here
void Game::render() {

	//Clear Current Screen
	SDL_RenderClear(renderer);

	/*----------Render Objects------------*/
	player->render();
	enemy->render();
	//Render Ball Last as it goes on top of the pad
	ball->render();
	/*------------------------------------*/

	//Re-Render the screen 
	SDL_RenderPresent(renderer);

}

//Clean game objects
void Game::clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	LOG("Game Cleaned...");

}



