#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "draw.h"
#include "input.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

SDL_Rect sprite;
SDL_Texture *texture = NULL;

void update()
{
    sprite.x += velocity.x;
    sprite.y += velocity.y;
}

void draw()
{
    SDL_RenderCopy(renderer, texture, NULL, &sprite);
}