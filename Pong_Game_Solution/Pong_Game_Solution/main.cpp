#include <C:\DOCUMENTS\C++_Projects\Pong_Game\Pong_Game_Solution\Pong_Game_Solution\Game.h>
#undef main

//Game Object
Game *game = nullptr;

int main(int argc, const char** argv) {

	game = new Game();

	game->init("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	//Run the game
	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	//Game is exited and objects cleaned
	game->clean();

	std::cin.get();
	return 0;
}
