#include "hearder.h"

void initPerso(Personne *p)
{
	p->direction=0;
	p->num=0;
	p->up=0;
	p->vitesse=5;
        p->acceleration=0;
	p[0][0].filename = "";
    	p[0][1].filename = "";
    	p[0][2].filename = "";
	p[0][3].filename = "";
	p[0][4].filename = "";
	p[0][5].filename = "";
    

    for (int i = 0; i < 3; i++) {
	for (int j=0; j < 5; j++){
        p[i].surface = IMG_Load(p[i][j].filename);
        if (p[i][j].surface == NULL) {
            fprintf(stderr, "Erreur lors du chargement de l'image %s : %s\n", p[i].filename, SDL_GetError());
            exit(EXIT_FAILURE);
         }
       }
    }
	
	
	

}
void afficherPerso(Personne p,SDL_Surface *screen)
{
//etheya el max yetbadel tebah el matrice 
/*if(p->num==6)
	p->num=0;
else
	p->num++;*/
int N = p.num;
int D = p.direction
SDL_BlitSurface(p[D][N].posIMG,NULL,screen,&(p.posSurface));
}
void movePerso(Personne *p,Uint32 dt)
{

	p->posScreen=0.5*p->acceleration*dt*dt+p->vitesse*dt
	





}
void saut(Personne *P,int dt, int posinit)
{
	if(p->posScreen == max)//cree valeur max a ne pas depacer
	      p->down=1;  //decente
	if(p->down == 1)
		
	if(p->posScreen == posinit)
		p->up=0;
		 
	


}
