#ifndef GAMESYSTEM_HPP
#define GAMESYSTEM_HPP

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../PlayerController/PlayerController.hpp"
#include "../HeroClient/HeroClient.hpp"
#include "../ProjectileClient/ProjectileClient.hpp"
#include "../GameMapCLient/GameMapClient.hpp"
#include "../../Base/Sizes/Sizes.hpp"
#include "../ClientSocket/ClientSocket.hpp"

class GameSystem
{
public:
    // SDL
    SDL_Window *_window = nullptr;
    SDL_Renderer *_renderer = nullptr;

    // WINDOW
    bool TELA_CHEIA = false;
    const int _fps = 60;
    int _scale = 1;
    int _width = SCREEN_SIZE.x * _scale;
    int _height = SCREEN_SIZE.y * _scale;

    // Logic
    bool RODANDO = true;

    // GAME OBJECTS
    GameMapClient *_MAP;
    PlayerController _CONTROLLER;
    HeroClient _PLAYER;
    std::vector<ProjectileClient> _PROJECTILES;
    std::vector<HeroClient> _PLAYERS;
    ClientSocket _CLIENT;

    // MAP AUXS
    const int TILE_NUMBER = SCREEN_SIZE.x * SCREEN_SIZE.y / (TILE_SIZE.x * TILE_SIZE.y);
    std::vector<bool> BLOCKS = std::vector<bool>(TILE_NUMBER, false);

    GameSystem();
    ~GameSystem();

    void inicializacao_SDL();
    void encerramento_SDL();

    void game_loop();
    void update();
    void input();
    void draw();
};

#endif