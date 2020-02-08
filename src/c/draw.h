#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define DRAW_SIZE 64

extern SDL_Window *window;
extern SDL_Renderer *renderer;

extern SDL_Rect sprite;
extern SDL_Texture *texture;

void update();

void draw();