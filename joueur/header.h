#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdbool.h>

#define SCREEN_W 1920
#define SCREEN_H 1080
typedef struct
{
    SDL_Surface *per;
} IMG;

typedef struct
{
    IMG image[3][5];
    SDL_Rect posScreen;
    float acceleration;
    float vitesse;
    int up;
    int direction;
    int num;
    float Step;
    int score;
    int moving;
} Personne;
typedef struct{
	SDL_Surface *url;
	SDL_Rect pos;
}image;

void initPerso(Personne *p);
void initPerso2(Personne *p);
void afficherPerso(Personne *p, SDL_Surface *screen);
void movePerso(Personne *p, Uint32 dt);
void animerPerso(Personne *p);
void saut(Personne *p, int dt, int posinit);
void liberer(Personne *p);
void initIMG(image *IMG,int x,int y,char nom[]);
void afficher_image(SDL_Surface *surf,image img);

#endif /* HEADER_H */

