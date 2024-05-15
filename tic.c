#include "tic.h"

void initialiserTic(tic *t,SDL_Surface * ecran)
{
int i;
int S=-1;


Mix_Chunk *son; 
SDL_Rect posText;
SDL_Surface * texttik;
SDL_Surface * im1;
SDL_Surface * im1S;
SDL_Surface * im2;
SDL_Surface * im2S;
SDL_Rect pos1;
SDL_Rect pos2;
SDL_Event e;

son = Mix_LoadWAV("button.wav");

  t->bg=IMG_Load("BG .png");
  t->bg1=IMG_Load("BG11.png");
  t->X=IMG_Load("X.png");
  t->O=IMG_Load("O.png");
  for(i=0;i<9;i++)
  {
  t->tabsuivi[i]=0;
  }
  t->tour=0;
  t->s=-1;
  t->S=IMG_Load("selection.png");
  
  t->pos.x=330;
  t->pos.y=150;
  t->pos.h=164;
  t->pos.w=282;
  
  im1=IMG_Load("IMAGE1.gif");
  im1S=IMG_Load("IMAGE1S.gif");
  im2=IMG_Load("IMAGE2.gif");
  im2S=IMG_Load("IMAGE2S.gif");
  pos1.x=600;
  pos1.y=300;
  pos1.h=59;
  pos1.w=170;
  
  pos2.x=600;
  pos2.y=400;
  pos2.h=59;
  pos2.w=170;
  
  t->Posbg.x=0;
  t->Posbg.y=0;
  t->Posbg.h=800;
  t->Posbg.w=800;
  
  t->font=TTF_OpenFont("arial.ttf",50);
  t->textColor.r=0;
  t->textColor.g=0;
  t->textColor.b=0;
  t->PosT.x=400;
  t->PosT.y=400;
  
  t->joueur=0;
  
  posText.x=400;
  posText.y=200;
  texttik=TTF_RenderText_Solid(t->font,"Who starts the first round ", t->textColor);
  int continu=1;
  bool sonJoueSurvol1 = false;
         bool sonJoueSurvol2 = false; 
  while(continu)
  {SDL_BlitSurface(t->bg1, NULL, ecran ,  &t->Posbg);
  SDL_BlitSurface(texttik, NULL, ecran ,  &posText);
  if(S==-1)
    {SDL_BlitSurface(im1, NULL, ecran ,  &pos1);
      SDL_BlitSurface(im2, NULL, ecran , &pos2);}
     else  if(S==0)
     { SDL_BlitSurface(im1S, NULL, ecran ,  &pos1);
     SDL_BlitSurface(im2, NULL, ecran , &pos2);}
     else
     {SDL_BlitSurface(im1, NULL, ecran ,  &pos1);
      SDL_BlitSurface(im2S, NULL, ecran ,  &pos2);}
      

     SDL_PollEvent(&e);
     switch(e.type)
     {case SDL_QUIT:
		    continu=0;
		    
		    break;
     
     case SDL_MOUSEMOTION:
     S=-1;
     if(e.motion.x > 600 && e.motion.x < 600+170 && e.motion.y > 300 && e.motion.y < 359)
                           { SDL_BlitSurface(im1S, NULL, ecran ,  &pos1);
                            if (!sonJoueSurvol1) {
                     Mix_PlayChannel(-1,son, 0); 
                     sonJoueSurvol1 = true;   
                 }}
                 else
                 sonJoueSurvol1 = false; 
                 
                 
                 
     if(e.motion.x > 600 && e.motion.x < 600+170 &&  e.motion.y > 400 && e.motion.y < 459)
                           { SDL_BlitSurface(im2S, NULL, ecran ,  &pos2);
                           if (!sonJoueSurvol2) {
                     Mix_PlayChannel(-1,son, 0); 
                     sonJoueSurvol2 = true;   
                 }}
                 else
                 sonJoueSurvol2 = false; 
                 
     break;
     
     case SDL_MOUSEBUTTONDOWN:
     if(e.button.x > 600 && e.button.x < 600+170 && e.button.y > 300 && e.button.y < 359)
                            {t->joueur=1;
                            continu=0;}
     if(e.button.x > 600 && e.button.x < 600+170 &&  e.button.y > 400 && e.button.y < 459)
                            {t->joueur=-1;
                            continu=0;}
     break;
     case SDL_KEYDOWN:
          switch (e.key.keysym.sym) {
          
                  case SDLK_UP:
                  if(S==-1 || S==1)
                  {S=0;
                  SDL_BlitSurface(im1S, NULL, ecran ,  &pos1);
                 
                  
                  }
                  else if(S==0)
                  {S=1;
                  SDL_BlitSurface(im2S, NULL, ecran ,  &pos2);
                  }
                  break;
                  
                  case SDLK_DOWN:
                  if(S==-1 || S==1)
                  {S=0;
                  SDL_BlitSurface(im1S, NULL, ecran ,  &pos1);
                  
                  }
                  else 
                  {S=1;
                  SDL_BlitSurface(im2S, NULL, ecran ,  &pos2);
                  }
                  break;
                  case SDLK_ESCAPE:
                	continu=0;
		    break;
                  case SDLK_SPACE:
                  if(S==0)
                  {t->joueur=1;
                  continu=0;}
                  else
                  {t->joueur=-1;
                  continu=0;}
                  break;
     }
     break;}
     
     SDL_Flip(ecran); 
     
  }
  
  for(i=0;i<9;i++)
  {
  t->tabPos[i].x=t->pos.w*(i%3)+260;
  t->tabPos[i].y=t->pos.h*(i/3)+130;
  t->tabPos[i].h=164;
  t->tabPos[i].w=282;
  }
  
  
   for(i=0;i<9;i++)
  {
  t->tabS[i].x=t->pos.w*(i%3)+185;
  t->tabS[i].y=t->pos.h*(i/3)+95;
  t->tabS[i].h=164;
  t->tabS[i].w=282;
  }
  }
  void afficherTic(tic t,SDL_Surface* ecran)
  {
  int i;
  
  SDL_BlitSurface(t.bg, NULL, ecran ,  &t.Posbg);
  
  
  for(i=0;i<9;i++)
  {
  	if (t.tabsuivi[i]==-1)
  	{
  	  SDL_BlitSurface(t.X, NULL, ecran , &t.tabPos[i]);
  	  }
  	 
  	  if(t.tabsuivi[i]==1)
  	  {
  	  	SDL_BlitSurface(t.O, NULL, ecran , &t.tabPos[i]);
  	  	}
  }
  if (t.s>=0 && t.s<=8)
  SDL_BlitSurface(t.S, NULL, ecran , &t.tabS[t.s]);
  
  
  }
  
  



