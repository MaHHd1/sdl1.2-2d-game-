#ifndef IMAGE_H
#define IMAGE_H

#include <SDL/SDL.h>

typedef struct {
    char *filename;
    SDL_Surface *surface;
} Image;

void load_images(Image images[]);
void free_images(Image images[]);

#endif
