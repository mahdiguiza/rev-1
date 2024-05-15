#include "tic.h"

void jouer_jeu (SDL_Surface *ecran)
{
tic t;
int i,coup=0;
animation A;
char tentative[20];
int continu ,x,y;
SDL_Event event;
SDL_Rect pos;
SDL_Surface * text;

Mix_Chunk * son1;
Mix_Chunk * son2;
int quitter=1;

	son1 = Mix_LoadWAV("clic.wav");
	son2 = Mix_LoadWAV("censor-beep-01.wav");
	//Lancer la musique avant la boucle du jeu

t.gagnet=0;
	for(i=0;i<3 && quitter==1;i++)
{  
initialiserTic(&t,ecran);
initialiser_Animation(&A);
if (t.joueur==0)
{continu=0;
quitter=0;}
else
{sprintf(tentative," Tentative %d /3",i+1);
t.SurfaceText=TTF_RenderText_Solid(t.font, tentative, t.textColor);
SDL_BlitSurface(t.bg1, NULL, ecran , &t.Posbg);
SDL_BlitSurface(t.SurfaceText, NULL, ecran , &t.PosT);
SDL_Flip(ecran); 
SDL_Delay(2000);
t.tour=1;
continu=1;
 
while(continu)
{

afficherTic(t,ecran);

SDL_Flip(ecran);
if(t.joueur==-1)
{ if (t.tour<10 && atilganer(t.tabsuivi)==0)
 	{afficher_Animation(&A,ecran);
     
 		if ((t.tour) % 2==1)
 		{
 		calcul_coup(t.tabsuivi);
 		Mix_PlayChannel(-1,son1, 0);
 		t.tour++;
 			
 		}
 		else
 		{
 		
 		while(SDL_PollEvent(&event))
 		
 		{switch(event.type)
 		{case SDL_MOUSEBUTTONDOWN:
 		t.s=-1;

 		if(event.button.x > 182 && event.button.x <1040 &&
                            event.button.y > 94 && event.button.y < 94+495)
 		  {
 		  x=(event.button.x-182)/282;
		  y=(event.button.y-94)/162;
		  coup=3*y+x;
		 if(t.tabsuivi[coup]==0)
		  {t.tabsuivi[coup]=-1;
		  t.tour++;
		  Mix_PlayChannel(-1,son1, 0);}
		  
		  else if (t.tabsuivi[coup]!=0)
             {Mix_PlayChannel(-1,son2, 0); 
             text=TTF_RenderText_Solid(t.font,"This box is already filled ", t.textColor);
                   pos.x=300;
                   pos.y=650;
                   SDL_BlitSurface(text, NULL, ecran ,  &pos);
                   
                   SDL_Flip(ecran);
                   SDL_Delay(1000);}}
		break;
		  case SDL_QUIT:
		    continu=0;
		    quitter=0;
		    break;
		   
		 case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                	continu=0;
		    quitter=0;
		    break;
                    case SDLK_UP:
                        if(t.s==-1)
                        t.s=0;
                        else if(t.s<3 && t.s>=0)
                        	t.s=6+t.s;
                        else
                        t.s=t.s-3;
       
                        break;
                        
                    case SDLK_DOWN:
                        if(t.s==-1)
                        t.s=0;
                        else if(t.s<9 && t.s>=6)
                        	t.s=t.s-6;
                        else
                        t.s=t.s+3;
                        break;
                        
                    case SDLK_LEFT:
                    if(t.s==-1)
                        t.s=0;
                        else if(t.s==0)
                        t.s=8;
                        else
                        t.s=t.s-1;
                        break;
                        
                    case SDLK_RIGHT:
                    if(t.s==-1)
                        t.s=0;
                        else if(t.s==8)
                        t.s=0;
                        else
                        t.s=t.s+1;
                        break;
                case SDLK_x:
                 if(t.s!=-1)
                  {
                  if(t.tabsuivi[t.s]==0)
                  {t.tabsuivi[t.s]=-1;
                  Mix_PlayChannel(-1,son1, 0);
                   t.tour++;}
                   
                   else
                   
                   {Mix_PlayChannel(-1,son2, 0);
                    text=TTF_RenderText_Solid(t.font,"This box is already filled ", t.textColor);
                   pos.x=300;
                   pos.y=650;
                   SDL_BlitSurface(text, NULL, ecran ,  &pos);
                   
                   SDL_Flip(ecran);
                   SDL_Delay(1000);}
                   }
                break;
                }
          }
		  }}}
 else
        {
        afficherG(t.tabsuivi, ecran);
        SDL_Delay(2000);
         if(atilganer(t.tabsuivi)==-1)
         	t.gagnet++;
         
         continu=0;
        }}
        
        
        else
        
        
        
        {if (t.tour<10 && atilganer(t.tabsuivi)==0)
        {afficher_Animation(&A,ecran);
        if ((t.tour) % 2==1)
        {while(SDL_PollEvent(&event))
 		
 		{switch(event.type)
 		{case SDL_MOUSEBUTTONDOWN:
 		t.s=-1;

 		if(event.button.x > 182 && event.button.x < 1040 &&
                            event.button.y > 94 && event.button.y < 94+495)
 		  {
 		  x=(event.button.x-182)/282;
		  y=(event.button.y-94)/162;
		  coup=3*y+x;
		 if(t.tabsuivi[coup]==0)
		  {t.tabsuivi[coup]=-1;
		  Mix_PlayChannel(-1,son1, 0);
		  t.tour++;}
		  
		  else 
                   
                   {Mix_PlayChannel(-1,son2, 0); 
                   text=TTF_RenderText_Solid(t.font,"This box is already filled ", t.textColor);
                   pos.x=300;
                   pos.y=650;
                   SDL_BlitSurface(text, NULL, ecran ,  &pos);
                   
                   SDL_Flip(ecran);
                   SDL_Delay(1000);
                   }
		  
		  }
		break;
		  case SDL_QUIT:
		    continu=0;
		    quitter=0;
		    break;
		   
		 case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                	continu=0;
		    quitter=0;
		    break;
                    case SDLK_UP:
                        if(t.s==-1)
                        t.s=0;
                        else if(t.s<3 && t.s>=0)
                        	t.s=6+t.s;
                        else
                        t.s=t.s-3;
       
                        break;
                        
                    case SDLK_DOWN:
                        if(t.s==-1)
                        t.s=0;
                        else if(t.s<9 && t.s>=6)
                        	t.s=t.s-6;
                        else
                        t.s=t.s+3;
                        break;
                        
                    case SDLK_LEFT:
                    if(t.s==-1)
                        t.s=0;
                        else if(t.s==0)
                        t.s=8;
                        else
                        t.s=t.s-1;
                        break;
                        
                    case SDLK_RIGHT:
                    if(t.s==-1)
                        t.s=0;
                        else if(t.s==8)
                        t.s=0;
                        else
                        t.s=t.s+1;
                        break;
                case SDLK_x:
                 if(t.s!=-1)
                  {
                  if(t.tabsuivi[t.s]==0)
                  {t.tabsuivi[t.s]=-1;
                  Mix_PlayChannel(-1,son1, 0);
                   t.tour++;}
                   else
                   
                   {Mix_PlayChannel(-1,son2, 0); 
                   text=TTF_RenderText_Solid(t.font,"This box is already filled ", t.textColor);
                   pos.x=300;
                   pos.y=650;
                   SDL_BlitSurface(text, NULL, ecran ,  &pos);
                   
                   SDL_Flip(ecran);
                   SDL_Delay(1000);}
                   
                   }
                break;
                }
          }
		  }}
		  else
		 {calcul_coup(t.tabsuivi);
 		t.tour++; 
 		Mix_PlayChannel(-1,son1, 0);}}
 		
        else
        {
        
        afficherG(t.tabsuivi, ecran);
        SDL_Delay(2000);
         if(atilganer(t.tabsuivi)==-1)
         	t.gagnet++;
         
         continu=0;
        }}
 		
 		
		SDL_Flip(ecran); 
		SDL_Delay(500);
		   }
	
	
	}
	
	}
	if (quitter==1)
	{Resultat(t,ecran);
         SDL_Flip(ecran);
         SDL_Delay(2000);}
	
	//liberert(t);
	

	}	

