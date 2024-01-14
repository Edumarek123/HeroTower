#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "src/Client/HeroClient/HeroClient.hpp"
#include "src/Base/GameMap/GameMap.hpp"

// HeroClient *PLAYER;
HeroClient *PLAYER;

// CONFIGURACOES JANELA
int SCALE = 4;
int WIDTH = 320 * SCALE;
int HEIGHT = 320 * SCALE;

// MAP
std::vector<bool> BLOCKS((WIDTH * HEIGHT) / (16 * 16), false);
GameMap MAP(WIDTH / SCALE, HEIGHT / SCALE);

// SLD GLOBAIS
SDL_Window *janela = nullptr;		  // cria uma variavel do tipo Window
SDL_Renderer *renderizador = nullptr; // cria uma variavel do tipo renderizador

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

	PLAYER = new HeroClient(100.0f, 100.0f);

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
		WIDTH = 2560;
		HEIGHT = 1600;
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

	PLAYER->update(MAP._collisionBLocks);
}

void input()
{
	if (PLAYER->_controller._keys._pauseIsPressed)
	{
		RODANDO = false;
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

	SDL_SetRenderDrawColor(renderizador, 155, 155, 155, 255);
	SDL_RenderDrawRect(renderizador, &bordaE);
	SDL_RenderFillRect(renderizador, &bordaE);

	for (Rect4 block : MAP._collisionBLocks)
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

	PLAYER->draw(renderizador, SCALE);

	// // Renderiza
	SDL_RenderPresent(renderizador);
}
