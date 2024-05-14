#include"menu.h"
void main(){
	int boucle=1,bck=0,drag1=0,drag2=0,drag3=0;
	int wind,ctrl;
	SDL_Surface *screen;
	SDL_Event event;
	Mix_Chunk *drg;
	Mix_Chunk *clk;
	SDL_Rect posM;
	image bg,b1,nb1,b2,nb2,b3,nb3,m,mp1,mp2,mm1,mm2,sfx,sfxp1,sfxp2,sfxm1,sfxm2,frame,wd1,wd2,fs1,fs2,key1,key2,ctrl1,ctrl2,bk1,bk2,bp;
	Mix_Music *music;
	texte settings,volume,screenmode,controls;
	int entre_p=0,entre_s=0,entre_e=0;
	int running = 1;
    	int current_image = 0;
    	int num_images = 8;
    	Image images[8];
	int B;
	TTF_Init();
	posM.x=(1080/2)+250;
	posM.y=-100;
	
	
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)==-1){
		printf("Coundn't initialise\n");
	}
	else{
		screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
		load_images(images);
		initialiser_text(&settings,"font/Gamejot.ttf",75,255,255,255,835,71);
		initialiser_text(&volume,"font/Corbel Bold.ttf",50,83,67,142,870,201);
		initialiser_text(&screenmode,"font/Corbel Bold.ttf",50,83,67,142,815,486);
		initialiser_text(&controls,"font/Corbel Bold.ttf",50,83,67,142,860,653);
		intro(music);
		initilize_img(&bg,"gfx/background/bg.png",0,0);
		//main menu:
		initilize_img(&b1,"image/play.png",850,350);
		initilize_img(&b2,"image/settings.png",850,500);
		initilize_img(&b3,"image/quit.png",850,650);
		initilize_img(&nb1,"image/play1.png",850,350);
		initilize_img(&nb2,"image/settings1.png",850,500);
		initilize_img(&nb3,"image/quit1.png",850,650);
		//settings menu:
		initilize_img(&m,"image/line.png",789,271);
		initilize_img(&mp1,"image/cercul.png",1055,271);
		initilize_img(&mp2,"gfx/settings/volume/btn_music/pls/bouton_plus_down.png",1153,271);
		initilize_img(&mm1,"gfx/settings/volume/btn_music/mns/bouton_moins.png",710,272);
		initilize_img(&mm2,"gfx/settings/volume/btn_music/mns/bouton_moins_down.png",710,272);
		initilize_img(&sfx,"gfx/settings/volume/sfx_level/sfx00.png",788,378);
		initilize_img(&sfxp1,"gfx/settings/volume/btn_sfx/pls/bouton_plus.png",1153,379);
		initilize_img(&sfxp2,"gfx/settings/volume/btn_sfx/pls/bouton_plus_down.png",1153,379);
		initilize_img(&sfxm1,"gfx/settings/volume/btn_sfx/mns/bouton_moins.png",709,379);
		initilize_img(&sfxm2,"gfx/settings/volume/btn_sfx/mns/bouton_moins_down.png",709,379);
		initilize_img(&frame,"gfx/settings/frame/frame.png",628,141);
		initilize_img(&wd1,"image/dzoom0.png",707,556);
		initilize_img(&fs1,"image/zoom0.png",1150,556);
		initilize_img(&key1,"gfx/settings/controls/keyboard/keyboard.png",989,723);
		initilize_img(&ctrl1,"gfx/settings/controls/controller/controller.png",707,723);
		initilize_img(&wd2,"image/dzoom.png",707,556);
		initilize_img(&fs2,"image/zoom.png",1150,556);
		initilize_img(&key2,"gfx/settings/controls/keyboard/keyboard_active.png",989,723);
		initilize_img(&ctrl2,"gfx/settings/controls/controller/controller_active.png",707,723);
		initilize_img(&bk1,"image/back0.png",923,830);
		initilize_img(&bk2,"image/back.png",923,830);
		//play Menu
		initilize_img(&bp,"image/bp.png",0,0);
		while(boucle){
			afficher_image(screen,bg);

        // Gestion des événements
        

        // Affichage de l'image courante
        SDL_BlitSurface(images[current_image].surface, NULL, screen, &posM);
        //SDL_Flip(screen);

        // Passage à l'image suivante
        current_image++;
        if (current_image >= num_images) {
            current_image = 0;
        }

        // Attente de 200 ms
        SDL_Delay(200);
		
 			if((event.motion.x<=1055 && event.motion.x>=820 && event.motion.y<=410 && event.motion.y>=350 && event.button.button==SDL_BUTTON_LEFT) || (event.key.keysym.sym==SDLK_SPACE && entre_p==1)){
	B=0;
	while(B==0){
	afficher_image(screen,bp);
	
	SDL_PollEvent(&event);
	if(event.type==SDL_KEYDOWN){
		if(event.key.keysym.sym==SDLK_ESCAPE){
				B=1;
				SDL_Delay(1000);
				//bck=1;

				
						}
					}
					SDL_Flip(screen);

}
}
			if((event.motion.x<=1040 && event.motion.x>=860 && event.motion.y<=565 && event.motion.y>=500 && event.button.button==SDL_BUTTON_LEFT) ||(event.key.keysym.sym==SDLK_SPACE && entre_s==1)){
				B=1;
				//frame:
				afficher_image(screen,frame);
				//settings(texte):
				afficher_text(screen,settings,"Settings");
				//volume(texte):
				afficher_text(screen,volume,"Volume");
				//screen mode(texte):
				afficher_text(screen,screenmode,"Screen Mode");
				//controls(texte)
				afficher_text(screen,controls,"Controls");
				bck=0;
				wind=0;
				ctrl=0;
			
				while(bck==0){
					//music:
					if(event.motion.x<=1055 && event.motion.x>=820 && event.motion.y<=410 && event.motion.y>=350){
						afficher_image(screen,m);
					}
					else{
						afficher_image(screen,m);
					}
					//+music:
					if(event.motion.x<=1205 && event.motion.x>=1257 && event.motion.y<=355 && event.motion.y>=271){
						afficher_image(screen,mp2);
					}
					else{
						afficher_image(screen,mp1);
					}
					//_music:
					if(event.motion.x<=765 && event.motion.x>=710 && event.motion.y<=356 && event.motion.y>=272){
						afficher_image(screen,mm2);
					}
					else{
						afficher_image(screen,mm1);
					}
					//sfx:
					if(event.motion.x<=1055 && event.motion.x>=820 && event.motion.y<=410 && event.motion.y>=350){
						
						afficher_image(screen,sfx);
					}
					else{
						afficher_image(screen,sfx);
					}
					//+sfx:
					if(event.motion.x<=1205 && event.motion.x>=1153 && event.motion.y<=434 && event.motion.y>=379){
						afficher_image(screen,sfxp2);
					}
					else{
						afficher_image(screen,sfxp1);
					}
					//_sfx:
					if(event.motion.x<=761 && event.motion.x>=709 && event.motion.y<=434 && event.motion.y>=379){
						afficher_image(screen,sfxm2);
					}
					else{
						afficher_image(screen,sfxm1);
					}
					//windowed:
					if(event.motion.x<=931 && event.motion.x>=707 && event.motion.y<=628 && event.motion.y>=556 && event.button.button==SDL_BUTTON_LEFT){
						wind=1;
					}
					//full screen:
					if(event.motion.x<=1213 && event.motion.x>=989 && event.motion.y<=628 && event.motion.y>=556 && event.button.button==SDL_BUTTON_LEFT){
						wind=0;
					}
					//keyboard:
					if(event.motion.x<=1213 && event.motion.x>=989 && event.motion.y<=795 && event.motion.y>=723 && event.button.button==SDL_BUTTON_LEFT){
						ctrl=0;
					}
					//controller:
					if(event.motion.x<=931 && event.motion.x>=707 && event.motion.y<=795 && event.motion.y>=723 && event.button.button==SDL_BUTTON_LEFT){
						ctrl=1;
					}
					if(wind==1){
						afficher_image(screen,fs1);
						afficher_image(screen,wd2);
					}
					else{
						afficher_image(screen,fs2);
						afficher_image(screen,wd1);
					}
					if((event.motion.x<=1213 && event.motion.x>=989 && event.motion.y<=628 && event.motion.y>=556 && event.button.button==SDL_BUTTON_LEFT) || (event.motion.x<=1213 && event.motion.x>=989 && event.motion.y<=628 && event.motion.y>=556 &&  event.key.keysym.sym==SDLK_SPACE)){
						screen=SDL_SetVideoMode(1920, 1017, 32, SDL_FULLSCREEN);
						//SDL_Flip(screen);
						
					}
					SDL_Flip(screen);
					if((event.motion.x<=931 && event.motion.x>=707 && event.motion.y<=628 && event.motion.y>=556 && event.button.button==SDL_BUTTON_LEFT) || (event.motion.x<=931 && event.motion.x>=707 && event.motion.y<=628 && event.motion.y>=556 &&  event.key.keysym.sym==SDLK_SPACE)){
						screen=SDL_SetVideoMode(1920, 1017, 32, 0);
						
                                        }
					SDL_Flip(screen);
					if(ctrl==1){
						afficher_image(screen,ctrl2);
						afficher_image(screen,key1);
					}
					else{
						afficher_image(screen,ctrl1);
						afficher_image(screen,key2);
					}
					SDL_Flip(screen);
					//back:
					if(event.motion.x<=997 && event.motion.x>=923 && event.motion.y<=904 && event.motion.y>=830 && event.button.button==SDL_BUTTON_LEFT){
						afficher_image(screen,bk2);
						SDL_Delay(100);
						bck=1;
					}
					else{
						afficher_image(screen,bk1);
					}
					SDL_PollEvent(&event);
					if(event.type==SDL_KEYDOWN){
						if(event.key.keysym.sym==SDLK_ESCAPE){
							bck=1;
						}
					}
					SDL_Flip(screen);
				}
			}
			else{

	
				if(event.motion.x<=1055 && event.motion.x>=820 && event.motion.y<=410 && event.motion.y>=350 || entre_p==1){
					afficher_image(screen,nb1);
					entre_s=0;
					entre_e=0;
					/*if(drag1==0){
						musiquebref_drag(drg);
						//liberer_musiquebref(drg);
					}
					drag1=1;*/
				}
				else{
					//drag1=0;
					afficher_image(screen,b1);
				}
				if(event.motion.x<=1040 && event.motion.x>=860 && event.motion.y<=565 && event.motion.y>=500 || entre_s==1){
					afficher_image(screen,nb2);
					entre_p=0;
					entre_e=0;
					/*if(drag2==0){
						musiquebref_drag(drg);
						//liberer_musiquebref(drg);
					}
					drag2=1;*/
				}
				else{
					//drag2=0;
					afficher_image(screen,b2);
				}
				if(event.motion.x<=1040 && event.motion.x>=860 && event.motion.y<=710 && event.motion.y>=650 || entre_e==1){
					afficher_image(screen,nb3);
					entre_p=0;
					entre_s=0;
					/*if(drag3==0){
						musiquebref_drag(drg);
						//liberer_musiquebref(drg);
					}*/
					//drag3=1;
					if((event.button.button==SDL_BUTTON_LEFT && event.motion.x<=1040 && event.motion.x>=860 && event.motion.y<=710 && event.motion.y>=650 ) || (event.key.keysym.sym==SDLK_SPACE && entre_e==1)){
						SDL_Delay(1000); // wait before launching next command
						boucle=0;
					}
				}
				else{
					//drag3=0;
					afficher_image(screen,b3);
				}
			}
			SDL_Flip(screen); //refresh screen
			while(SDL_PollEvent(&event)){
				switch(event.type){
					case SDL_MOUSEBUTTONDOWN:{
						if(event.motion.x<=1055 && event.motion.x>=820 && event.motion.y<=410 && event.motion.y>=350||event.motion.x<=1205 && event.motion.x>=735 && event.motion.y<=565 && event.motion.y>=500||event.motion.x<=1063 && event.motion.x>=870 && event.motion.y<=710 && event.motion.y>=650){
							if((event.button.button== SDL_BUTTON_LEFT)){
								musiquebref_click(clk);
								liberer_musiquebref(clk);
							}
						}
						break;
					}
		case SDL_QUIT:{
			boucle=0;
			break;
			}
	case SDL_KEYDOWN:{
                  switch(event.key.keysym.sym){ 
              case SDLK_UP:{
                if(entre_p==1 && entre_s==0 && entre_e==0) entre_p=0;
                else{
                    if(entre_p==0 && entre_s==1 && entre_e==0){
                    entre_p=1;
                    entre_s=0;
                    }
                                        
                else{
                    if(entre_p==0 && entre_s==0 && entre_e==1){
                    entre_s=1;
                    entre_e=0;
                    }
                    }
	}

                break;
                    }
             case SDLK_DOWN:{
                   if(entre_p==0 && entre_s==0 && entre_e==0) entre_p=1;
                    else{
                               if(entre_p==1 && entre_s==0 && entre_e==0){
                        entre_p=0;
                    entre_s=1;
                     }
                    
                        else{
                    if(entre_p==0 && entre_s==1 && entre_e==0){
                    entre_e=1;                                                                entre_s=0;
                    }
                    
                else{
                    if(entre_p==0 && entre_s==0 && entre_e==1) entre_e=0;
                    }
}
}
                break;
				}
			}
		}
	}
}
}
		TTF_Quit();
		//free_text(settings);
		//free_text(volume);
		//free_text(screenmode);
		//free_text(controls);
		free_image(nb1);
		free_image(nb2);
		free_image(nb3);
		free_image(bg);
		free_image(b1);
		free_image(b2);
		free_image(b3);
		free_image(m);
		free_image(mp1);
		free_image(mp2);
		free_image(mm1);
		free_image(mm2);
		free_image(sfx);
		free_image(sfxp1);
		free_image(sfxp2);
		free_image(sfxm1);
		free_image(sfxm2);
		free_image(frame);
		free_image(wd1);
		free_image(fs1);
		free_image(key1);
		free_image(ctrl1);
		free_image(wd2);
		free_image(fs2);
		free_image(key2);
		free_image(ctrl2);
		free_image(bk1);
		free_image(bk2);
		free_images(images);
		//liberer_music(music);
	}
}




