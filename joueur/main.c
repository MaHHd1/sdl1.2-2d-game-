#include "header.h"

void main()
{
    SDL_Surface *screen;
    Uint32 dt,t_prev;
    SDL_Rect M1,M2;//a ne pas depacer
    SDL_Event event;
    int ST;
  
    
    
    Personne p;
    float n;
    //int vectX=10;
    //int vectY=10;
    int direction,num;
    bool gameRunning = true;

    if(SDL_Init(SDL_INIT_EVERYTHING)==-1){
        printf("Coundn't initialise\n");
    }
         else
    {
        screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
        initPerso(&p);

    while(gameRunning)
    {    
        t_prev=SDL_GetTicks();
        afficherPerso(&p,screen);
	
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    gameRunning = false;
                    break;
                case SDL_KEYDOWN:
                {
                    /*if(event.key.keysym.sym == SDLK_DOWN)
                    {
                    
                    }*/
                    if(event.key.keysym.sym == SDLK_UP)
                    {
                        p.up=1;
			if(event.key.keysym.sym == SDLK_RIGHT)
				ST=0;
			else
				ST=1;
                        
                    
                    }
                    else
                    {
                        p.up=0;
                    }
                    if(event.key.keysym.sym == SDLK_RIGHT)
                    {
                        p.direction=0;
                    
                    }
                    if(event.key.keysym.sym == SDLK_LEFT)
                    {
                        p.direction=1;
                    
                    }
                    if(event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        //acceleration
                        p.acceleration+=0.005;
                
                    }
                    else
                    {
                        //deceleration
                        while(p.acceleration > n)
                        	p.acceleration-=0.01;
                    
                    }

                }//CASE
		
                

            }//SWITCH
            
        }//WHILE EVENT

                
                
               saut(&p,dt,p.posScreen.x,ST);//Machkok feha 
                

                if(p.num==6)
                    p.num=0;
                else
                    p.num++;
        if(p.direction == 0 || p.direction == 1){
                movePerso(&p,dt);
                animerPerso(&p);
            }
    
        


                dt=SDL_GetTicks()-t_prev;
		SDL_Flip(screen);
    }//WHILE GAME RUNNING








}//ELSE
liberer(&p);
}//MAIN
