#include"menu.h"

void initilize_img(image* img,char* path,int x,int y){
	img->name=path;
	img->url=IMG_Load(img->name);
	if(img->url==NULL){
		printf("Pas d'image\n");
	}
	else{
		img->pos.x=x;
		img->pos.y=y;
	}
}
void afficher_image(SDL_Surface *surf,image img){
	SDL_BlitSurface(img.url,NULL,surf,&(img.pos));
}
void free_image(image img){
	SDL_FreeSurface(img.url);
}
void intro(Mix_Music *music){
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	music=Mix_LoadMUS("sfx/menu/menu.mp3");
	Mix_PlayMusic(music,-1);
	Mix_VolumeMusic(1000000000);
}
void liberer_music(Mix_Music *music){
	Mix_FreeMusic(music);
}
void musiquebref_click(Mix_Chunk *music){
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
	music=Mix_LoadWAV("sfx/click/click.wav");
	Mix_PlayChannel(-1,music,0);
	Mix_VolumeMusic(1000000000);
}
void musiquebref_drag(Mix_Chunk *music){//dragging sound(not used for now)
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
	music=Mix_LoadWAV("sfx/drag/drag_sfx_1.wav");
	if(music==NULL){
		printf("Couldn't load the sound\n");
	}
	else{
	Mix_PlayChannel(-1,music,0);
	Mix_VolumeMusic(10000);}
}
void liberer_musiquebref(Mix_Chunk *music){//segmentation fault
	Mix_FreeChunk(music);
}
void initialiser_text(texte* text,char* font,float size,int r,int g,int b,int x,int y){
	text->font=TTF_OpenFont(font,size);
	text->color.r=r;
	text->color.g=g;
	text->color.b=b;
	text->pos.x=x;
	text->pos.y=y;
}
void afficher_text(SDL_Surface* screen,texte text,char* message){
	text.txt=TTF_RenderText_Blended(text.font,message,text.color);
	SDL_BlitSurface(text.txt,NULL,screen,&text.pos);
}
void free_text(texte text){
	TTF_CloseFont(text.font);//segmentation fault
}
void load_images(Image images[]) {
    	images[0].filename = "MOON/M1.png";
    	images[1].filename = "MOON/M2.png";
    	images[2].filename = "MOON/M3.png";
	images[3].filename = "MOON/M4.png";
	images[4].filename = "MOON/M5.png";
	images[5].filename = "MOON/M6.png";
	images[6].filename = "MOON/M7.png";
	images[7].filename = "MOON/M8.png";
    

    for (int i = 0; i < 8; i++) {
        images[i].surface = IMG_Load(images[i].filename);
        if (images[i].surface == NULL) {
            fprintf(stderr, "Erreur lors du chargement de l'image %s : %s\n", images[i].filename, SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }
}

void free_images(Image images[]) {
    for (int i = 0; i < 8; i++) {
        SDL_FreeSurface(images[i].surface);
    }
}
