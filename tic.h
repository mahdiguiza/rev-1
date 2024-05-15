#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#include <limits.h>
#include <stdbool.h>
typedef struct {
          SDL_Rect pose;
          SDL_Surface * image[6]  ; 
          int frame ;
     }animation;  
     
typedef struct{
	SDL_Surface* bg;
	SDL_Surface* bg1;
	SDL_Surface* S;
	int s;
	SDL_Surface * X;
	SDL_Surface *O;
	SDL_Rect Posbg;
	int tabsuivi[9];
	SDL_Rect pos;
	int tour;
	int joueur;
	SDL_Surface * SurfaceText;
	TTF_Font * font;
	SDL_Rect PosT;
	SDL_Color textColor;
	SDL_Rect tabS[9];
	SDL_Rect tabPos[9];
	int gagnet;
	
}tic;
     
     
void initialiser_Animation(animation *A);
void afficher_Animation(animation* A, SDL_Surface* ecran);
void initialiserTic(tic *t,SDL_Surface * ecran);
void afficherTic(tic t,SDL_Surface* ecran);
int atilganer(int tabsuivi[]);
int minimax(int tabsuivi[],int joueur);
void calcul_coup(int tabsuivi[]);
void Resultat(tic t,SDL_Surface * ecran);
//void liberert(tic t);
void afficherG(int tabsuivi[], SDL_Surface* ecran);

 #endif // HEAD_H_INCLUDED
