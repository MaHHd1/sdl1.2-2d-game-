#include "header.h"
void initIMG(image *IMG,int x,int y,char nom[])
{
IMG->url=IMG_Load(nom);
if(IMG->url==NULL){
		printf("Pas d'image\n");
	}
else
{
	IMG->pos.x=x;
	IMG->pos.y=y;
}


}
void afficher_image(SDL_Surface *surf,image img){
	SDL_BlitSurface(img.url,NULL,surf,&(img.pos));
}
void initPerso2(Personne *p)
{
    p->direction = 0;
    p->moving = 0;
    p->num = 0;
    p->up = 0;
    p->vitesse = 5;
    p->acceleration = 10;
    p->score = 100;
    p->posScreen.x = 300;
    p->posScreen.y = 400;
    p->posScreen.w = 1; 
    p->posScreen.h = 1; 

    p->image[0][0].per = IMG_Load("1.4-removebg-preview.png");
    p->image[0][1].per = IMG_Load("4.4-removebg-preview.png");
    p->image[0][2].per = IMG_Load("5.4-removebg-preview.png");
    p->image[1][0].per = IMG_Load("2.4-removebg-preview.png");
    p->image[1][1].per = IMG_Load("3.4-removebg-preview.png");
    p->image[1][2].per = IMG_Load("6.4-removebg-preview.png");
    p->image[2][0].per = IMG_Load("1.4-removebg-preview.png");
    p->image[2][1].per = IMG_Load("2.4-removebg-preview.png");




}
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
    p->posScreen.w = 1; 
    p->posScreen.h = 1; 

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
//SDL_Flip(screen);
}

void movePerso(Personne *p, Uint32 dt)
{
    
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
    
  p->num=0;
  if(p->moving == 1){
	if(p->num==3)
		p->num=0;
	if(p->num != 3)
		p->num++;}
  /*if(p->direction == 1 && p->moving == 1){
	
	if(p->num==3)
		p->num=0;
	if(p->num != 3)
		p->num++;}*/
 if(p->moving == 0 && p->direction == 0){
	p->num=0;}
 if(p->moving == 0 && p->direction == 1){
	p->num=0;}
	
	
}

void saut(Personne *p, int dt, int posinit)
{
    
	int G=10;
	int val=10;
	int SV=10;
	static int pos_absolux = -50;  
    static int pos_absoluy = 0;
	int jump_height = 80;
	int jump_speed = 15;
	if(p-> moving == 0){
	if(p->up == 1 ){
		p->posScreen.y -= jump_speed;
		pos_absoluy += jump_speed;
		if(pos_absoluy >= jump_height){
			p->up=0;}
		

	}
	else{
	p->posScreen.y += jump_speed;
	pos_absoluy -= jump_speed;
	if(p->posScreen.y >= 600 ){
			p->posScreen.y = 600;
			p->up=0;}}


}
	if(p->direction == 0 && p->moving ==1){
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

        if (p->posScreen.y >= 600) {
            p->posScreen.y = 600; 
        }
    }}
     if(p->direction == 1 && p->moving == 1){
	if (p->up == 1) {
    pos_absolux += 4;
    pos_absoluy = (-0.04 * (pos_absolux * pos_absolux) + 100);
    p->posScreen.x -= pos_absolux + 50; 
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

    if (p->posScreen.y >= 600) {
        p->posScreen.y = 600; 
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
void liberer2(image *I)
{

	SDL_FreeSurface(I->url);

}


