#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "src/Client/HeroClient/HeroClient.hpp"
#include "src/Client/ProjectileClient/ProjectileClient.hpp"
#include "src/Client/GameMapCLient/GameMapClient.hpp"

// CONFIGURACOES JANELA
int SCALE = 3;
int WIDTH = 16 * 50 * SCALE;
int HEIGHT = 9 * 50 * SCALE;

// SLD GLOBAIS
SDL_Window *janela = nullptr;		  // cria uma variavel do tipo Window
SDL_Renderer *renderizador = nullptr; // cria uma variavel do tipo renderizador

// MAP
std::vector<bool> BLOCKS(((WIDTH / SCALE) * (HEIGHT / SCALE)) / (16 * 9), false);
GameMapClient *MAP;

// HeroClient *PLAYER;
HeroClient *PLAYER;
std::vector<ProjectileClient> PROJECTILES;

// VARIAVEIS GLOBAIS
bool TELA_CHEIA = false, RODANDO = true;
int STEPS = 0, FPS = 60;

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
	MAP = new GameMapClient(WIDTH / SCALE, HEIGHT / SCALE, renderizador);

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
		// WIDTH = 2560;
		// HEIGHT = 1600;
		// SCALE = WIDTH / 16;
		SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP, &janela, &renderizador);
	}
	else
		SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_SHOWN, &janela, &renderizador);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
	SDL_SetWindowBordered(janela, SDL_TRUE);
	SDL_SetRenderDrawBlendMode(renderizador, SDL_BLENDMODE_BLEND);
	SDL_SetWindowTitle(janela, "Hero Tower");
}

void encerramento_SDL()
{
	SDL_DestroyWindow(janela);
	SDL_DestroyRenderer(renderizador);
	SDL_Quit();
}

void update()
{
	STEPS++;

	PLAYER->update(MAP->_collisionBLocks);

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
	if (PLAYER->_controller._keys._pauseIsPressed)
	{
		RODANDO = false;
	}

	if (PLAYER->_controller._keys._n1IsPressed)
	{
		PROJECTILES.push_back(ProjectileClient(*PLAYER));
	}
}

void draw()
{
	// Limpa tela
	SDL_RenderClear(renderizador);

	SDL_Rect bordaE;
	bordaE.x = 0;
	bordaE.y = 0;
	bordaE.w = WIDTH;
	bordaE.h = HEIGHT;

	SDL_SetRenderDrawColor(renderizador, 34, 35, 35, 255);
	SDL_RenderDrawRect(renderizador, &bordaE);
	SDL_RenderFillRect(renderizador, &bordaE);

	MAP->draw(renderizador, PLAYER->_position.x, PLAYER->_position.y, SCALE);

	for (Rect4 block : MAP->_collisionBLocks)
	{
		SDL_Rect b;
		b.x = block.x * SCALE;
		b.y = block.y * SCALE;
		b.w = block.w * SCALE;
		b.h = block.h * SCALE;

		SDL_SetRenderDrawColor(renderizador, 155, 0, 0, 255);
		SDL_RenderDrawRect(renderizador, &b);
		SDL_RenderFillRect(renderizador, &b);
	}

	for (ProjectileClient projectile : PROJECTILES)
	{
		projectile.draw(renderizador, SCALE);
	}
	PLAYER->draw(renderizador, SCALE);
	SDL_SetRenderDrawColor(renderizador, 0, 0, 0, 255);

	// // Renderiza
	SDL_RenderPresent(renderizador);
}
