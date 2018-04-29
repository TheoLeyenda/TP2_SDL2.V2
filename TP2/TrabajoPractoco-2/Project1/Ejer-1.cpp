#include <iostream>
#include "Game.h"
using namespace std;

Game *game = nullptr;
int main(int argc, char* argv[]) {

	game = new Game();
	game->init("Avioncitos", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false);
	while (game->running())
	{
		game->handlEvent();
		game->update();
		game->render();
	}
	game->clean();

	return 0;
	/*SDL_Window *window;                    // Declare a pointer
	bool gameOver = false;
	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

										   // Create an application window with the following settings:
	window = SDL_CreateWindow(
		"An SDL2 window",                  // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		640,                               // width, in pixels
		480,                               // height, in pixels
		SDL_WINDOW_OPENGL                  // flags - see below
	);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	//SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	//SDL_RenderClear(renderer);
	//SDL_RenderPresent(renderer);
	if (renderer)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	}
	//cargar una imagen en SDL
	SDL_Texture* texturaJugador;
	SDL_Surface* tmpSurface = IMG_Load("../thumbnail_Avion_2.png");
	texturaJugador = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	//escalar una imagen en SDL
	SDL_Rect srcR;
	SDL_Rect destR;

	// Check that the window was successfully created
	if (window == NULL) {
		// In the case that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}
	//escalar la imagen
	destR.h = 32;
	destR.w = 32;
	//dibujar en pantalla la imagen.
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texturaJugador, NULL, NULL);
	SDL_RenderPresent(renderer);


	// The window is open: could enter program loop here (see SDL_PollEvent())
	cin.get();
	//SDL_Delay(3000);  // Pausa el programa por 3 segundos

					  
	SDL_DestroyWindow(window); // cierra y destruye la ventana

	// Clean up
	SDL_Quit();
	return 0;*/
}