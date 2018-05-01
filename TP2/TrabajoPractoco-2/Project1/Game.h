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
	bool entrarEnJuego;
	double AvionChicoXrand;
	double AvionGrandeXrand;
	bool balaAvanza;
	bool balaAvanzarEnemigo2;
	bool unaVez = true;
	bool isRunning;

	bool muestraGameOver = false;
	bool muestraMenu = false;
	bool muestraControles = false;
	bool muestraCreditos = false;
	bool muestraJuego = false;

	SDL_Event event;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Keysym* Key;
	//Jugador
	SDL_Texture* texturePlayer;
	SDL_Surface* tmpSurface;
	SDL_Rect srcRJugador;
	SDL_Rect destRJugador;
	int vidasJugador = 3;

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

	//fondo Juego
	SDL_Texture* textureFondoJuego;
	SDL_Surface* tmpSurfaceFondoJuego;
	SDL_Rect srcRFondoJuego;
	SDL_Rect destRFondoJuego;

	//fondo inicio o menu
	SDL_Texture* textureFondoMenu;
	SDL_Surface* tmpSurfaceFondoMenu;
	SDL_Rect srcRFondoMenu;
	SDL_Rect destFondoRMenu;

	//fondo controles
	SDL_Texture* textureFondoControles;
	SDL_Surface* tmpSurfaceFondoControles;
	SDL_Rect srcRFondoControles;
	SDL_Rect destRFondoControles;
	
	//fondo game over
	SDL_Texture* textureFondoGameOver;
	SDL_Surface* tmpSurfaceFondoGameOver;
	SDL_Rect serRFondoGameOver;
	SDL_Rect destRFondoGameOver;

	//fondo Creditos
	SDL_Texture* textureFondoCreditos;
	SDL_Surface* tmpSurfaceFondoCreditos;
	SDL_Rect serRFondoCreditos;
	SDL_Rect destRFondoCreditos;

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
