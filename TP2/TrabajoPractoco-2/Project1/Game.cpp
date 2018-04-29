/*
public:
Game();
~Game();
void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
void update();
void render();//renderiza
void clean();//limpia la pantalla
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
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) 
		{
			cout << "la ventana se ha creado" << endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "el renderer se ha creado" << endl;
		}
		isRunning = true;
		tmpSurface = IMG_Load("../thumbnail_Avion_2.png");
		texturePlayer = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		SDL_FreeSurface(tmpSurface);
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
}
void Game::render() 
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texturePlayer, NULL, &destRJugador);
	SDL_RenderPresent(renderer);
}
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Juego limpiado" << endl;
}
void Game::handlEvent() //input
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.key.keysym.sym)
	{
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