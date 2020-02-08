#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "init.h"
#include "draw.h"

bool init()
{
    printf("--- begin init ---\n");
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return false;
    }
    printf("creating window\n");
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);
    if (window == NULL | renderer == NULL)
    {
        return false;
    }
    printf("--- end init ---\n");
    return true;
}

void load_textures()
{
    printf("--- begin load textures ---\n");
    SDL_Surface *surface = IMG_Load("assets/texture.png");
    if (!surface)
    {
        printf("%s\n", IMG_GetError());
    }
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0x75, 0xFF, 0xFF));
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    printf("--- end load textures ---\n");
}