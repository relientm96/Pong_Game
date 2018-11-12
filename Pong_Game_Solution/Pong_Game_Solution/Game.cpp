#include <C:\DOCUMENTS\C++_Projects\Pong_Game\Pong_Game_Solution\Pong_Game_Solution\Game.h>
#include <C:\DOCUMENTS\C++_Projects\Pong_Game\Pong_Game_Solution\Pong_Game_Solution\TextureManager.h>

SDL_Texture* ballTex;
SDL_Rect srcR, destR;

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	//Flags for window creation (if fullscreen or not)
	int flags = 0;

	//If we want fullscreen, set window to full screen mode
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//Initialize Window 
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
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created!..." << std::endl;
		}
		isRunning = true;
	}

	//Initialize Texture from Surface
	ballTex = TextureManager::LoadTexture("res/PixelArt.png",renderer);

}

//Handle Events in game
void Game::handleEvents() {

	SDL_Event event;

	//Continuously Poll Events in Game
	SDL_PollEvent(&event);

	//Handle Different Events
	switch (event.type){

	//Quit Event, close game by changing flag
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}

}

//Where game objects positions are updated
void Game::update() {
	cnt++;
	destR.h = 32;
	destR.w = 32;
	destR.x = cnt;
	LOG(cnt);
}

//Add Stuff to render here
void Game::render() {

	SDL_RenderClear(renderer);

	/*--Add Textures to be rendered here--*/
	SDL_RenderCopy(renderer, ballTex, NULL , &destR);


	/*--------------------------------*/
	SDL_RenderPresent(renderer);

}

//Clean game objects
void Game::clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned..." << std::endl;
}



