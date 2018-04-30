/*
public
Game();
~Game();
void init(const char title, int xpos, int ypos, int width, int height, bool fullscreen);
void update();
void render(); renderiza
void clean(); limpia la pantalla
void handlEvents();
bool running();
};
*/

#include "Game.h"

Game::Game()
{
}
Game::~Game()
{
}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	bool balaAvanza = false;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			cout<<"la ventana se ha creado"<<endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout<<"el renderer se ha creado"<<endl;
		}
		isRunning = true;
		tmpSurface = IMG_Load("../thumbnail_Avion_1.png");
		texturePlayer = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		SDL_FreeSurface(tmpSurface);

		tmpSurfaceBala = IMG_Load("../bala1.png");
		textureBala = SDL_CreateTextureFromSurface(renderer, tmpSurfaceBala);
		SDL_FreeSurface(tmpSurfaceBala);
	}
	else
	{
		isRunning = false;
	}
}
void Game::update()
{
	destRJugador.h = 64;
	destRJugador.w = 64;
	destRBala.h = 7;
	destRBala.w = 3;
	if (!balaAvanza)
	{
		destRBala.x = destRJugador.x + 30;
		destRBala.y = destRJugador.y - 5;
	}
	if (balaAvanza)
	{
		destRBala.y = destRBala.y - 1;
	}
}
void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texturePlayer, NULL, &destRJugador);
	SDL_RenderCopy(renderer, textureBala, NULL, &destRBala);
	SDL_RenderPresent(renderer);
}
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout<<"Juegolimpiado"<<endl;
}
void Game::handlEvent() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.key.keysym.sym)
	{
			case SDLK_SPACE:
				balaAvanza = true;
			break;
			case SDLK_ESCAPE:
				isRunning = false;
				break;
			case SDLK_DOWN:
				destRJugador.y = destRJugador.y + 10;
				break;
			case SDLK_UP:
				destRJugador.y = destRJugador.y - 10;
				break;
			case SDLK_LEFT:
				destRJugador.x = destRJugador.x - 10;
				break;
			case SDLK_RIGHT:
				destRJugador.x = destRJugador.x + 10;
				break;
			default:
				break;
	}
}
bool Game::running()
{
	return isRunning;
}