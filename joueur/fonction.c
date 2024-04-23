#include "header.h"

void initPerso(Personne *p)
{
	p->direction=0;
	p->num=0;
	p->up=0;
	p->vitesse=5;
        p->acceleration=0;
	p->score=100;
	p->vie.nv=3;
	p->posScreen.x=30;
	p->posScreen.y=460;
	p->posScreen.w=100;//largeur image
	p->posScreen.h=100;//Hauteur image
	//strcpy(p->image[0][0].filename,"images.png");
    	//strcpy(p->image[0][1].filename,"images.png");
	//strcpy(p->image[0][2].filename,"images.png");
	//strcpy(p->image[1][0].filename,"images2.png");
	//strcpy(p->image[1][1].filename,"images2.png");
	//strcpy(p->image[1][2].filename,"images2.png");
	//strcpy(p->image[2][0].filename,"images3.png");
	p->image[0][0].per = IMG_Load("images.jpg");
	p->image[0][1].per = IMG_Load("player1.png");
	p->image[0][2].per = IMG_Load("images.png");
	p->image[1][0].per = IMG_Load("images2.png");
	p->image[1][1].per = IMG_Load("images2.png");
	p->image[1][2].per = IMG_Load("images2.png");
	
	
	
    

    /*for (int i = 0; i < 3; i++) {
	for (int j=0; j < 3; j++){
        p->image[i][j].surface = IMG_Load(p->image[i][j].filename);
}}*/
        /*if (p->image[i][j].surface == NULL) {
            fprintf(stderr, "Erreur lors du chargement de l'image ");
            exit(EXIT_FAILURE);
         }
       }
    }*/
	
	
	

}//Perso
void afficherPerso(Personne *p,SDL_Surface *screen)
{

int N = p->num;//colone matrice
int D = p->direction;//line matrice
SDL_BlitSurface(p->image[D][N].per,NULL,screen,&p->posScreen);
/*if(p.up=1 && D==0)
	SDL_BlitSurface(p.image[2][0].surface,NULL,screen,&(p.posScreen));

if(p.up=1 && D==1)
	SDL_BlitSurface(p.image[2][1].surface,NULL,screen,&(p.posScreen));
//SDL_BlitSurface(p.score,NULL,screen,155,147);
if(p.vie.nv==3){
	//SDL_BlitSurface(p.score,NULL,screen,155,147);
}
if(p.vie.nv==2){
	//SDL_BlitSurface(p.score,NULL,screen,155,147);
}
if(p.vie.nv==1){
	//SDL_BlitSurface(p.score,NULL,screen,155,147);
}
if(p.vie.nv==0){
	//SDL_BlitSurface(p.score,NULL,screen,155,147);
}
}//afficher
	*/
//SDL_Flip(screen);
}
void movePerso(Personne *p,Uint32 dt)
{

	p->Step=0.5*p->acceleration*dt*dt+p->vitesse*dt;
	p->posScreen.x= p->posScreen.x + p->Step;
	





}//move
void saut(Personne *p,int dt, int posinit,int ST)
{
	
	int G=10;
	int val=10;
	int SV=10;
	/*if(p->posScreen == max)//cree valeur max a ne pas depacer
	      p->down=1;  //decente
	if(p->down == 1)
		
	if(p->posScreen == posinit)
		p->up=0;
	if(p->up == 1)
		
	if(y == posy)
		p->up=0;*/
	//saut horizontale
	if(ST==0){
	p->posScreen.y = p->posScreen.y + val;
	if(p->posScreen.y ==SV){
		p->posScreen.y = p->posScreen.y - val;
		p->up=0;}
	}
	

	//saut parabolique
	if(ST==1){
	p->posScreen.x = posinit + p->vitesse * dt;
	p->posScreen.y = p->acceleration*p->posScreen.x*p->posScreen.x + 100;
	if(p->posScreen.y >= SV){
		p->posScreen.y = p->posScreen.y - 100;
		p->up=0;}
	//p->vitesse = p->vitesse + G * dt;
	}
	
		 
	


}//Saut
void liberer(Personne *p)
{
    for (int i = 0; i < 2; i++) {
	for (int j=0; j < 3; j++){
		SDL_FreeSurface(p->image[i][j].per);
	}
	}




}//liberer
void animerPerso(Personne *p)
{
int n=2,m=3,l=5;
 if(p->direction==0){
	if(p->num==n-1)
		p->num=0;
	else
		p->num++;
	}
 else{
	if(p->num==n+m-1)
		p->num=n;
	else
		p->num++;
}
 if(p->num==n+m+l-1){
	if(p->num=n+m+l-1)
		p->num=n+m;
	else
		p->num++;
}
}//animer