int atilganer(int tabsuivi[])
{
  int i,tr;
  int ligne_gagnantes[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
  for(i=0;i<8 ;i++)
  {
  	if(tabsuivi[ligne_gagnantes[i][0]]==tabsuivi[ligne_gagnantes[i][1]] 
  	&& tabsuivi[ligne_gagnantes[i][1]]==tabsuivi[ligne_gagnantes[i][2]] 
  	&& tabsuivi[ligne_gagnantes[i][2]]!=0)
  	{
  	return tabsuivi[ligne_gagnantes[i][2]];
}
}
return 0;
}

void Resultat(tic t,SDL_Surface * ecran)
{int i,angle=200;
	
	
	if(t.gagnet==2 || t.gagnet==3)
	{for(i=0;i<6;i++)
	{t.SurfaceText=TTF_RenderText_Solid(t.font,"GOOD ", t.textColor);
	SDL_Surface* rotozoomedSurface = rotozoomSurface(t.SurfaceText,0,i, 0);
	SDL_BlitSurface(t.bg1, NULL, ecran , &t.Posbg);
	SDL_BlitSurface(rotozoomedSurface, NULL, ecran, &t.PosT);
	SDL_Flip(ecran);
	SDL_Delay(200);}}
	
	
	else
	{t.SurfaceText=TTF_RenderText_Solid(t.font,"Hard Luck ", t.textColor);
	while(angle>0){
		SDL_Surface* rotozoomedSurface = rotozoomSurface(t.SurfaceText, angle, 1.0, 0);
		SDL_BlitSurface(t.bg1, NULL, ecran , &t.Posbg);

		SDL_BlitSurface(rotozoomedSurface, NULL, ecran, &t.PosT);
		SDL_Flip(ecran);
		angle=angle-10;
 		 SDL_Delay(70); 
	}}
	
	
	

}
	
	
	
	
	
	

  /*void liberert(tic t)
  {
  	SDL_FreeSurface(t.bg);
  	SDL_FreeSurface(t.X);
  	SDL_FreeSurface(t.O);
  	TTF_CloseFont(t.font);
  }*/
  
  
int minimax(int tabsuivi[], int joueur) {
    int gagnant = atilganer(tabsuivi);
    if (gagnant != 0) {
        
        
    if(joueur==1 && gagnant==1)
 	    return 1;
 	  else if (joueur==-1 && gagnant==-1) 
 	    return -1;
    else
      return 0; 
    }

    int meilleur_coup = -1;
    int meilleure_valeur ;
   
    if(joueur==1)
  meilleure_valeur=INT_MIN;
  else
  meilleure_valeur=INT_MAX;

    for (int i = 0; i < 9; i++) {
        if (tabsuivi[i] == 0) {
            tabsuivi[i] = joueur;
            int valeur_coup = minimax(tabsuivi, -joueur);
            tabsuivi[i] = 0;
            //ytasti itha ken el joueur oila el robot rbeh
            if ((joueur == 1 && valeur_coup > meilleure_valeur) || (joueur == -1 && valeur_coup < meilleure_valeur)) {
                meilleure_valeur = valeur_coup;
                meilleur_coup = i;
            }
        }
    }

    return meilleur_coup;
}







 
 
 void calcul_coup(int tabsuivi[]) {
    int i, meilleure_valeur, valeur_coup, meilleur_coup;
    meilleure_valeur = INT_MIN;
    meilleur_coup = -1;
    
    for (i = 0; i < 9; i++) {
        if (tabsuivi[i] == 0) {
            tabsuivi[i] = 1;
            valeur_coup = minimax(tabsuivi, -1);
            tabsuivi[i] = 0;
            
            if (valeur_coup > meilleure_valeur) {
                meilleure_valeur = valeur_coup;
                meilleur_coup = i;
            }
        }
    }
    
    if (meilleur_coup != -1) {
        tabsuivi[meilleur_coup] = 1;
    }
}

  	
 		
  void initialiser_Animation(animation *A)
  {
  int i;
  char filename[50];
 for( i=0;i<=5;++i){
 sprintf(filename,"%d.png",i);
  A->image[i]=IMG_Load(filename);
  if(A->image[i]==NULL) {
    printf("erreur iteraton %d",i);
}
}
  A->pose.x=1100;
  A->pose.y=120;
  A->pose.h=220;
  A->pose.w=125;
  A->frame=0;
  }
  
  void afficher_Animation(animation *A, SDL_Surface* ecran)
  {	
   
         SDL_BlitSurface(A->image[A->frame], NULL, ecran, &A->pose);
            A->frame++;
           
        if(A->frame>5){
           A->frame=0;}        
 }
 
 void afficherG(int tabsuivi[], SDL_Surface* ecran)
 {
 SDL_Surface * im1=IMG_Load("GAGNET1.png");
 SDL_Surface * im2=IMG_Load("GAGNET2.png");
 SDL_Surface * im3=IMG_Load("GAGNET3.png");
 SDL_Surface * im4=IMG_Load("GAGNET4.png");
 int i;
 SDL_Rect tab[9];
 
 for(i=0;i<3;i++)
 {tab[i].y=165+130*i;
 tab[i].x=335;
 tab[i].h=im1->h;
 tab[i].w=im1->w;
 }
 for(i=3;i<6;i++)
 {tab[i].y=170;
 tab[i].x=350+250*(i-3);
 tab[i].h=im2->h;
 tab[i].w=im2->w;
 }
 tab[6].x=332;
 tab[6].y=150;
 tab[6].h=im3->h;
 tab[6].w=im3->w;
 
 tab[7].x=335;
 tab[7].y=124;
 tab[7].h=im4->h;
 tab[7].w=im4->w;
 
 
 
  if(tabsuivi[0]==tabsuivi[1] && tabsuivi[1]==tabsuivi[2] && tabsuivi[2]!=0 )
  SDL_BlitSurface(im1, NULL, ecran, & tab[0]);
  if(tabsuivi[3]==tabsuivi[4] && tabsuivi[4]==tabsuivi[5]  && tabsuivi[3]!=0)
  SDL_BlitSurface(im1, NULL, ecran, & tab[1]);
  if(tabsuivi[6]==tabsuivi[7] && tabsuivi[7]==tabsuivi[8] && tabsuivi[6]!=0)
  SDL_BlitSurface(im1, NULL, ecran, & tab[2]);
  
  
  if (tabsuivi[0]==tabsuivi[3] && tabsuivi[3]==tabsuivi[6] && tabsuivi[6]!=0)
       SDL_BlitSurface(im2, NULL, ecran, &tab[3]);
       
      if (tabsuivi[1]==tabsuivi[4] && tabsuivi[4]==tabsuivi[7] && tabsuivi[7]!=0)
       SDL_BlitSurface(im2, NULL, ecran, &tab[4]);
       
       if (tabsuivi[2]==tabsuivi[5] && tabsuivi[5]==tabsuivi[8] && tabsuivi[8]!=0)
       SDL_BlitSurface(im2, NULL, ecran, &tab[5]);
       
   if (tabsuivi[0]==tabsuivi[4] && tabsuivi[4]==tabsuivi[8] && tabsuivi[8]!=0)
       SDL_BlitSurface(im3, NULL, ecran, & tab[6]);
       
   if (tabsuivi[2]==tabsuivi[4] && tabsuivi[4]==tabsuivi[6] && tabsuivi[6]!=0)
       SDL_BlitSurface(im4, NULL, ecran, & tab[7] );
       
       
 
 SDL_Flip(ecran);
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 	
  	
