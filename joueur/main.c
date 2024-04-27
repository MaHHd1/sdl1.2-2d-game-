#include "header.h"

int main()
{
    SDL_Surface *screen;
    Uint32 dt, t_prev;
    SDL_Surface *url;
    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;
    SDL_Event event;
    int ST = 0; // Initialize ST variable
    Personne p;
    bool gameRunning = true;

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        printf("Couldn't initialize SDL\n");
        return 1; // Exit the program with an error code
    }
    else
    {
        screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
        url = IMG_Load("wallpaperflare.com_wallpaper(1).jpg");
	
        //SDL_BlitSurface(url, NULL, screen, &pos);
        initPerso(&p);

        while (gameRunning)
        {
            t_prev = SDL_GetTicks();
            afficherPerso(&p, screen);
	    
	    

            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_QUIT:
                    gameRunning = false;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_UP)
                    {
                        p.up = 1;
                        if (event.key.keysym.sym == SDLK_RIGHT)
                            ST = 0;
                        else
                            ST = 1;
                    }
                    else
                    {
                        p.up = 0;
                    }
                    if (event.key.keysym.sym == SDLK_RIGHT)
                    {
                        p.direction = 0;
			p.moving= 1;
                    }
                    if (event.key.keysym.sym == SDLK_LEFT)
                    {
                        p.direction = 1;
			p.moving = 1;
                    }

                    if (event.key.keysym.sym == SDLK_a)
                    {
                        // acceleration
                        p.acceleration += 100;
                    }
                    else
                    {
                        // deceleration
                        if(p.acceleration > 10 ){
                            p.acceleration -= 2;}
                    }
                    break; // Add break statement here

                case SDL_KEYUP:
                    p.moving = 0;
                    break; // Add break statement here
                }
            }

            saut(&p, dt, p.posScreen.x, ST);

          
            
                
                animerPerso(&p);
            
		movePerso(&p, dt);

            dt = SDL_GetTicks() - t_prev;
            SDL_Flip(screen);
	    SDL_BlitSurface(url, NULL, screen, &pos);
        }

        liberer(&p); // Move outside the else block
    }

    SDL_Quit(); // Cleanup SDL before exiting
    return 0;
}

