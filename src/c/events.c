#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "events.h"
#include "input.h"

void process_events()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        handle_keyboard(&event);
    }
}