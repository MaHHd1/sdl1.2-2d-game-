#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "struct.h"



//******************* BACKGROUND IMAGE FUNCTIONS *******************
/* void initialisation_backgroundimage(image *back_img)
{
back_img->url="background.png";    //
back_img->img=IMG_Load(back_img->url);
if(back_img->img==NULL)
{
printf("unable to load background image %s \n",SDL_GetError());
return;
}
back_img->pos_img.x=0;
back_img->pos_img.y=0;
back_img->pos_img.h=1920;
back_img->pos_img.w=1080;

back_img->part_img.x=0;
back_img->part_img.y=0;
}


void affichage_backgroundimage(SDL_Surface *screen,image back_img)
{
SDL_BlitSurface(back_img.img,NULL,screen,NULL);  //&back_img.part_img

}
*/
void liberer_image(image imgee)
{
SDL_FreeSurface(imgee.img);

}

//******************* START BUTTON IMAGE FUNCTIONS *******************
void initialisation_start_button(image *start_img)
{
start_img->url="start.png";
start_img->img=IMG_Load(start_img->url);
if(start_img->img==NULL)
{
printf("unable to load start image %s \n",SDL_GetError());
return;
}
start_img->pos_img.x=0;
start_img->pos_img.y=0;
start_img->pos_img.w=1700;
start_img->pos_img.h=200;
start_img->part_img.x=340;
start_img->part_img.y=320;

}

void affichage_start_button(SDL_Surface *screen,image start_img)
{
SDL_BlitSurface(start_img.img,NULL,screen,&start_img.part_img);   

}

//******************* BACK BUTTON IMAGE FUNCTIONS *******************
void initialisation_back_button(image *start_img)
{
start_img->url="back.png";
start_img->img=IMG_Load(start_img->url);
if(start_img->img==NULL)
{
printf("unable to load start image %s \n",SDL_GetError());
return;
}
start_img->pos_img.x=0;
start_img->pos_img.y=0;
start_img->pos_img.w=1700;
start_img->pos_img.h=200;
start_img->part_img.x=695;
start_img->part_img.y=650;

}

void affichage_back_button(SDL_Surface *screen,image start_img)
{
SDL_BlitSurface(start_img.img,NULL,screen,&start_img.part_img);   

}

//******************* CREDITS BUTTON IMAGE FUNCTIONS *******************
void initialisation_credits_button(image *start_img)
{
start_img->url="credits.png";
start_img->img=IMG_Load(start_img->url);
if(start_img->img==NULL)
{
printf("unable to load start image %s \n",SDL_GetError());
return;
}
start_img->pos_img.x=0;
start_img->pos_img.y=0;
start_img->pos_img.w=1700;
start_img->pos_img.h=200;
start_img->part_img.x=340;
start_img->part_img.y=480;

}

void affichage_credits_button(SDL_Surface *screen,image start_img)
{
SDL_BlitSurface(start_img.img,NULL,screen,&start_img.part_img);   

}

//******************* UPDATED_CREDITS BUTTON IMAGE FUNCTIONS *******************
void initialisation_updated_credits_button(image *settingseffect_img)
{
settingseffect_img->url="creditseffect.png";
settingseffect_img->img=IMG_Load(settingseffect_img->url);
if(settingseffect_img->img==NULL)
{
printf("unable to load settings effect image %s \n",SDL_GetError());
return;
}
settingseffect_img->pos_img.x=0;
settingseffect_img->pos_img.y=0;
settingseffect_img->pos_img.w=1700;
settingseffect_img->pos_img.h=500;
settingseffect_img->part_img.x=340;
settingseffect_img->part_img.y=480;

}

void affichage_updated_credits_button(SDL_Surface *screen,image settingseffect_img)
{
SDL_BlitSurface(settingseffect_img.img,NULL,screen,&settingseffect_img.part_img);
}



//******************* UPDATED START BUTTON IMAGE FUNCTIONS *******************
void initialisation_updated_start_button(image *starteffect_img)
{
starteffect_img->url="starteffect.png";
starteffect_img->img=IMG_Load(starteffect_img->url);
if(starteffect_img->img==NULL)
{
printf("unable to load start effect image %s \n",SDL_GetError());
return;
}
starteffect_img->pos_img.x=0;
starteffect_img->pos_img.y=0;
starteffect_img->pos_img.w=1700;
starteffect_img->pos_img.h=200;
starteffect_img->part_img.x=340;
starteffect_img->part_img.y=320;

}

