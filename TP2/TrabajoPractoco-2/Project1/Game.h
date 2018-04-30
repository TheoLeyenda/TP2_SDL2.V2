#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <SDL_keyboard.h>
#include <SDL_keycode.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Game
{
private:
	double AvionChicoXrand;
	double AvionGrandeXrand;
	bool balaAvanza;
	bool balaAvanzarEnemigo2;
	bool unaVez = true;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

	//Jugador
	SDL_Texture* texturePlayer;
	SDL_Surface* tmpSurface;
	SDL_Rect srcRJugador;
	SDL_Rect destRJugador;

	//Bala del jugador
	SDL_Texture* textureBala;
	SDL_Surface* tmpSurfaceBala;
	SDL_Rect srcRBala;
	SDL_Rect destRBala;

	//Enemigo 1
	SDL_Texture* texturaEnemigo1;
	SDL_Surface* tmpSurfaceEnemigo1;
	SDL_Rect srcREnemigo1;
	SDL_Rect destREnemigo1;
	double velocidadEnemigo1 = 2;
	bool dibujarEnemigo1;

	//Enemigo 2
	SDL_Texture* textureEnemigo2;
	SDL_Surface* tmpSurfaceEnemigo2;
	SDL_Rect srcREnemigo2;
	SDL_Rect destREnemigo2;
	double velocidadEnemigo2 = 1;
	bool dibujarEnemigo2;

	//balaEnemigo2
	SDL_Texture* textureBalaEnemigo2;
	SDL_Surface* tmpSurfaceBalaEnemigo2;
	SDL_Rect srcRBalaEnemigo2;
	SDL_Rect destRBalaEnemigo2;
	double velocidadBalaEnemigo2 = 5;

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
