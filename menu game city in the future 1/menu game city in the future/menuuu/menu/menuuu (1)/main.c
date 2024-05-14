#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "struct.h"



int main(int argc, char *argv[])
{

 SDL_Surface *screen=NULL;
 image backimg,startimg,creditimg,crediteffet,comingsoon,settingsimg,settings_background,quitimg,starteffet,settingseffet,quiteffet,onFS,offFS,muteon,muteoff,credits;
 Animation animat;
 audio backmusic,buttonsound;
 text textt;
 Image back;
 Animation anim;
 SDL_Event event;
 int boucle=1;
 int animation;
 int currentScreen=1;
 int startstate=0;
 int creditstate=0;
 int settingsstate=0;
 int FSstate=0;
 int mutestate=0;
 int quitstate=0;
 image img0,img10,img20,img30,img40,img50,img60,img70,img80,img90,img100;
 int volumestate=5;
 
 	
	// Initialiser SDL
  if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) !=0) {
    printf("Impossible d'initialiser SDL: %s\n", SDL_GetError());
    return 1;
  }
  
  screen=SDL_SetVideoMode(900,722,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
 SDL_WM_SetCaption("city of the future",NULL);
 // initialisation_backgroundimage(&backimg);
  // initialiser_imageBACK(&back);

  initialisation_start_button(&startimg);
  initialisation_coming_soon(&comingsoon);
  initialisation_credits(&credits);
  initialisation_settings_button(&settingsimg);
    initialisation_credits_button(&creditimg);
  initialisation_settings_background(&settings_background);
  initialisation_quit_button(&quitimg);
       initialiser_animation(&anim);
  initialisation_background_music(&backmusic);
  initialisation_du_text(&textt);
  initialisation_updated_start_button(&starteffet);
    initialisation_updated_credits_button(&crediteffet);
  initialisation_updated_settings_button(&settingseffet);
  initialisation_updated_quit_button(&quiteffet);
  
 //animation


  //initialisation des images de %
  initialisation_0_img(&img0);
  initialisation_10_img(&img10);
  initialisation_20_img(&img20);
  initialisation_30_img(&img30);
  initialisation_40_img(&img40);
  initialisation_50_img(&img50);
  initialisation_60_img(&img60);
  initialisation_70_img(&img70);
  initialisation_80_img(&img80);
  initialisation_90_img(&img90);
  initialisation_100_img(&img100);
  
  //initialisation on and off fullscreen
  initialisation_onFS(&onFS);
  initialisation_offFS(&offFS);
  
  //initialisation on off mute
  initialisation_mute_off(&muteoff);
  initialisation_mute_on(&muteon);
 initialisation_back_button(&backimg);
  

  
  SDL_Flip(screen);


  int i=0;
  while(boucle)
  {
        
  if (currentScreen == 1 ) 
  {
  //affichage_backgroundimage(screen,backimg);

  //afficher_imageBACK(screen,back); 
  
   SDL_BlitSurface(anim.anim[i],NULL,screen,&anim.pos);
   i++;
         SDL_Delay(100);
   if (i==22)
   i=0;
  affichage_start_button(screen,startimg); 
  affichage_settings_button(screen,settingsimg);
  affichage_credits_button(screen,creditimg); 
  affichage_quit_button(screen,quitimg);
  affichage_du_text(screen,textt);


  }
    




  //start	
  if(startstate==1)
  {
  affichage_updated_start_button(screen,starteffet);
  }
  else if(startstate==0)
  {
  affichage_start_button(screen,startimg);
  }
  //settings
  if(settingsstate==1)
  {
  affichage_updated_settings_button(screen,settingseffet);
  }
  else if(settingsstate==0)
  {
  affichage_settings_button(screen,settingsimg);
  }
  //credits
   if(creditstate==1)
  {
  affichage_updated_credits_button(screen,crediteffet);
  }
  else if(creditstate==0)
  {
  affichage_credits_button(screen,creditimg);
  }
  //quit
  if(quitstate==1)
  {
  affichage_updated_quit_button(screen,quiteffet);
  }
  else if(quitstate==0)
  {
  affichage_quit_button(screen,quitimg);
  }
  if (currentScreen == 2)
   	{
   	 affichage_50_img(screen,img50);
         affichage_settings_background(screen,settings_background); 
         affichage_back_button(screen,backimg);
    	 affichage_mute_off(screen,muteoff);
	 affichage_offFS(screen,offFS);
	//affichage_offFS(screen,offFS);
  	   if(FSstate==0)
  	    {affichage_offFS(screen,offFS);}
  	    else if (FSstate==1)
  	     {affichage_onFS(screen,onFS);}
  	//affichage on off mute
  	   if(mutestate==0)
  	    {affichage_mute_off(screen,muteoff);
  	    }
  	    if(mutestate==1)
  	     {	 affichage_mute_on(screen,muteon);
  	      }
        }         
  if (currentScreen == 3)
        {
         affichage_coming_soon(screen,comingsoon); 
                  affichage_back_button(screen,backimg);
        }    
         if (currentScreen == 4)
        {
         affichage_credits(screen,credits); 
                  affichage_back_button(screen,backimg);
        }    

  
  //affichage et changement de volume
  
  
  if (currentScreen == 2 && volumestate==0)
  	{
  	affichage_0_img(screen,img0);
  	volume_mod(&backmusic,&buttonsound,volumestate);
  	}

  if (currentScreen == 2 && volumestate==1)
  	{
  	affichage_10_img(screen,img10);
  	volume_mod(&backmusic,&buttonsound,volumestate);
  	}
  	
  if (currentScreen == 2 && volumestate==2)
  	{
  	affichage_20_img(screen,img20);
  	volume_mod(&backmusic,&buttonsound,volumestate);
  	}
  	  	  
  if (currentScreen == 2 && volumestate==3)
  	{
  	affichage_30_img(screen,img30);
  	volume_mod(&backmusic,&buttonsound,volumestate);
  	}  
  
  if (currentScreen == 2 && volumestate==4)
  	{
  	affichage_40_img(screen,img40);
  	volume_mod(&backmusic,&buttonsound,volumestate);
  	}  
  
  if (currentScreen == 2 && volumestate==5)
  	{
  	affichage_50_img(screen,img50);
  	volume_mod(&backmusic,&buttonsound,volumestate);
  	}  
  
  if (currentScreen == 2 && volumestate==6)
  	{
  	affichage_60_img(screen,img60);
  	volume_mod(&backmusic,&buttonsound,volumestate);
  	}  
  
  if (currentScreen == 2 && volumestate==7)
  	{
  	affichage_70_img(screen,img70);
  	volume_mod(&backmusic,&buttonsound,volumestate);
  	}  
  
  if (currentScreen == 2 && volumestate==8)
  	{
  	affichage_80_img(screen,img80);
  	volume_mod(&backmusic,&buttonsound,volumestate);
  	}  
  
  if (currentScreen == 2 && volumestate==9)
  	{
  	affichage_90_img(screen,img90);
  	volume_mod(&backmusic,&buttonsound,volumestate);
  	}  
  
  if (currentScreen == 2 && volumestate==10)
  	{
  	affichage_100_img(screen,img100);
  	volume_mod(&backmusic,&buttonsound,volumestate);
  	}  
  
  
  


    SDL_Flip(screen);

  while(SDL_PollEvent(&event)){
  switch(event.type)
  {
  	case SDL_QUIT:
  	boucle=0;
  	break;
  	//QUIT BUTTON
  	case SDL_MOUSEBUTTONUP:
          if (currentScreen == 1  && event.button.button==SDL_BUTTON_LEFT &&(event.motion.y<=624 && event.motion.y>=558 
  	&& event.motion.x<=500 && event.motion.x>=340))
            {
            
            boucle=0;
            }
           //SETTINGS BUTTON                                                 
         if (currentScreen == 1  && event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=463 && event.motion.y>=400
          && event.motion.x<=501 && event.button.x>=341)) {
                    currentScreen = 2;
                }
                
         //BACK BUTTON OF SETTINGS PAGE      "777,650,889,688"
        if (currentScreen == 2  && event.button.button==SDL_BUTTON_LEFT &&(event.button.y<=688 && event.button.y>=650
          						                    && event.button.x<=889 && event.button.x>=777)) {
                    currentScreen = 1;
                    
                }
                
                //BACK BUTTON OF CREDITS PAGE  
        if (currentScreen == 4  && event.button.button==SDL_BUTTON_LEFT &&(event.button.y<=688 && event.button.y>=650
          						                    && event.button.x<=889 && event.button.x>=777)) {
                    currentScreen = 1;
                }
         //START BUTTON      
        if (currentScreen == 1  && event.button.button==SDL_BUTTON_LEFT &&(event.motion.y<=383 && event.motion.y>=321 && event.motion.x<=499 && event.motion.x>=342)) {
                    currentScreen = 3;
                }
                        
         //Credits BUTTON      
        if (currentScreen == 1  && event.button.button==SDL_BUTTON_LEFT &&(event.motion.y<=543 && event.motion.y>=480 
  	    && event.motion.x<=500 && event.button.x>=342)) {
                    currentScreen = 4;
                }
                
          //BACK BUTTON OF START PAGE     
        if (currentScreen == 3  && event.button.button==SDL_BUTTON_LEFT &&(event.button.y<=688 && event.button.y>=650
          						                    && event.button.x<=889 && event.button.x>=777)) {
                    currentScreen = 1;
                    
         
                }        
         
         //en cas yenzel + 
     
        if (currentScreen == 2  && event.button.button==SDL_BUTTON_LEFT &&(event.button.y<=410 && event.button.y>=371
          						                    && event.button.x<=616 && event.button.x>=577)) {
                    volumestate ++;  
                   
                    }  
         //en cas yenzel - 
         
         if (currentScreen == 2  && event.button.button==SDL_BUTTON_LEFT &&(event.button.y<=410 && event.button.y>=373
          						                    && event.button.x<=359 && event.button.x>=321)) {
                    volumestate --;  
                   
                    }    
  	
  	  	//full screen on "340,243,466,275
         if (currentScreen == 2  && event.button.button==SDL_BUTTON_LEFT &&(event.button.y<=275 && event.button.y>=243
          						                    && event.button.x<=466 && event.button.x>=340)) {
                    FSstate=1;

                    screen=SDL_SetVideoMode(1920, 1200, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
                    
                    
                     
                  
                    }      	
  	//full screen off  
         if (currentScreen == 2  && event.button.button==SDL_BUTTON_LEFT &&(event.button.y<=275 && event.button.y>=243
          						                    && event.button.x<=594 && event.button.x>=468)) {
                    FSstate=0;
                    screen=SDL_SetVideoMode(900,722,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
                    
                    
                    
                    }  	
        // mute on then off 467,474,593,506
  	if (currentScreen == 2  && event.button.button==SDL_BUTTON_LEFT &&(event.button.y<=506 && event.button.y>=474
          						                    && event.button.x<=593 && event.button.x>=467)) {
              
                   
                      mutestate=0;
                       volumestate=5;
                    		 
                 Mix_VolumeMusic(volumestate);
                    }
  		 if (currentScreen == 2  && event.button.button==SDL_BUTTON_LEFT &&(event.button.y<=505 && event.button.y>=473
          						                    && event.button.x<=466 && event.button.x>=340)) {
              
                   		 mutestate=1;
                   	volumestate=0;
                  
                    Mix_VolumeMusic(volumestate);
                   		 }
  	
  	break;
  	
  	case SDL_MOUSEMOTION:
  	if(event.motion.y<=383 && event.motion.y>=321 && event.motion.x<=499 && event.motion.x>=342)
  	 {startstate=1;}
  	 else
  	  {startstate=0;}                                        
         if(event.motion.y<=463 && event.motion.y>=400
          && event.motion.x<=501 && event.button.x>=341)					                     
          {settingsstate=1;} 						                 
  	   else
  	   {settingsstate=0;}
  	    if(event.motion.y<=543 && event.motion.y>=480 
  	    && event.motion.x<=500 && event.button.x>=342)					                     
          {creditstate=1;} 						                 
  	   else
  	   {creditstate=0;}
  	if(event.motion.y<=624 && event.motion.y>=558 
  	&& event.motion.x<=500 && event.motion.x>=340)
  	{quitstate=1;}
  	  else
  	  {quitstate=0;}
  	break;
  	
  	case SDL_MOUSEBUTTONDOWN:
  	if (event.button.button == SDL_BUTTON_LEFT)
  	{ 
  	initialisation_button_sound(&buttonsound);
  	}			
       case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    
                    boucle=0;
                }
        
            		 
 switch (event.key.keysym.sym)
                {
	case SDLK_DOWN: 
                	
                	if(currentScreen==2)
                	{
                	volumestate --;
                	}									
        		break;

        case SDLK_UP:
 
                	if(currentScreen==2)
                	{
                	volumestate ++;
                	
                	}                                	             	
                	break;
          case SDLK_b:
                	if(currentScreen==2)
                	{currentScreen=1;}
                	else if(currentScreen==3)
                	{currentScreen=1;}
                	else if(currentScreen==4)
                	{currentScreen=1;}
                	break;

            
        case SDLK_s:
	if(currentScreen==1)
	{currentScreen=3;}
                	break;
	case SDLK_o:
	if(currentScreen==1)
                	{currentScreen=2;}
                	break;
	case SDLK_q:
	if(currentScreen==1)
                	{boucle=0;}
                	break;
        
        case SDLK_c:
	if(currentScreen==1)
                	{currentScreen=4;}
                	break;
       
}
          break;	    
  }

  }
  
  
}


  	
  

  //liberer_image(backimg);
  //liberer_imageBACK(back);
  //liberer_animation(anim);
  
  liberer_image(startimg);
  liberer_image(settingsimg);
  liberer_image(quitimg);
  
  //liberer_image(comingsoon);
  //liberer_image(settings_background);
  
  liberer_background_music(&backmusic);
  liberer_button_sound(&buttonsound);
  liberer_image(settings_background);
  liberer_du_texte(textt);
  
  SDL_Quit();
  
  
  

return 0;
}




















