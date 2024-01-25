#include "PlayerController.hpp"
#include <SDL2/SDL.h>

PlayerController::PlayerController()
{
}

void PlayerController::update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            _keys._pauseIsPressed = true;
        }

        if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
        {
            bool state;
            if (event.type == SDL_KEYDOWN)
            {
                state = true;
            }
            if (event.type == SDL_KEYUP)
            {
                state = false;
            }

            switch (event.key.keysym.sym)
            {
                // MOVEMENT
            case SDLK_w:
                _keys._wIsPressed = state;
                break;
            case SDLK_a:
                _keys._aIsPressed = state;
                break;
            case SDLK_d:
                _keys._dIsPressed = state;
                break;

                // ATTACK
            case SDLK_SPACE:
                _keys._n1IsPressed = state;
                break;

                //  MENU
            case SDLK_ESCAPE:
                _keys._pauseIsPressed = state;
                break;
            default:
                break;
            }
        }
    }
}