#ifndef STRUCT_H
#define STRUCT_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#define SCREEN_H 1080
#define SCREEN_W 1920

typedef struct
{
	char *url;
	SDL_Rect pos_img;   //position de l'image par rapport a l'ecran
	SDL_Rect part_img;  //la partie de l'image a afficher
	SDL_Surface *img;
	
	
 

}image;

typedef struct
{
	char url[100];
	SDL_Rect pos_img_affiche;//partie de l'image qui doit etre affichée
        SDL_Rect pos_img_ecran; // position de l'image par rapport l'écran
	SDL_Surface *img;
}Image;

typedef struct
{
SDL_Surface *anim[100];
SDL_Rect pos;


}Animation;


typedef struct
{
	SDL_Surface *txt;
	SDL_Rect pos_txt;
	SDL_Colour color_txt;
	TTF_Font *police;


}text;


typedef struct
{
Mix_Music *music;
Mix_Chunk *cmusic;
}audio;


//void initialisation_backgroundimage(image *back_img);

void initialisation_start_button(image *start_img);

void initialisation_settings_background(image *coming_soon);

void initialisation_coming_soon(image *coming_soon);
void initialisation_settings_button(image *settings_img);
void initialisation_settings_background(image *settingsbackground);
void initialisation_quit_button(image *quit_img);
void initialisation_background_music(audio *back_music);
void initialisation_button_sound(audio *button_sound);
void initialisation_du_text(text *txte);
void initialisation_updated_start_button(image *starteffect_img);
void initialisation_updated_settings_button(image *settingseffect_img);
void initialisation_updated_quit_button(image *quiteffect_img);
//void affichage_backgroundimage(SDL_Surface *screen,image back_img);
void affichage_start_button(SDL_Surface *screen,image start_img);
void affichage_settings_button(SDL_Surface *screen,image settings_img);
void affichage_settings_background(SDL_Surface *screen,image settingsbackground);
void affichage_quit_button(SDL_Surface *screen,image quit_img);
void affichage_du_text(SDL_Surface *screen,text txte);
void affichage_coming_soon(SDL_Surface *screen,image coming_soon);
void affichage_updated_start_button(SDL_Surface *screen,image starteffect_img);
void affichage_updated_settings_button(SDL_Surface *screen,image settingseffect_img);
void affichage_updated_quit_button(SDL_Surface *screen,image quiteffect_img);
void liberer_image(image imgee);
void liberer_background_music(audio *back_music);
void liberer_button_sound(audio *button_sound);
void liberer_du_texte(text txte);
//animation
/*void initialiser_imageBACK(Image *img);
void afficher_imageBACK(SDL_Surface *screen, Image img);
void liberer_imageBACK(Image img);*/

void initialiser_animation(Animation *animat);
void afficher_animation(Animation animat,SDL_Surface *screen);
void liberer_animation(Animation animat);
//initialisation des images de %

void initialisation_0_img(image *img0);
void initialisation_10_img(image *img10);
void initialisation_20_img(image *img20);
void initialisation_30_img(image *img30);
void initialisation_40_img(image *img40);
void initialisation_50_img(image *img50);
void initialisation_60_img(image *img60);
void initialisation_70_img(image *img70);
void initialisation_80_img(image *img80);
void initialisation_90_img(image *img90);
void initialisation_100_img(image *img100);


//affichage des images de %
void affichage_0_img(SDL_Surface *screen,image img0);
void affichage_10_img(SDL_Surface *screen,image img10);
void affichage_20_img(SDL_Surface *screen,image img20);
void affichage_30_img(SDL_Surface *screen,image img30);
void affichage_40_img(SDL_Surface *screen,image img40);
void affichage_50_img(SDL_Surface *screen,image img50);
void affichage_60_img(SDL_Surface *screen,image img60);
void affichage_70_img(SDL_Surface *screen,image img70);
void affichage_80_img(SDL_Surface *screen,image img80);
void affichage_90_img(SDL_Surface *screen,image img90);
void affichage_100_img(SDL_Surface *screen,image img100);

//volume modification
void volume_mod(audio *back_music,audio *button_sound,int volumestate);

//on and off fullscreen
void initialisation_onFS(image *onF);
void initialisation_offFS(image *offF);
void affichage_onFS(SDL_Surface *screen,image onF);
void affichage_offFS(SDL_Surface *screen,image offF);

//mute on off
void initialisation_mute_off(image *muteoff);
void initialisation_mute_on(image *muteon);
void affichage_mute_off(SDL_Surface *screen,image muteoff);
void affichage_mute_on(SDL_Surface *screen,image muteon);


void initialisation_credits_button(image *start_img);
void affichage_credits_button(SDL_Surface *screen,image start_img);
void initialisation_updated_credits_button(image *settingseffect_img);
void affichage_updated_credits_button(SDL_Surface *screen,image settingseffect_img);
void initialisation_credits(image *coming_soon);
void affichage_credits(SDL_Surface *screen,image coming_soon);
void initialisation_plus_button(image *starteffect_img);
void affichage_plus_button(SDL_Surface *screen,image starteffect_img);
void initialisation_back_button(image *start_img);
void affichage_back_button(SDL_Surface *screen,image start_img);
#endif
