#include <SDL/SDL.h>
#include <stdio.h>
#include "anim.h"

int main(int argc, char *argv[]) {
    SDL_Surface *screen;
    SDL_Event event;
    int running = 1;
    int current_image = 0;
    int num_images = 3;
    Image images[3];

    // Initialisation de la SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Création de la fenêtre
    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Chargement des images
    load_images(images);

    // Boucle principale
    while (running) {
        // Gestion des événements
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
            }
        }

        // Affichage de l'image courante
        SDL_BlitSurface(images[current_image].surface, NULL, screen, NULL);
        SDL_Flip(screen);

        // Passage à l'image suivante
        current_image++;
        if (current_image >= num_images) {
            current_image = 0;
        }

        // Attente de 200 ms
        SDL_Delay(200);
    }

    // Libération de la mémoire
    free_images(images);

    // Fermeture de la SDL
    SDL_Quit();

    return 0;
}