void affichage_updated_start_button(SDL_Surface *screen,image starteffect_img)
{
SDL_BlitSurface(starteffect_img.img,NULL,screen,&starteffect_img.part_img);   

}
//******************* START BACKGROUND IMAGE FUNCTIONS *******************
void initialisation_coming_soon(image *coming_soon)
{
coming_soon->url="coming soon.png";
coming_soon->img=IMG_Load(coming_soon->url);
if(coming_soon->img==NULL)
{
printf("unable to load coming_soon background image %s \n",SDL_GetError());
return;
}


}
void affichage_coming_soon(SDL_Surface *screen,image coming_soon)
{

SDL_BlitSurface(coming_soon.img,NULL,screen,NULL);  //&coming_soon.part_img

}
//******************* CREDITS BACKGROUND IMAGE FUNCTIONS *******************
void initialisation_credits(image *coming_soon)
{
coming_soon->url="creditsback.png";
coming_soon->img=IMG_Load(coming_soon->url);
if(coming_soon->img==NULL)
{
printf("unable to load coming_soon background image %s \n",SDL_GetError());
return;
}


}
void affichage_credits(SDL_Surface *screen,image coming_soon)
{

SDL_BlitSurface(coming_soon.img,NULL,screen,NULL);  //&coming_soon.part_img

}
//******************* SETTINGS BACKGROUND IMAGE FUNCTIONS *******************
void initialisation_settings_background(image *settingsbackground)
{
settingsbackground->url="settings_background.png";
settingsbackground->img=IMG_Load(settingsbackground->url);
if(settingsbackground->img==NULL)
{
printf("unable to load settings background image %s \n",SDL_GetError());
return;
}


}
void affichage_settings_background(SDL_Surface *screen,image settingsbackground)
{

SDL_BlitSurface(settingsbackground.img,NULL,screen,NULL);  //&settingsbackground.part_img

}
//******************* SETTINGS BUTTON IMAGE FUNCTIONS *******************
void initialisation_settings_button(image *settings_img)
{
settings_img->url="settings.png";
settings_img->img=IMG_Load(settings_img->url);
if(settings_img->img==NULL)
{
printf("unable to load settings image %s \n",SDL_GetError());
return;
}
settings_img->pos_img.x=0;
settings_img->pos_img.y=0;
settings_img->pos_img.w=1700;
settings_img->pos_img.h=500;
settings_img->part_img.x=340;
settings_img->part_img.y=400;

}

void affichage_settings_button(SDL_Surface *screen,image settings_img)
{
SDL_BlitSurface(settings_img.img,NULL,screen,&settings_img.part_img);
}



//******************* UPDATED_SETTINGS BUTTON IMAGE FUNCTIONS *******************
void initialisation_updated_settings_button(image *settingseffect_img)
{
settingseffect_img->url="settingseffect.png";
settingseffect_img->img=IMG_Load(settingseffect_img->url);
if(settingseffect_img->img==NULL)
{
printf("unable to load settings effect image %s \n",SDL_GetError());
return;
}
settingseffect_img->pos_img.x=0;
settingseffect_img->pos_img.y=0;
settingseffect_img->pos_img.w=1700;
settingseffect_img->pos_img.h=500;
settingseffect_img->part_img.x=340;
settingseffect_img->part_img.y=400;

}

void affichage_updated_settings_button(SDL_Surface *screen,image settingseffect_img)
{
SDL_BlitSurface(settingseffect_img.img,NULL,screen,&settingseffect_img.part_img);
}

//******************* QUIT BUTTON IMAGE FUNCTIONS *******************
void initialisation_quit_button(image *quit_img)
{
quit_img->url="quit.png";
quit_img->img=IMG_Load(quit_img->url);
if(quit_img->img==NULL)
{
printf("unable to load quit image %s \n",SDL_GetError());
return;
}
quit_img->pos_img.x=0;
quit_img->pos_img.y=0;
quit_img->pos_img.w=1700;
quit_img->pos_img.h=360;
quit_img->part_img.x=340;
quit_img->part_img.y=560;


}

void affichage_quit_button(SDL_Surface *screen,image quit_img)
{
SDL_BlitSurface(quit_img.img,NULL,screen,&quit_img.part_img);
}



