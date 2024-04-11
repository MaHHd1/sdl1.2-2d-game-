#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>

typedef struct {
    char *filename;
    SDL_Surface *surface;

} IMG;
typedef struct {
    IMG image[3][5];// matrice type IMG Struct 
    SDL_Rect posScreen;// pos fel ecran 
    SDL_Rect posIMG;
    float acceleration;// yejri wala lee
    float vitesse;
    int up;// jump wala lee 0 or 1
    int direction;// el i mtah el matrice image ;)
    int num;// el j mtah el matrice 
    float Step;// How much does he need to move 
    

} Personne;



void initPerso(Personne *p);
void afficherPerso(Personne p,SDL_Surface *screen);
void movePerso(Personne *p,Uint32 dt);
void animerPerso(Personne p);
void saut(Personne *P,int dt, int posinit);
