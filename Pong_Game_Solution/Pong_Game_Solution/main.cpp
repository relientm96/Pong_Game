#include <C:\DOCUMENTS\C++_Projects\Pong_Game\Pong_Game_Solution\Pong_Game_Solution\Game.h>
#undef main

//Game Object
Game *game = nullptr;

int main(int argc, const char** argv) {

	//FPS Handling
	const int FPS = 400;
	const int frameDelay = 1000 / FPS;

	Uint32 framestart;
	int frameTime;

	game = new Game();

	game->init("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	//Run the game
	while (game->running()) {

		//How many ms since we first initialize SDL
		framestart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		//Time in ms in handling, updating and rendering
		frameTime = SDL_GetTicks() - framestart;

		//We need to delay in this case
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}

	}

	//Game is exited and objects cleaned
	game->clean();

	std::cin.get();
	return 0;
}
