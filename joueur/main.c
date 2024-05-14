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

        initPerso(&p);
        initPerso2(&p2);

        while (gameRunning)
        {
            t_prev = SDL_GetTicks();
            afficherPerso(&p, screen);
            afficherPerso(&p2, screen);

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
                    break; 

                case SDL_KEYUP:
                    p.moving = 0;
                    p2.moving = 0;
                    break; 
                }
            }

            saut(&p, dt, p.posScreen.x);
            saut(&p2, dt, p2.posScreen.x);

            animerPerso(&p);
            animerPerso(&p2);

            movePerso(&p, dt);
            movePerso(&p2, dt);

            dt = SDL_GetTicks() - t_prev;
            SDL_Flip(screen);
	    SDL_BlitSurface(url, NULL, screen, &pos);
        }

        liberer(&p);
        liberer(&p2); 
    }

    SDL_Quit(); 
    return 0;
}