//******************* UPDATED QUIT BUTTON IMAGE FUNCTIONS *******************
void initialisation_updated_quit_button(image *quiteffect_img)
{
quiteffect_img->url="quiteffect.png";
quiteffect_img->img=IMG_Load(quiteffect_img->url);
if(quiteffect_img->img==NULL)
{
printf("unable to load quit image %s \n",SDL_GetError());
return;
}
quiteffect_img->pos_img.x=0;
quiteffect_img->pos_img.y=0;
quiteffect_img->pos_img.w=113;
quiteffect_img->pos_img.h=55;
quiteffect_img->part_img.x=340;
quiteffect_img->part_img.y=560;


}

void affichage_updated_quit_button(SDL_Surface *screen,image quiteffect_img)
{
SDL_BlitSurface(quiteffect_img.img,NULL,screen,&quiteffect_img.part_img);
}

//******************* BACKGROUND MUSIC FUNCTIONS *******************

void initialisation_background_music(audio *back_music)
{
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("unable to play background music %s \n",SDL_GetError());
}
back_music->music=Mix_LoadMUS("background music.mp3");
Mix_PlayMusic(back_music->music,-1);
Mix_VolumeMusic(MIX_MAX_VOLUME*0.5);
}



void liberer_background_music(audio *back_music)
{
Mix_FreeMusic(back_music->music);
}




//******************* TEXT FUNCTIONS *******************
void initialisation_du_text(text *txte)
{
TTF_Init();
txte->police=TTF_OpenFont("flashrogers.ttf",45);
txte->color_txt.r=0;
txte->color_txt.g=0;
txte->color_txt.b=0;

txte->pos_txt.x=300;
txte->pos_txt.y=20;

}

void affichage_du_text(SDL_Surface *screen,text txte)
{
txte.txt=TTF_RenderText_Blended(txte.police,"vanish of the elites",txte.color_txt);
SDL_BlitSurface(txte.txt,NULL,screen,&txte.pos_txt);



}

void liberer_du_texte(text txte)
{
TTF_CloseFont (txte.police);
TTF_Quit();

}

//******************* BUTTON SOUND FUNCTIONS *******************
void initialisation_button_sound(audio *button_sound)
{
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,2048)==-1)
{
printf("unable to play button sound effect %s \n",SDL_GetError());
}
button_sound->cmusic=Mix_LoadWAV("mouse buttoon.wav");
Mix_PlayChannel(1,button_sound->cmusic,0);
Mix_VolumeChunk(button_sound->cmusic,MIX_MAX_VOLUME*0.5);
}

void liberer_button_sound(audio *button_sound)
{
Mix_FreeChunk(button_sound->cmusic);
}


//******************* 0% FUNCTIONS *******************
void initialisation_0_img(image *img0)
{
img0->url="0%.png";
img0->img=IMG_Load(img0->url);
if(img0->img==NULL)
{
printf("unable to load 0 image %s \n",SDL_GetError());
return;
}
img0->pos_img.x=370;  
img0->pos_img.y=378;  
img0->pos_img.w=550;
img0->pos_img.h=67;



}

void affichage_0_img(SDL_Surface *screen,image img0)
{
SDL_BlitSurface(img0.img,NULL,screen,&img0.pos_img);
}



//******************* 10% FUNCTIONS *******************
void initialisation_10_img(image *img10)
{
img10->url="10%.png";
img10->img=IMG_Load(img10->url);
if(img10->img==NULL)
{
printf("unable to load 10 image %s \n",SDL_GetError());
return;
}
img10->pos_img.x=370;
img10->pos_img.y=378;
img10->pos_img.w=550;
img10->pos_img.h=67;



}

void affichage_10_img(SDL_Surface *screen,image img10)
{
SDL_BlitSurface(img10.img,NULL,screen,&img10.pos_img);
}


//******************* 20% FUNCTIONS *******************
void initialisation_20_img(image *img20)
{
img20->url="20%.png";
img20->img=IMG_Load(img20->url);
if(img20->img==NULL)
{
printf("unable to load 20 image %s \n",SDL_GetError());
return;
}
img20->pos_img.x=370;
img20->pos_img.y=378;
img20->pos_img.w=550;
img20->pos_img.h=67;



}

void affichage_20_img(SDL_Surface *screen,image img20)
{
SDL_BlitSurface(img20.img,NULL,screen,&img20.pos_img);
}

