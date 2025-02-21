#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"
void initmap( minimap * m)
{
	m->img_map=IMG_Load("minmap.png");
	m->img_joueur=IMG_Load("mini_joueur.bmp"); 

	m->pos_joueur.x=500;
	m->pos_joueur.y=200;
	m->pos_map.x=500;
	m->pos_map.y=0;
}

void afficherminimap (minimap m,SDL_Surface *screen)
{
	SDL_BlitSurface(m.img_map,NULL,screen,&m.pos_map);
	SDL_BlitSurface(m.img_joueur,NULL,screen,&m.pos_joueur);
}


SDL_Rect MAJMinimap (SDL_Rect Posjoueur,int redemensionement,SDL_Rect camera)////////pos absoluee
{
	SDL_Rect pos_joueur;
	pos_joueur.x= (((camera.x +Posjoueur.x)*redemensionement)/100)+400;
	pos_joueur.y= (((camera.y +Posjoueur.y)*redemensionement)/100)-2;
	return pos_joueur;
}





void affichertemp (Uint32 *temps,SDL_Surface *screen,TTF_Font *police)
{

	SDL_Surface *chrono = NULL;
	SDL_Rect positionChrono;
	SDL_Color couleur = {255,255,255};

	int min=0,sec=0;
	char texteChrono [40] = "";

	positionChrono.x = 1600;
	positionChrono.y = 10;

	(*temps)=SDL_GetTicks();
	(*temps)/=1000;
	min=((*temps)/60);
	sec=(*temps) - (60*min);

	sprintf(texteChrono,"%02d:%02d",min,sec);

	SDL_FreeSurface(chrono);
	chrono = TTF_RenderText_Solid(police,texteChrono,couleur);
	SDL_BlitSurface(chrono,NULL,screen,&positionChrono);
	
}




SDL_Color GetPixel(SDL_Surface *mask,int x,int y)
{
	SDL_Color color;
	Uint32 col=0;

	//determine position
	char * pPosition=(char*)mask->pixels;

	pPosition+=(mask->pitch *y);
	pPosition+=(mask->format->BytesPerPixel *x);
	memcpy(&col,pPosition,mask->format->BytesPerPixel);

	//convertir color 
	SDL_GetRGB(col,mask->format,&color.r,&color.g,&color.b);
	return(color);
}

int collisionPP_droite( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera)
{
	int collision=0;
	int i;

	SDL_Color couleur_obstacle={0,0,0},test;
	//int couleur_obstacle;
	//SDL_Color couleur_obstacle;
	//Uint32 col=0;

	int pos[3][2];
	pos[0][0]=80+camera.x+posjoueur.x+posjoueur.w;
	pos[0][1]=100+posjoueur.y;
	pos[1][0]=80+camera.x+posjoueur.x+posjoueur.w;
	pos[1][1]=100+posjoueur.y+posjoueur.h/2;
	pos[2][0]=80+camera.x+posjoueur.x+posjoueur.w;
	pos[2][1]=100+posjoueur.y+posjoueur.h;
	for(i=0;i<2 && collision==0;i++)
	{
		test=GetPixel(mask,pos[i][0],pos[i][1]);
		if ((test.r==couleur_obstacle.r)&&(test.g==couleur_obstacle.g)&&(test.b==couleur_obstacle.b))
			collision=1;
			
	}
	return collision;
}


int collisionPP_gauche( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera)
{
	int collision=0;
	int i;

	SDL_Color couleur_obstacle={0,0,0},test;
	//int couleur_obstacle;
	//SDL_Color couleur_obstacle;
	//Uint32 col=0;

	int pos[3][2];
	pos[0][0]=80+camera.x+posjoueur.x;
	pos[0][1]=100+posjoueur.y;
	pos[1][0]=80+camera.x+posjoueur.x;
	pos[1][1]=100+posjoueur.y+posjoueur.h/2;
	pos[2][0]=80+camera.x+posjoueur.x;
	pos[2][1]=100+posjoueur.y+posjoueur.h;

	for(i=0;i<2 && collision==0;i++)
	{
		test=GetPixel(mask,pos[i][0],pos[i][1]);
		if ((test.r==couleur_obstacle.r)&&(test.g==couleur_obstacle.g)&&(test.b==couleur_obstacle.b))
			collision=1;
			

	}
	return collision;
}




int collisionPP_up( SDL_Rect posjoueur, SDL_Surface *mask)
{
	int collision=0;
	int i;

	SDL_Color couleur_obstacle={0,0,0},test;

	
	int posX,posY;
	posX=100+ posjoueur.x+ posjoueur.w/2;
	posY=120+posjoueur.y;

	test=GetPixel(mask,posX,posY);
	if ((test.r==couleur_obstacle.r)&&(test.g==couleur_obstacle.g)&&(test.b==couleur_obstacle.b))
		collision=1;

	return collision;
}


int collisionPP_down( SDL_Rect posjoueur, SDL_Surface *mask)
{
	int collision=0;
	int i;
	SDL_Color couleur_obstacle={0,0,0},test;
	
	int posX,posY;
	posX=100+ posjoueur.x+ posjoueur.w/2;
	posY=120+posjoueur.y+ posjoueur.h;

	test=GetPixel(mask,posX,posY);
	if ((test.r==couleur_obstacle.r)&&(test.g==couleur_obstacle.g)&&(test.b==couleur_obstacle.b))
		collision=1;

	return collision;
}


void initialiser_alerte (image * m)
{
	m->alerte[0]=IMG_Load("alert 1.png");
	m->alerte[1]=IMG_Load("alert2.png");
	m->alerte[2]=IMG_Load("alert3.png");
	
	m->posal.x=1850;
	m->posal.y=20;
	
}


void afficher_alerte(image m,SDL_Surface *screen)
{
	SDL_BlitSurface(m.alerte[m.etat],NULL,screen,&m.posal);
}







