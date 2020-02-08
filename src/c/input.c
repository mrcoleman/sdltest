#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "input.h"

SDL_Point velocity = {0, 0};

void handle_keyboard(SDL_Event *event)
{
    SDL_Keycode key = event->key.keysym.sym;

    if (event->key.type == SDL_KEYDOWN)
    {
        if (key == SDLK_LEFT || key == SDLK_RIGHT)
        {
            velocity.x = key == SDLK_LEFT ? -1 : 1;
        }
        if (key == SDLK_UP || key == SDLK_DOWN)
        {
            velocity.y = key == SDLK_UP ? -1 : 1;
        }
    }
    if (event->key.type == SDL_KEYUP)
    {
        if (key == SDLK_LEFT || key == SDLK_RIGHT)
        {
            velocity.x = 0;
        }
        if (key == SDLK_UP || key == SDLK_DOWN)
        {
            velocity.y = 0;
        }
    }
}