//******************* 30% FUNCTIONS *******************
void initialisation_30_img(image *img30)
{
img30->url="30%.png";
img30->img=IMG_Load(img30->url);
if(img30->img==NULL)
{
printf("unable to load 30 image %s \n",SDL_GetError());
return;
}
img30->pos_img.x=370;
img30->pos_img.y=378;
img30->pos_img.w=550;
img30->pos_img.h=67;



}

void affichage_30_img(SDL_Surface *screen,image img30)
{
SDL_BlitSurface(img30.img,NULL,screen,&img30.pos_img);
}


//******************* 40% FUNCTIONS *******************
void initialisation_40_img(image *img40)
{
img40->url="40%.png";
img40->img=IMG_Load(img40->url);
if(img40->img==NULL)
{
printf("unable to load 40 image %s \n",SDL_GetError());
return;
}
img40->pos_img.x=370;
img40->pos_img.y=378;
img40->pos_img.w=550;
img40->pos_img.h=67;



}

void affichage_40_img(SDL_Surface *screen,image img40)
{
SDL_BlitSurface(img40.img,NULL,screen,&img40.pos_img);
}


//******************* 50% FUNCTIONS *******************
void initialisation_50_img(image *img50)
{
img50->url="50%.png";
img50->img=IMG_Load(img50->url);
if(img50->img==NULL)
{
printf("unable to load 50 image %s \n",SDL_GetError());
return;
}
img50->pos_img.x=370;
img50->pos_img.y=378;
img50->pos_img.w=550;
img50->pos_img.h=67;



}

void affichage_50_img(SDL_Surface *screen,image img50)
{
SDL_BlitSurface(img50.img,NULL,screen,&img50.pos_img);
}

//******************* 60% FUNCTIONS *******************
void initialisation_60_img(image *img60)
{
img60->url="60%.png";
img60->img=IMG_Load(img60->url);
if(img60->img==NULL)
{
printf("unable to load 60 image %s \n",SDL_GetError());
return;
}
img60->pos_img.x=370;
img60->pos_img.y=378;
img60->pos_img.w=550;
img60->pos_img.h=67;



}

void 	affichage_60_img(SDL_Surface *screen,image img60)
{
SDL_BlitSurface(img60.img,NULL,screen,&img60.pos_img);
}

//******************* 70% FUNCTIONS *******************
void initialisation_70_img(image *img70)
{
img70->url="70%.png";
img70->img=IMG_Load(img70->url);
if(img70->img==NULL)
{
printf("unable to load 70 image %s \n",SDL_GetError());
return;
}
img70->pos_img.x=370;
img70->pos_img.y=378;
img70->pos_img.w=550;
img70->pos_img.h=67;



}

void affichage_70_img(SDL_Surface *screen,image img70)
{
SDL_BlitSurface(img70.img,NULL,screen,&img70.pos_img);
}


//******************* 80% FUNCTIONS *******************
void initialisation_80_img(image *img80)
{
img80->url="80%.png";
img80->img=IMG_Load(img80->url);
if(img80->img==NULL)
{
printf("unable to load 80 image %s \n",SDL_GetError());
return;
}
img80->pos_img.x=370;
img80->pos_img.y=378;
img80->pos_img.w=550;
img80->pos_img.h=67;



}

void affichage_80_img(SDL_Surface *screen,image img80)
{
SDL_BlitSurface(img80.img,NULL,screen,&img80.pos_img);
}

//******************* 90% FUNCTIONS *******************
void initialisation_90_img(image *img90)
{
img90->url="90%.png";
img90->img=IMG_Load(img90->url);
if(img90->img==NULL)
{
printf("unable to load 90 image %s \n",SDL_GetError());
return;
}
img90->pos_img.x=370;
img90->pos_img.y=378;
img90->pos_img.w=550;
img90->pos_img.h=67;



}

void affichage_90_img(SDL_Surface *screen,image img90)
{
SDL_BlitSurface(img90.img,NULL,screen,&img90.pos_img);
}


//******************* 100% FUNCTIONS *******************
void initialisation_100_img(image *img100)
{
img100->url="100%.png";
img100->img=IMG_Load(img100->url);
if(img100->img==NULL)
{
printf("unable to load 100 image %s \n",SDL_GetError());
return;
}
img100->pos_img.x=370;
img100->pos_img.y=378;
img100->pos_img.w=550;
img100->pos_img.h=67;



}

