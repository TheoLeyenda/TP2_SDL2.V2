#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <SDL_keyboard.h>
#include <SDL_keycode.h>
using namespace std;

class Game
{
private:
	bool balaAvanza;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Texture* texturePlayer;
	SDL_Surface* tmpSurface;
	SDL_Rect srcRJugador;
	SDL_Rect destRJugador;

	SDL_Texture* textureBala;
	SDL_Surface* tmpSurfaceBala;
	SDL_Rect srcRBala;
	SDL_Rect destRBala;
public:
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen); // inicializa todo
	void update();//logica del juego
	void render();//renderiza
	void clean();//limpia la pantalla
	void handlEvent(); //input

	bool running();
};
#endif
