#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <emscripten.h>

#include "init.h"
#include "draw.h"
#include "events.h"
#include "input.h"

void main_loop()
{
    process_events();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    update();
    draw();

    SDL_RenderPresent(renderer);
    
}

void destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main()
{
    init();
    load_textures();

    sprite.x = (WINDOW_WIDTH - DRAW_SIZE) / 2;
    sprite.y = (WINDOW_HEIGHT - DRAW_SIZE) / 2;
    
    printf("--- begin main loop ---\n");
    emscripten_set_main_loop(main_loop, 0, 1);
    printf("--- end main loop ---\n");
    printf("this should never happen.\n");
    
    return EXIT_SUCCESS;
}