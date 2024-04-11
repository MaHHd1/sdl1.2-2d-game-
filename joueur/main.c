#include "header.h"

void main()
{
	SDL_Surface *screen;
	Unit32 dt,t_prev;
	SDL_Rect M1,M2;//a ne pas depacer
	SDL_Event event;
	Personne p;
	SDL_Surface *mat[3][5];
	int direction,num;
	if(SDL_Init(SDL_INIT_EVRYTHING)==-1){
		printf("Coundn't initialise\n");
	}
	else
	{
		screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
		initPerso(Personne *p);

	while(gameRunning)
	{	
		t_prev=SDL_GetTicks();
		afficherPerso(p,screen);
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
						saut(&p,dt,posinit)
					
					}
					else
					{
						p.up=0;
					}
					if(event.key.keysym.sym == SDLK_RIGHT)
					{
						p.direction=1;
					
					}
					if(event.key.keysym.sym == SDLK_LEFT)
					{
						p.direction=0;
					
					}
					if((event.key.keysym.sym == SDLK_ESCAPE)
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

				}
				movePerso(&p,dt);
				if(p->num==6)
					p.num=0;
				else
					p.num++;
				animerPerso(Personne p);

			}
			
		}
		
		


		dt=SDL_GetTicks()-t_prev
	}








}
