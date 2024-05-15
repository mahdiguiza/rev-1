#ifndef ENNEMIE_H_INCLUDED
#define ENNEMIE_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>


typedef struct
{
    SDL_Surface *ennemie; // stoki el surface mta3 el ennemie
    SDL_Rect pos_ennemie; //el rectangle
    SDL_Rect anim_ennemie[70];
    int frame_ennemie;
    int direction;
    int col;
    int type;
    int maxi_up, maxi_down;
    int show;
    SDL_Rect pos_ennemie_initiale;

} Ennemie;

void init_tab_anim_ennemie(SDL_Rect *clip, Ennemie *e);

void initEnnemi(Ennemie *e);

void afficherEnnemi(Ennemie e, SDL_Surface *screen);

void deplacer(Ennemie * e);

void deplacerIA(Ennemie * E, SDL_Rect posPerso);

//void update_ennemie(Ennemie *e, Personnage *p);

//int detect_collision_ennemie(Personnage *p, Ennemie *e);

int gerer(Ennemie *e);

void animer_ennemi(Ennemie *e);

int collision(SDL_Rect E, SDL_Rect p);

#endif
