#include "enemie.h"

int 
nb_frame1=5,
ennemie_h=100,
ennemie_w=100,
ennemie_y=100,
ennemie_x=100;
int frame_delay = 200;
Uint32 last_frame_time = 0; 
int frame_delay2 = 200;
Uint32 last_frame_time2 = 0; 
int frame_delay3 = 200;
Uint32 last_frame_time3 = 0; 
int frame_delay4 = 200;
Uint32 last_frame_time4 = 0; 

void init_tab_anim_ennemie(SDL_Rect *clip, Ennemie *e)
{       
    for (int i = 0; i < nb_frame1; i++)
    {
        clip[i].h = ennemie_h;
        clip[i].w = ennemie_w;
        clip[i].x = i * ennemie_w;
        clip[i].y = 0;
    }
}

void initEnnemi(Ennemie *e)
{
    e->ennemie = IMG_Load("ENNEMIE2.png");
    e->pos_ennemie.x = 800;
    e->pos_ennemie.y = 504;
    init_tab_anim_ennemie(e->anim_ennemie, e);
    e->frame_ennemie = 0;
    e->direction = 0;
    e->col = 0;
    e->show = 1;
}



void afficherEnnemi(Ennemie e, SDL_Surface *screen)
{
    
    SDL_BlitSurface(e.ennemie, &e.anim_ennemie[e.frame_ennemie], screen, &e.pos_ennemie);

}



void deplacer(Ennemie * e)  {
    if (e->direction==0)
    {
        e->pos_ennemie.x += 5;
    }else if (e->direction==1)
    {
        e->pos_ennemie.x -= 5;
    }

    if (e->pos_ennemie.x > 600)
    {
        e->direction=1;
    }
    if (e->pos_ennemie.x < 400)
    {
        e->direction=0;
    }   
}


void deplacerIA(Ennemie * E, SDL_Rect posPerso) {
  if (((E -> pos_ennemie.x - posPerso.x) < 200) && ((E -> pos_ennemie.x - posPerso.x) > 80))  
   {
    E -> direction = 1; 
    E -> pos_ennemie.x -= 8;
  } 
  else if (((E -> pos_ennemie.x - posPerso.x) < -80) && ((E -> pos_ennemie.x - posPerso.x) > -400))
   {
    E -> direction = 0; 
    E -> pos_ennemie.x += 8;
  } 
  else if (((E -> pos_ennemie.x - posPerso.x) <= 80) && ((E -> pos_ennemie.x - posPerso.x) >= 0)) 
  {
    E -> direction = 3;
  } 
  else if (((E -> pos_ennemie.x - posPerso.x) <= 0) && ((E -> pos_ennemie.x - posPerso.x) >= -80)) 
  {
    E -> direction = 2;
  }
  else deplacer(E);

}


/*
void update_ennemie(Ennemie *e, SDL_Rect *p)
{ 
    deplacerIA(e, p);
    animer_ennemi(e);
}



int detect_collision_ennemie(SDL_Rect *p, Ennemie *e)
{
    if ((p->x + 105 < e->pos_ennemie.x) || (p->x > e->pos_ennemie.x + 50) ||
        (p->y + 152 < e->pos_ennemie.y) || (p->y > e->pos_ennemie.y + 50)){
        return 0;
    }else
        return 1;
}
*/

int collision(SDL_Rect E, SDL_Rect p) {
  int collision,px,py;
  px=p.x+100;
  py=p.y+120;
  if (((px + p.w) < E.x) || (px > (E.x + E.w)) || ((py + p.h) < E.y) || (py > (E.y + E.h))) 
  {
    collision = 0;
  } else {
    collision = 1;
  }

  return collision;
}


int gerer(Ennemie *e) 
{
    e->show = 0;
    return 0; 
}

void animer_ennemi(Ennemie *e)
{
    // ken ll fluidité mta3 el animation
    Uint32 current_time = SDL_GetTicks();
    if (current_time > last_frame_time + frame_delay)
    {
        e->frame_ennemie++; // temchi ll frame eli ba3dha
        if (e->frame_ennemie >= nb_frame1)
        {
            e->frame_ennemie = 0; // tarja3 ll frame louleneya ki tousel llekher
        }
        last_frame_time = current_time; // mise à jour wa9t ekher frame ll fluidité
    }
}
