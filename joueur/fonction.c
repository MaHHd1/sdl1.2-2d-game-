#include "header.h"

void initPerso(Personne *p)
{
    p->direction = 0;
    p->moving = 0;
    p->num = 0;
    p->up = 0;
    p->vitesse = 5;
    p->acceleration = 10;
    p->score = 100;
    p->posScreen.x = 30;
    p->posScreen.y = 400;
    p->posScreen.w = 1; // largeur image
    p->posScreen.h = 1; // Hauteur image

    p->image[0][0].per = IMG_Load("dd1.png");
    p->image[0][1].per = IMG_Load("dd2.png");
    p->image[0][2].per = IMG_Load("dd3.png");
    p->image[1][0].per = IMG_Load("gd1.png");
    p->image[1][1].per = IMG_Load("gd2.png");
    p->image[1][2].per = IMG_Load("gd3.png");
    p->image[2][0].per = IMG_Load("dd1.png");
    p->image[2][1].per = IMG_Load("gd3.png");
   
}

void afficherPerso(Personne *p, SDL_Surface *screen)
{
    int N = p->num;
    int D = p->direction;
	
    if(p->direction == 0 && p->moving == 0){
		SDL_BlitSurface(p->image[2][0].per, NULL, screen, &p->posScreen);}
if(p->direction == 1 && p->moving == 0){
		SDL_BlitSurface(p->image[2][1].per, NULL, screen, &p->posScreen);}
if(p->moving == 1){
    SDL_BlitSurface(p->image[D][N].per, NULL, screen, &p->posScreen);}
}

void movePerso(Personne *p, Uint32 dt)
{
    // Implement the movePerso function
   if(p->direction==0 && p->moving == 1){
	p->Step=0.5*p->acceleration*dt*dt+3*dt;
	p->posScreen.x= p->posScreen.x + p->Step;
	if(p->posScreen.x == 1900)
		p->posScreen.x = 30;
	}
	if(p->direction==1 && p->moving == 1){
	p->Step=0.5*p->acceleration*dt*dt+3*dt;
	p->posScreen.x= p->posScreen.x - p->Step;
	if(p->posScreen.x == 0)
		p->posScreen.x = 30;
	}
	
		
	/*if(p->posScreen.x >= 1800)
		p->posScreen.x = 1800;
	if(p->posScreen.x <= 0)
		p->posScreen.x = 30;*/
	
}

void animerPerso(Personne *p)
{
    // Implement the animerPerso function
  p->num=0;
  if(p->direction == 0 && p->moving == 1){
	if(p->num==3)
		p->num=0;
	else
		p->num++;}
  if(p->direction == 1 && p->moving == 1){
	
	if(p->num==3)
		p->num=0;
	else
		p->num++;}
 if(p->moving == 0 && p->direction == 0){
	p->num=0;}
 if(p->moving == 0 && p->direction == 1){
	p->num=0;}
	
	
}

void saut(Personne *p, int dt, int posinit, int ST)
{
    // Implement the saut function
	int G=10;
	int val=10;
	int SV=10;
	static int pos_absolux = -50;  // Make pos_absolux static to retain its value between function calls
    static int pos_absoluy = 0;
	if(p->direction == 0){
    if (p->up == 1) {
        pos_absolux += 4;
        pos_absoluy = (-0.04 * (pos_absolux * pos_absolux) + 100);
        p->posScreen.x += pos_absolux + 50;
        p->posScreen.y -= pos_absoluy;

        if (pos_absoluy == 100) {
            p->posScreen.y += pos_absoluy;
        }

        if (pos_absolux >= 10) {
            pos_absolux = -50;
            p->up = 0;
        }
    } else { // Character is coming down
        pos_absoluy = 0.5 * G * dt * dt;
        p->posScreen.y += pos_absoluy +20;

        if (p->posScreen.y >= 400) {
            p->posScreen.y = 400; // Ensure the character doesn't go below the initial position
        }
    }}
     if(p->direction == 1){
	if (p->up == 1) {
    pos_absolux += 4;
    pos_absoluy = (-0.04 * (pos_absolux * pos_absolux) + 100);
    p->posScreen.x -= pos_absolux + 50; // Adjust the x position for moving left
    p->posScreen.y -= pos_absoluy;

    if (pos_absoluy == 100) {
        p->posScreen.y += pos_absoluy;
    }

    if (pos_absolux >= 10) {
        pos_absolux = -50;
        p->up = 0;
    }
} else { // Character is coming down
    pos_absoluy = 0.5 * G * dt * dt;
    p->posScreen.y += pos_absoluy +20;

    if (p->posScreen.y >= 400) {
        p->posScreen.y = 400; // Ensure the character doesn't go below the initial position
    }
}}
}

void liberer(Personne *p)
{
    SDL_FreeSurface(p->image[0][0].per);
    SDL_FreeSurface(p->image[0][1].per);
    SDL_FreeSurface(p->image[0][2].per);
    SDL_FreeSurface(p->image[1][0].per);
    SDL_FreeSurface(p->image[1][1].per);
    SDL_FreeSurface(p->image[1][2].per);
    SDL_FreeSurface(p->image[2][0].per);
    SDL_FreeSurface(p->image[2][1].per);
}


