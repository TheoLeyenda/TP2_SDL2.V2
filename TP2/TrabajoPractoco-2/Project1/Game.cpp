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
// SE GUARDO CON BALA ENEMIGA RETOCADA
#include "Game.h"

Game::Game()
{
}
Game::~Game()
{
}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	entrarEnJuego = false;
	muestraGameOver = false;
	muestraMenu = true;
	muestraJuego = false;
	muestraControles = false;
	muestraCreditos = false;

	int flags = 0;
	destRJugador.x = 320-32;
	destRJugador.y = 400;

	destREnemigo1.y = -32;

	destREnemigo2.y = -64;

	dibujarEnemigo1 = true;
	
	srand(time(0));
	balaAvanza = false;
	balaAvanzarEnemigo2 = true;
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
		tmpSurface = IMG_Load("../thumbnail_Avion_2.png");
		texturePlayer = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		SDL_FreeSurface(tmpSurface);

		tmpSurfaceBala = IMG_Load("../Bala1.png");
		textureBala = SDL_CreateTextureFromSurface(renderer, tmpSurfaceBala);
		SDL_FreeSurface(tmpSurfaceBala);

		tmpSurfaceEnemigo1 = IMG_Load("../Enemigo_8.png");
		texturaEnemigo1 = SDL_CreateTextureFromSurface(renderer, tmpSurfaceEnemigo1);
		SDL_FreeSurface(tmpSurfaceEnemigo1);

		tmpSurfaceEnemigo2 = IMG_Load("../Enemigo_1.png");
		textureEnemigo2 = SDL_CreateTextureFromSurface(renderer, tmpSurfaceEnemigo2);
		SDL_FreeSurface(tmpSurfaceEnemigo2);

		tmpSurfaceBalaEnemigo2 = IMG_Load("../balaEnemigo.png");
		textureBalaEnemigo2 = SDL_CreateTextureFromSurface(renderer, tmpSurfaceBalaEnemigo2);
		SDL_FreeSurface(tmpSurfaceBalaEnemigo2);

		tmpSurfaceFondoJuego = IMG_Load("../paisajeFondo_op4.jpg");
		textureFondoJuego = SDL_CreateTextureFromSurface(renderer, tmpSurfaceFondoJuego);
		SDL_FreeSurface(tmpSurfaceFondoJuego);

		tmpSurfaceFondoMenu = IMG_Load("../Menu1.jpg");
		textureFondoMenu = SDL_CreateTextureFromSurface(renderer, tmpSurfaceFondoMenu);
		SDL_FreeSurface(tmpSurfaceFondoMenu);

		tmpSurfaceFondoControles = IMG_Load("../Controles.jpg");
		textureFondoControles = SDL_CreateTextureFromSurface(renderer, tmpSurfaceFondoControles);
		SDL_FreeSurface(tmpSurfaceFondoControles);

		tmpSurfaceFondoGameOver = IMG_Load("../GameOver_op1.jpg");
		textureFondoGameOver = SDL_CreateTextureFromSurface(renderer, tmpSurfaceFondoGameOver);
		SDL_FreeSurface(tmpSurfaceFondoGameOver);

		tmpSurfaceFondoCreditos = IMG_Load("../Creditos2.jpg");
		textureFondoCreditos = SDL_CreateTextureFromSurface(renderer, tmpSurfaceFondoCreditos);
		SDL_FreeSurface(tmpSurfaceFondoCreditos);
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
	//Fondo juego
	destRFondoJuego.w = 640;
	destRFondoJuego.h = 480;
	//-----------------------------------------------------
	//Fondo Menu
	destFondoRMenu.w = 640;
	destFondoRMenu.h = 480;
	//-------------------------------------------
	//Fondo Controles
	destRFondoControles.w = 640;
	destRFondoControles.h = 480;
	//----------------------------------------
	//Fondo GameOver
	destRFondoGameOver.w = 640;
	destRFondoGameOver.h = 480;
	//----------------------------------------
	//Fondo Creditos
	destRFondoCreditos.w = 640;
	destRFondoCreditos.h = 480;
	//----------------------------------------
	//Enemigo1
	destREnemigo1.h = 48;
	destREnemigo1.w = 48;
	if (destREnemigo1.y == -48)
	{
		AvionChicoXrand = rand() % 640 - 48;
		destREnemigo1.x = AvionChicoXrand;
	}
	destREnemigo1.y = destREnemigo1.y + velocidadEnemigo1;
	if (destREnemigo1.y >= 480)
	{
		destREnemigo1.y = -48;
	}
	//---------------------------------

	//Enemigo2
	destREnemigo2.h = 64;
	destREnemigo2.w = 64;
	
	if (destREnemigo2.y == -64)
	{
		//cout << "Entre" << endl;
		AvionGrandeXrand = rand() % 640 - 64;
		destREnemigo2.x = AvionGrandeXrand;

		if (destREnemigo2.x >= destREnemigo1.x && destREnemigo2.x <= destREnemigo1.x + 16)
		{
			destREnemigo2.x = destREnemigo2.x - 48;
		}
		if (destREnemigo2.x <= destREnemigo1.x + 32 && destREnemigo2.x >= destREnemigo1.x + 16)
		{
			destREnemigo2.x = destREnemigo2.x + 48;
		}
	}
	destREnemigo2.y = destREnemigo2.y + velocidadEnemigo2;
	if (destREnemigo2.y >= 480)
	{
		destREnemigo2.y = -64;
	}
	//---------------------------------
	
	//BALA ENEMIGO
	destRBalaEnemigo2.h = 7;
	destRBalaEnemigo2.w = 3;
	if (!balaAvanzarEnemigo2)
	{
		destRBalaEnemigo2.x = destREnemigo2.x + 31;
		destRBalaEnemigo2.y = destREnemigo2.y + 32;
	}
	if (balaAvanzarEnemigo2)
	{
		//cout << "bala enemigo avanza";
		if (unaVez)
		{
			destRBalaEnemigo2.x = destREnemigo2.x + 31;
			destRBalaEnemigo2.y = destREnemigo2.y + 64;
			unaVez = false;
		}
		destRBalaEnemigo2.y = destRBalaEnemigo2.y + velocidadBalaEnemigo2;
	}
	if (destRBalaEnemigo2.y >= 480-7)
	{
		balaAvanzarEnemigo2 = true;
		destRBalaEnemigo2.x = destREnemigo2.x + 31;
		destRBalaEnemigo2.y = destREnemigo2.y + 64;
	}
	
	//BALA JUGADOR
	destRBala.h = 7;
	destRBala.w = 3;
	if (!balaAvanza)
	{
		destRBala.x = destRJugador.x + 29;
		destRBala.y = destRJugador.y + 16;
	}
	if (balaAvanza)
	{
		destRBala.y = destRBala.y - 10;
	}
	if (destRBala.y < 0)
	{
		balaAvanza = false;
	}
	//----------------------------------

	//COLICIONES ENEMIGO 1 JUGADOR
	if (destRJugador.x + 64 >= destREnemigo2.x && destRJugador.x <= destREnemigo1.x + 48 && destREnemigo1.y + 48 >= destRJugador.y && destREnemigo1.y < destRJugador.y)
	{
		destRJugador.x = 320 - 32;
		destRJugador.y = 400;

		destREnemigo1.y = -32;
		vidasJugador--;
	}
	//--------------------------------

	//COLICIONES ENEMIGO 2 JUGADOR
	if (destRJugador.x + 64 >= destREnemigo2.x && destRJugador.x <= destREnemigo2.x + 64 && destRJugador.y <= destREnemigo2.y + 64 && destRJugador.y + 64 > destREnemigo2.y)
	{
		destRJugador.x = 320 - 32;
		destRJugador.y = 400;

		destREnemigo2.y = -64;
		vidasJugador--;

	}
	//-------------------------------

	//COLICION ENEMIGO 1
	if (destRBala.y >= destREnemigo1.y && destRBala.y < destREnemigo1.y + 48 && destRBala.x >= destREnemigo1.x && destRBala.x <= destREnemigo1.x + 48)
	{
		balaAvanza = false;
		destREnemigo1.y = -48;
		//velocidadEnemigo1++;
	}
	//COLICIONES ENEMIGO 2
	if (destRBala.y >= destREnemigo2.y && destRBala.y < destREnemigo2.y +64 && destRBala.x >= destREnemigo2.x && destRBala.x <= destREnemigo2.x + 64)
	{
		balaAvanza = false;
		destREnemigo2.y = -64;
		//velocidadEnemigo1++;
	}
	
	

	//COLICION BALA ENEMIGO JUGADOR
	if (destRJugador.y <= destRBalaEnemigo2.y + 7 && destRJugador.y + 64 > destRBalaEnemigo2.y && destRBalaEnemigo2.x <= destRJugador.x + 64 && destRBalaEnemigo2.x >= destRJugador.x )
	{
		destRJugador.x = 320 - 32;
		destRJugador.y = 400;

		destRBalaEnemigo2.x = destREnemigo2.x + 31;
		destRBalaEnemigo2.y = destREnemigo2.y + 32;
		vidasJugador--;
	}
	//-------------------------------

	//COLICIONES BALA JUGADOR BALA ENEMIGA
	if (destRBala.y <= destRBalaEnemigo2.y && destRBala.x >= destRBalaEnemigo2.x && destRBala.x <= destRBalaEnemigo2.x + 3 || (destRBalaEnemigo2.y >= destRBala.y) && (destRBalaEnemigo2.x >= destRBala.x) && (destRBalaEnemigo2.x <= destRBala.x + 3))
	{
		destRBalaEnemigo2.x = destREnemigo2.x + 31;
		destRBalaEnemigo2.y = destREnemigo2.y + 32;
		balaAvanza = false;
	}
	//-------------------------------


	if (vidasJugador == 0 && muestraJuego)
	{
		cout <<endl<< "Game Over" << endl;
		muestraJuego = false;
		muestraGameOver = true;
		muestraMenu = false;
		muestraControles = false;
		muestraCreditos = false;
		entrarEnJuego = false;
		vidasJugador = -1;
	}

}
void Game::render()
{
	SDL_RenderClear(renderer);
	if (muestraCreditos)
	{
		SDL_RenderCopy(renderer, textureFondoCreditos, NULL, &destRFondoCreditos);
	}
	if (muestraGameOver)
	{
		SDL_RenderCopy(renderer, textureFondoGameOver, NULL, &destRFondoGameOver);
	}
	if (muestraControles)
	{
		SDL_RenderCopy(renderer, textureFondoControles, NULL, &destRFondoControles);
	}
	if (muestraMenu)
	{
		SDL_RenderCopy(renderer, textureFondoMenu, NULL, &destFondoRMenu);
	}
	if (muestraJuego)
	{
		SDL_RenderCopy(renderer, textureFondoJuego, NULL, &destRFondoJuego);
		if (vidasJugador > 0)
		{
			SDL_RenderCopy(renderer, textureBala, NULL, &destRBala);
			SDL_RenderCopy(renderer, texturePlayer, NULL, &destRJugador);
		}
		SDL_RenderCopy(renderer, texturaEnemigo1, NULL, &destREnemigo1);
		SDL_RenderCopy(renderer, textureEnemigo2, NULL, &destREnemigo2);
		SDL_RenderCopy(renderer, textureBalaEnemigo2, NULL, &destRBalaEnemigo2);
	}
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
	if (event.type == SDL_KEYDOWN)
	{
		if (muestraCreditos)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_z:
				muestraJuego = false;
				muestraGameOver = false;
				muestraMenu = true;
				muestraControles = false;
				muestraCreditos = false;
				break;
				case SDLK_ESCAPE:
					isRunning = false;
					break;
			}
		}
		if (muestraGameOver)
		{
			switch (event.key.keysym.sym)
			{
				case SDLK_s:
					muestraJuego = false;
					muestraGameOver = false;
					muestraMenu = true;
					muestraControles = false;
					muestraCreditos = false;
					break;
				case SDLK_r:
					vidasJugador = 3;
					destREnemigo1.y = -48;
					destREnemigo2.y = -64;
					muestraJuego = true;
					muestraGameOver = false;
					muestraMenu = false;
					muestraControles = false;
					muestraCreditos = false;
					break;
				case SDLK_ESCAPE:
					isRunning = false;
					break;
			}
		}
		if (muestraMenu)
		{
			switch (event.key.keysym.sym)
			{
				case SDLK_1:
					vidasJugador = 3;
					destREnemigo1.y = -48;
					destREnemigo2.y = -64;
					muestraJuego = true;
					muestraGameOver = false;
					muestraMenu = false;
					muestraControles = false;
					muestraCreditos = false;
				break;

				case SDLK_2:
					muestraJuego = false;
					muestraGameOver = false;
					muestraMenu = false;
					muestraControles = true;
					muestraCreditos = false;
					break;
				case SDLK_3:
					muestraJuego = false;
					muestraGameOver = false;
					muestraMenu = false;
					muestraControles = false;
					muestraCreditos = true;
					break;
				case SDLK_ESCAPE:
					isRunning = false;
				break;
			}
		}
		if (muestraControles)
		{
			switch (event.key.keysym.sym)
			{
				case SDLK_z:
					muestraJuego = false;
					muestraGameOver = false;
					muestraMenu = true;
					muestraControles = false;
					muestraCreditos = false;
				break;
				case SDLK_ESCAPE:
					isRunning = false;
				break;
			}

		}
		if (muestraJuego)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_SPACE:
				balaAvanza = true;
				break;
			case SDLK_ESCAPE:
				isRunning = false;
				break;
			case SDLK_DOWN:
				destRJugador.y = destRJugador.y + 15;
				break;
			case SDLK_UP:
				destRJugador.y = destRJugador.y - 15;
				break;
			case SDLK_LEFT:
				destRJugador.x = destRJugador.x - 15;
				break;
			case SDLK_RIGHT:
				destRJugador.x = destRJugador.x + 15;
				break;
			case SDLK_r:
				if (vidasJugador <= 0)
				{
					vidasJugador = 3;
				}
			default:
				break;
			}
		}
	}
}
bool Game::running()
{
	return isRunning;
}