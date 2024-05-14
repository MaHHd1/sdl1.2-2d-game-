#include "header.h"

int main()
{
    SDL_Surface *screen;
    Uint32 dt, t_prev;
    SDL_Surface *url;
    static int choix;
    image pl1,pl2,M;
    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;
    SDL_Event event;
    static int Menu=0;
    int ST = 0;
    int ST2 = 0; 
    Personne p;
    Personne p2;
    bool gameRunning = true;

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        printf("Couldn't initialize SDL\n");
        return 1; 
    }
    else
    {
        screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
        url = IMG_Load("11.jpg");

        //SDL_BlitSurface(url, NULL, screen, &pos);
	initIMG(&pl1,850,350,"p1.jpg");
	initIMG(&pl2,850,650,"p1.jpg");
	initIMG(&M,0,0,"b.jpg");
        initPerso(&p);
        initPerso2(&p2);

        while (gameRunning)
        {
            t_prev = SDL_GetTicks();
            //afficherPerso(&p, screen);
            //afficherPerso(&p2, screen);

            while (SDL_PollEvent(&event))
            {
		/*if (event.key.keysym.sym == SDLK_p)
		    {
			Menu=0;
		    }
		    if (event.key.keysym.sym == SDLK_p)
		    {
			Menu=1;
		    }
		if(Menu == 0 && (event.motion.x<=1055 && event.motion.x>=820 && event.motion.y<=410 && event.motion.y>=350 && event.button.button==SDL_BUTTON_LEFT))
		    {
			choix = 0;
			Menu = 1;

		    }
		    if(Menu == 0 && (event.motion.x<=1040 && event.motion.x>=860 && event.motion.y<=710 && event.motion.y>=650))
		    {
			choix = 1;
			Menu= 1;
		    }*/
                switch (event.type)
                {
                case SDL_QUIT:
                    gameRunning = false;
                    break;
                case SDL_KEYDOWN:
		    /*if (event.key.keysym.sym == SDLK_p)
		    {
			Menu=0;
		    }
		    if (event.key.keysym.sym == SDLK_p)
		    {
			Menu=1;
		    }*/
                    if (event.key.keysym.sym == SDLK_UP)
                    {
                        p.up = 1;
                        if (event.key.keysym.sym == SDLK_RIGHT)
                            p.moving = 0;
                        if (event.key.keysym.sym == SDLK_LEFT)
                            p.moving = 1;
                    }
                    else
                    {
                        p.up = 0;
                    }
                    if (event.key.keysym.sym == SDLK_z)
                    {
                        p2.up = 1;
                        if (event.key.keysym.sym == SDLK_d)
                            p2.direction = 0;
                        if (event.key.keysym.sym == SDLK_q)
                            p2.direction = 1;
                    }
                    else
                    {
                        p2.up = 0;
                    }
                    if (event.key.keysym.sym == SDLK_RIGHT)
                    {
                        p.direction = 0;
                        p.moving = 1;
                    }
                    if (event.key.keysym.sym == SDLK_d)
                    {
                        p2.direction = 0;
                        p2.moving = 1;
                    }
                    if (event.key.keysym.sym == SDLK_LEFT)
                    {
                        p.direction = 1;
                        p.moving = 1;
                    }
                    if (event.key.keysym.sym == SDLK_q)
                    {
                        p2.direction = 1;
                        p2.moving = 1;
                    }

                    if (event.key.keysym.sym == SDLK_b)
                    {
                        // acceleration
                        p.acceleration += 10;
                    }
                    else
                    {
                        // deceleration
                        if (p.acceleration > 10)
                        {
                            p.acceleration -= 2;
                        }
                    }
                    if (event.key.keysym.sym == SDLK_b)
                    {
                        // acceleration
                        p2.acceleration += 10;
                    }
                    else
                    {
                        // deceleration
                        if (p2.acceleration > 10)
                        {
                            p2.acceleration -= 2;
                        }
                    }
		    if(Menu == 0 && event.key.keysym.sym == SDLK_1 )
		    {
			choix = 0;
			Menu = 1;

		    }
		    if(Menu == 0 && event.key.keysym.sym == SDLK_2)
		    {
			choix = 1;
			Menu= 1;
		    }
                    break; 

                case SDL_KEYUP:
                    p.moving = 0;
                    p2.moving = 0;
                    break; 
                }
            }
	    
	    if(Menu == 0)
	    {
		afficher_image(screen,M);
		afficher_image(screen,pl1);
		afficher_image(screen,pl2);
	

	    }
	    else
	    {
		SDL_BlitSurface(url, NULL, screen, &pos);
	    	if( choix == 0)
		{
			afficherPerso(&p, screen);
           		saut(&p, dt, p.posScreen.x);
			movePerso(&p, dt);
			animerPerso(&p);
			
			

		}
		if( choix == 1)
		{
			afficherPerso(&p, screen);
            		afficherPerso(&p2, screen);
			saut(&p, dt, p.posScreen.x);
            		saut(&p2, dt, p2.posScreen.x);
			movePerso(&p, dt);
                        movePerso(&p2, dt);
			animerPerso(&p);
            		animerPerso(&p2);
			
			
		}
		
	    }

            /*saut(&p, dt, p.posScreen.x);
            saut(&p2, dt, p2.posScreen.x);

            animerPerso(&p);
            animerPerso(&p2);

            movePerso(&p, dt);
            movePerso(&p2, dt);*/

            dt = SDL_GetTicks() - t_prev;
            SDL_Flip(screen);
	    //SDL_Delay(100);
	    //SDL_BlitSurface(url, NULL, screen, &pos);
        }

        liberer(&p);
        liberer(&p2); 
	liberer2(&pl1);
	liberer2(&pl2);
	liberer2(&M);
	SDL_FreeSurface(url);

    }

    SDL_Quit(); 
    return 0;
}