void affichage_100_img(SDL_Surface *screen,image img100)
{
SDL_BlitSurface(img100.img,NULL,screen,&img100.pos_img);
}



//******************* mute on off FUNCTIONS *******************

void initialisation_mute_off(image *muteoff)
{
muteoff->url="off.png";
muteoff->img=IMG_Load(muteoff->url);
if(muteoff->img==NULL)
{
printf("unable to load off image %s \n",SDL_GetError());
return;
}
muteoff->pos_img.x=340;
muteoff->pos_img.y=475;
muteoff->pos_img.w=552;
muteoff->pos_img.h=72;


}
void initialisation_mute_on(image *muteon)
{
muteon->url="on.png";
muteon->img=IMG_Load(muteon->url);
if(muteon->img==NULL)
{
printf("unable to load on image %s \n",SDL_GetError());
return;
}
muteon->pos_img.x=340;
muteon->pos_img.y=475;
muteon->pos_img.w=552;
muteon->pos_img.h=72;

}
void affichage_mute_off(SDL_Surface *screen,image muteoff)
{
SDL_BlitSurface(muteoff.img,NULL,screen,&muteoff.pos_img);
}
void affichage_mute_on(SDL_Surface *screen,image muteon)
{
SDL_BlitSurface(muteon.img,NULL,screen,&muteon.pos_img);
}

//on and off fullscreen
void initialisation_onFS(image *onF)
{
onF->url="on.png";
onF->img=IMG_Load(onF->url);
if(onF->img==NULL)
{
printf("unable to load on image %s \n",SDL_GetError());
return;
}
onF->pos_img.x=340;
onF->pos_img.y=245;
onF->pos_img.w=552;
onF->pos_img.h=72;

}
void initialisation_offFS(image *offF)
{
offF->url="off.png";
offF->img=IMG_Load(offF->url);
if(offF->img==NULL)
{
printf("unable to load off image %s \n",SDL_GetError());
return;
}
offF->pos_img.x=340;
offF->pos_img.y=245;
offF->pos_img.w=552;
offF->pos_img.h=72;
}
void affichage_onFS(SDL_Surface *screen,image onF)
{
SDL_BlitSurface(onF.img,NULL,screen,&onF.pos_img);
}
void affichage_offFS(SDL_Surface *screen,image offF)
{
SDL_BlitSurface(offF.img,NULL,screen,&offF.pos_img);
}
//volume modification function
void volume_mod(audio *back_music,audio *button_sound,int volumestate)
{
float a;
float volumest= (float) volumestate;
a=volumest/10;
Mix_VolumeMusic(MIX_MAX_VOLUME * a);
Mix_VolumeChunk(button_sound->cmusic,MIX_MAX_VOLUME * a);
}


/*void initialiser_imageBACK(Image *imge)
{

imge->img=IMG_Load("background/background0.png");
if (imge->img == NULL){
	printf("unable to load background image %s \n",SDL_GetError()); 
	return ;}

imge->pos_img_affiche.x=0;
imge->pos_img_affiche.y=0;
imge->pos_img_affiche.h=SCREEN_H;
imge->pos_img_affiche.w=SCREEN_W;

imge->pos_img_ecran.x=0;
imge->pos_img_ecran.y=0;
}


void afficher_imageBACK(SDL_Surface *screen, Image imge)
{
//Coller et Afficher l'image du back dans screen
SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);
}


void liberer_imageBACK(Image imge)
{
SDL_FreeSurface(imge.img);
}

*/

void initialiser_animation(Animation *animat)
{
int i;
char c[3],chemin[100]="";

animat->anim[0]=IMG_Load("background/background0.png");

for(i=1;i<=22;i++)
{
strcpy(chemin,"background/background");
sprintf(c,"%d",i);

strcat(chemin,c);
strcat(chemin,".png");

animat->anim[i-1]=IMG_Load(chemin);
}

// initialiser la position
animat->pos.x=0;
animat->pos.y=0;
}





void afficher_animation( Animation animat,SDL_Surface *screen)
{
int i;
for(i=0;i<=22;i++)
{
SDL_BlitSurface(animat.anim[i],NULL,screen,&animat.pos);
SDL_Delay(100);
SDL_Flip(screen);
}
}



void liberer_animation(Animation animat)
{
int i;
for(i=0;i<=22;i++)
SDL_FreeSurface(animat.anim[i]);

}




























