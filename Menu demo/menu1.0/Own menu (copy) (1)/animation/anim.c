#include "anim.h"

void load_images(Image images[]) {
    images[0].filename = "back/img1.BMP";
    images[1].filename = "back/img2.BMP";
    images[2].filename = "back/img3.BMP";

    for (int i = 0; i < 3; i++) {
        images[i].surface = SDL_LoadBMP(images[i].filename);
        if (images[i].surface == NULL) {
            fprintf(stderr, "Erreur lors du chargement de l'image %s : %s\n", images[i].filename, SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }
}

void free_images(Image images[]) {
    for (int i = 0; i < 3; i++) {
        SDL_FreeSurface(images[i].surface);
    }
}
