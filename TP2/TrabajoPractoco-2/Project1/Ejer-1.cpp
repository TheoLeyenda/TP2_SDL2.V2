//SE GUARDO CON COLICIONES

//SE GUARDO COMPATIBLE CON TODOS LOS RELEASE Y TODOS LOS DEBUG

//SE GUARDO CON CONTROLES, CREDITOS, MENU Y GAME OVER
#include <iostream>
#include "Game.h"
using namespace std;

Game *game = nullptr;
int main(int argc, char* argv[]) {

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("Avioncitos", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false);
	SDL_Delay(1000);
	while (game->running())
	{

		frameStart = SDL_GetTicks();

		game->handlEvent();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->clean();

	return 0;
}