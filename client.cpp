#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>

#include "src/Client/PlayerController/PlayerController.hpp"
#include "src/Client/HeroClient/HeroClient.hpp"
#include "src/Client/ProjectileClient/ProjectileClient.hpp"
#include "src/Client/GameMapCLient/GameMapClient.hpp"
#include "src/Base/Sizes/Sizes.hpp"

// CONFIGURACOES JANELA
int SCALE = 3;
int WIDTH = SCREEN_SIZE.x * SCALE;
int HEIGHT = SCREEN_SIZE.y * SCALE;

// SLD GLOBAIS
SDL_Window *window = nullptr;	  // cria uma variavel do tipo Window
SDL_Renderer *renderer = nullptr; // cria uma variavel do tipo renderer
bool TELA_CHEIA = false;
const int FPS = 60;

// MAP AUXS
const int TILE_NUMBER = SCREEN_SIZE.x * SCREEN_SIZE.y / (TILE_SIZE.x * TILE_SIZE.y);
std::vector<bool> BLOCKS(TILE_NUMBER, false);

// GAME OBJECTS
GameMapClient *MAP;
PlayerController CONTROLLER;
HeroClient *PLAYER;
std::vector<ProjectileClient> PROJECTILES;

// VARIAVEIS GLOBAIS
bool RODANDO = true;

// FUNCOES SDL
void inicializacao_SDL();
void encerramento_SDL();

// FUNCOES JOGO
void update();
void input();
void draw();

// FUNCOES AUXILIARES

int main(int argc, char *argv[])
{
	int fps_timer, delta_fps;

	inicializacao_SDL();

	PLAYER = new HeroClient(0.0f, 0.0f);
	MAP = new GameMapClient(renderer);

	while (RODANDO)
	{
		fps_timer = SDL_GetTicks();

		update();
		input();
		draw();

		delta_fps = SDL_GetTicks() - fps_timer;
		if (1000 / FPS > delta_fps)
			SDL_Delay(1000 / FPS - delta_fps);
	}

	encerramento_SDL();

	return 0;
}

void inicializacao_SDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		std::cout << "Erro encontrado:  " << SDL_GetError() << std::endl;
	if (TELA_CHEIA)
	{
		SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP, &window, &renderer);
	}
	else
	{
		SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetWindowTitle(window, "Hero Tower");

	/*
	SDL_DisplayMode DM;
	int w, h;
	SDL_GetRendererOutputSize(renderer, &w, &h);
	std::cout << "WIDTH: " << w << " HEIGHT: " << h << std::endl;
	SDL_GetCurrentDisplayMode(0, &DM);
	std::cout << "WIDTH: " << DM.w << " HEIGHT: " << DM.h << std::endl;

	std::cout << "EXTRA - WIDTH: " << DM.w % (int)SCREEN_SIZE.x << " EXTRA - HEIGHT: " << DM.h % (int)SCREEN_SIZE.y << std::endl;
	std::cout << "MAX - WIDTH: " << std::floor((float)DM.w / SCREEN_SIZE.x) << " MAX - HEIGHT: " << std::floor((float)DM.h / SCREEN_SIZE.y) << std::endl;
	*/
}

void encerramento_SDL()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void update()
{
	PLAYER->update(MAP->_collisionBLocks, CONTROLLER._keys);

	for (int i = 0; i < (int)PROJECTILES.size(); i++)
	{
		PROJECTILES[i].update(MAP->_collisionBLocks);

		if (!PROJECTILES[i]._isActive)
		{
			PROJECTILES.erase(PROJECTILES.begin() + i);
			i = 0;

			PROJECTILES.shrink_to_fit();
		}
	}
}

void input()
{
	CONTROLLER.update();

	if (CONTROLLER._keys._pauseIsPressed)
	{
		RODANDO = false;
	}

	if (CONTROLLER._keys._n1IsPressed)
	{
		PROJECTILES.push_back(ProjectileClient(*PLAYER));
	}
}

void draw()
{
	// Limpa tela
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255); // bota rosa para debug

	MAP->draw(renderer, PLAYER->_position.x, PLAYER->_position.y, SCALE);

	for (ProjectileClient projectile : PROJECTILES)
	{
		projectile.draw(renderer, SCALE);
	}

	PLAYER->draw(renderer, SCALE);

	// // Renderiza
	SDL_RenderPresent(renderer);
}
