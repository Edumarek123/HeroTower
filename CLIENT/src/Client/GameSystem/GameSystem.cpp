#include "GameSystem.hpp"

#include <iostream>
#include "../../Base//SDerialization/SDerialization.hpp"

GameSystem::GameSystem()
{
    inicializacao_SDL();
    _MAP = new GameMapClient(_renderer);
}

GameSystem::~GameSystem()
{
    encerramento_SDL();
}

void GameSystem::inicializacao_SDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        std::cout << "Erro encontrado:  " << SDL_GetError() << std::endl;
    if (TELA_CHEIA)
    {
        SDL_CreateWindowAndRenderer(_width, _height, SDL_WINDOW_FULLSCREEN_DESKTOP, &_window, &_renderer);
    }
    else
    {
        SDL_CreateWindowAndRenderer(_width, _height, SDL_WINDOW_SHOWN, &_window, &_renderer);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    SDL_SetRenderDrawBlendMode(_renderer, SDL_BLENDMODE_BLEND);
    SDL_SetWindowTitle(_window, "Hero Tower");

    /*
    SDL_DisplayMode DM;
    int w, h;
    SDL_GetRendererOutputSize(renderer, &w, &h);
    std::cout << "_width: " << w << " _height: " << h << std::endl;
    SDL_GetCurrentDisplayMode(0, &DM);
    std::cout << "_width: " << DM.w << " _height: " << DM.h << std::endl;

    std::cout << "EXTRA - _width: " << DM.w % (int)SCREEN_SIZE.x << " EXTRA - _height: " << DM.h % (int)SCREEN_SIZE.y << std::endl;
    std::cout << "MAX - _width: " << std::floor((float)DM.w / SCREEN_SIZE.x) << " MAX - _height: " << std::floor((float)DM.h / SCREEN_SIZE.y) << std::endl;
    */
}

void GameSystem::encerramento_SDL()
{
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    SDL_Quit();
}

void GameSystem::game_loop()
{
    while (RODANDO)
    {
        int fps_timer = SDL_GetTicks();

        update();
        input();
        draw();

        int delta_fps = SDL_GetTicks() - fps_timer;
        if (1000 / _fps > delta_fps)
        {
            SDL_Delay(1000 / _fps - delta_fps);
        }
    }
}

void GameSystem::update()
{
    _CLIENT.update(_OBJECTS);

    _PLAYER.update(_MAP->_collisionBLocks, _CONTROLLER._keys);

    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        if (_PROJECTILES[i]._isActive)
        {
            _PROJECTILES[i].update(_MAP->_collisionBLocks);
        }
    }
}

void GameSystem::input()
{
    _CONTROLLER.update();

    if (_CONTROLLER._keyIsPressed)
    {
        int packetLen = 0;
        char *packet = serialize(_CONTROLLER._keys, "key", packetLen);
        _CLIENT.sendPacket(packet, packetLen);
        free(packet);
    }

    if (_CONTROLLER._keys._pauseIsPressed)
    {
        RODANDO = false;
    }

    if (_CONTROLLER._keys._n1IsPressed && !_PROJECTILES[0]._isActive)
    {
        _PROJECTILES[0] = ProjectileClient(_PLAYER);
        _PROJECTILES[0]._isActive = true;
    }
}

void GameSystem::draw()
{
    // Limpa tela
    SDL_RenderClear(_renderer);
    SDL_SetRenderDrawColor(_renderer, 255, 0, 255, 255); // bota rosa para debug

    _MAP->draw(_renderer, _PLAYER._position.x, _PLAYER._position.y, _scale);

    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        if (_PROJECTILES[i]._isActive)
        {
            _PROJECTILES[i].draw(_renderer, _scale);
        }

        _PLAYERS[i].draw(_renderer, _scale);
    }

    _PLAYER.draw(_renderer, _scale);

    // // Renderiza
    SDL_RenderPresent(_renderer);
}
