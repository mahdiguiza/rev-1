#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "enigme.h"

void initialiserEnigme(enigme* e)
{
	// chargement mtaa tsawer l background lkol //
	e->image[0]=IMG_Load("multimediaEnigme/BG/bg1.png"); 
	e->image[1]=IMG_Load("multimediaEnigme/BG/bg2.png");
	e->image[2]=IMG_Load("multimediaEnigme/BG/bg3.png");
	e->image[3]=IMG_Load("multimediaEnigme/BG/bg4.png");
	e->image[4]=IMG_Load("multimediaEnigme/BG/bg5.png");
	e->image[5]=IMG_Load("multimediaEnigme/BG/bg6.png");
	e->image[6]=IMG_Load("multimediaEnigme/BG/bg7.png");
	e->image[7]=IMG_Load("multimediaEnigme/BG/bg8.png");
	e->image[8]=IMG_Load("multimediaEnigme/BG/bg9.png");
	e->image[9]=IMG_Load("multimediaEnigme/BG/bg10.png");
	e->image[10]=IMG_Load("multimediaEnigme/BG/bg11.png");
	e->image[11]=IMG_Load("multimediaEnigme/BG/bg12.png");
	e->image[12]=IMG_Load("multimediaEnigme/BG/bg13.png");
	e->image[13]=IMG_Load("multimediaEnigme/BG/bg14.png");
	e->image[14]=IMG_Load("multimediaEnigme/BG/bg15.png");
	e->image[15]=IMG_Load("multimediaEnigme/BG/bg16.png");
	e->image[16]=IMG_Load("multimediaEnigme/BG/bg17.png");
	e->image[17]=IMG_Load("multimediaEnigme/BG/bg18.png");
	e->image[18]=IMG_Load("multimediaEnigme/BG/bg19.png");
	e->image[19]=IMG_Load("multimediaEnigme/BG/bg20.png");
	e->image[20]=IMG_Load("multimediaEnigme/BG/bg21.png");
	e->image[21]=IMG_Load("multimediaEnigme/BG/bg22.png");
	e->image[22]=IMG_Load("multimediaEnigme/BG/bg23.png");
	e->image[23]=IMG_Load("multimediaEnigme/BG/bg24.png");
	e->image[24]=IMG_Load("multimediaEnigme/BG/bg25.png");
	e->image[25]=IMG_Load("multimediaEnigme/BG/bg26.png");
	e->image[26]=IMG_Load("multimediaEnigme/BG/bg27.png");
	e->image[27]=IMG_Load("multimediaEnigme/BG/bg28.png");
	e->image[28]=IMG_Load("multimediaEnigme/BG/bg29.png");
	e->image[29]=IMG_Load("multimediaEnigme/BG/bg30.png");
	//-----------------------------------------------------------//
	e->background_GameOver=IMG_Load("multimediaEnigme/BG/GAME_OVER.png"); // chargement mtaa l background lose
	e->background_Victory=IMG_Load("multimediaEnigme/BG/VICTORY.png"); // chargement mtaa l background win
	e->PositionBackground.x=0; // remplissage mtaa l position mtaa l background 
	e->PositionBackground.y=0;
	e->PositionImageOriginale.x=50; // remplissage mtaa l position mtaa el image loula mtaa el enigme
	e->PositionImageOriginale.y=200;
	e->PositionImageModifiee.x=450; // remplissage mtaa l position mtaa el image ethenya mtaa el enigme
	e->PositionImageModifiee.y=200;
        e->current_frame=0; // initialisation mtaa l variable current frame fel 0 puisque awel image bech tetaficha heya image[0]
	e->previous_frame=-1; // initialisation mtaa l variable previous frame fel -1
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	e->musique_enigme=Mix_LoadMUS("multimediaEnigme/music.mp3"); // chargement mtaa son li yemchi maa l enigme
	e->musique_victoire=Mix_LoadMUS("multimediaEnigme/win.mp3"); // chargement mtaa son mtaa rebh
	e->musique_defaite=Mix_LoadMUS("multimediaEnigme/lose.mp3"); // chargement mtaa son mtaa l khsara
	

}

void genererEnigme(enigme *e)
{
	int nb,ReponseCorrecte; // variable bech nkhabiw feha l ijeba shiha li bech nakrawha mel fichier texte
	char chemin_original[100], chemin_modified[100]; // hethouma des chemins bech nasn3ouhom bech nhelou behom les images mtaa l enigme
	FILE* fichier;
	nb=generateRandomNumber(1,6); // bech nhotou fi nb noumrou aleatoire bin 1 w 6 
	//tawika hasb l valeur mtaa nb bech nasn3ou les chemins li bech nhelou behom les images w nakraw les reponse correcte
	switch (nb)
	{
		case 1 :
		{
			strcpy(chemin_original,"multimediaEnigme/SPOTTHEDIFFERANCES/1/original.png");
			strcpy(chemin_modified,"multimediaEnigme/SPOTTHEDIFFERANCES/1/modified.png");
			fichier=fopen("multimediaEnigme/SPOTTHEDIFFERANCES/1/nb_differances.txt","r");	
			fscanf(fichier,"%d",&ReponseCorrecte);
			break;
		}
		case 2 :
		{
			strcpy(chemin_original,"multimediaEnigme/SPOTTHEDIFFERANCES/2/original.png");
			strcpy(chemin_modified,"multimediaEnigme/SPOTTHEDIFFERANCES/2/modified.png");
			fichier=fopen("multimediaEnigme/SPOTTHEDIFFERANCES/2/nb_differances.txt","r");	
			fscanf(fichier,"%d",&ReponseCorrecte);
			break;
		}
		case 3 :
		{
			strcpy(chemin_original,"multimediaEnigme/SPOTTHEDIFFERANCES/3/original.png");
			strcpy(chemin_modified,"multimediaEnigme/SPOTTHEDIFFERANCES/3/modified.png");
			fichier=fopen("multimediaEnigme/SPOTTHEDIFFERANCES/3/nb_differances.txt","r");	
			fscanf(fichier,"%d",&ReponseCorrecte);
			break;
		}
		case 4 :
		{
			strcpy(chemin_original,"multimediaEnigme/SPOTTHEDIFFERANCES/4/original.png");
			strcpy(chemin_modified,"multimediaEnigme/SPOTTHEDIFFERANCES/4/modified.png");
			fichier=fopen("multimediaEnigme/SPOTTHEDIFFERANCES/4/nb_differances.txt","r");	
			fscanf(fichier,"%d",&ReponseCorrecte);
			break;
		}
		case 5 :
		{
			strcpy(chemin_original,"multimediaEnigme/SPOTTHEDIFFERANCES/5/original.png");
			strcpy(chemin_modified,"multimediaEnigme/SPOTTHEDIFFERANCES/5/modified.png");
			fichier=fopen("multimediaEnigme/SPOTTHEDIFFERANCES/5/nb_differances.txt","r");	
			fscanf(fichier,"%d",&ReponseCorrecte);
			break;
		}
		case 6 :
		{
			strcpy(chemin_original,"multimediaEnigme/SPOTTHEDIFFERANCES/6/original.png");
			strcpy(chemin_modified,"multimediaEnigme/SPOTTHEDIFFERANCES/6/modified.png");
			fichier=fopen("multimediaEnigme/SPOTTHEDIFFERANCES/6/nb_differances.txt","r");	
			fscanf(fichier,"%d",&ReponseCorrecte);		
			break;
		}
	}
	e->ImageOriginale=IMG_Load(chemin_original); // chargement mtaa l image loula mtaa l enigme bel chemin li generineh aleatoirement
	e->ImageModifiee=IMG_Load(chemin_modified); // chargement mtaa l image thenya mtaa l enigme bel chemin li generineh aleatoirement
	e->ReponseCorrecte=ReponseCorrecte; // remplissage mtaa l champ reponse correcte bel valeur li krineha mel fichier
}

void animerEnigme(enigme* e)
{
	if (e->current_frame==29) // itheken etaswira li affiche heya lekhra
	{
		e->previous_frame=e->current_frame; // ettaswira li kbal lekhra twali heya lekhra	
		e->current_frame--; // etaswira li affiche se decremente
	}
	else if (e->current_frame==0) // itheken etaswira li affiche heya lekhra
		{
			e->previous_frame=e->current_frame; // ettaswira li kbal lekhra twali heya loula
			e->current_frame++; // etaswira li affiche s incremente
		}
    	else if (e->current_frame > e->previous_frame) // ken li affiche akber meli kbalha
		{
			e->previous_frame=e->current_frame; // yokodou ykadmou les 2
			e->current_frame++;
		}
    	else 
	{
		e->previous_frame=e->current_frame;		
		e->current_frame--;
	}
}

void afficherEnigme(enigme e, SDL_Surface* screen)
{
	SDL_BlitSurface(e.image[e.current_frame], NULL, screen, &e.PositionBackground); // affichage de la background animee 
	SDL_BlitSurface(e.ImageOriginale, NULL, screen, &e.PositionImageOriginale); // affichage mtaa taswira loula mtaa l enigme
	SDL_BlitSurface(e.ImageModifiee, NULL, screen, &e.PositionImageModifiee); // affichage mtaa taswira thenya mtaa l enigme
}

int generateRandomNumber(int min, int max) // fonction tgeneri noumrou aleatoire fi interval enti tdakhlou en parametres
{
    srand(time(NULL)); // Seed the random number generator
    return (min + rand() % (max - min + 1));
}


void freeEnigme(enigme e) // fonction tliberi les ressources en images
{
	SDL_FreeSurface(e.image[0]);
	SDL_FreeSurface(e.image[1]);
	SDL_FreeSurface(e.image[2]);
	SDL_FreeSurface(e.image[3]);
	SDL_FreeSurface(e.image[4]);
	SDL_FreeSurface(e.image[5]);
	SDL_FreeSurface(e.image[6]);
	SDL_FreeSurface(e.image[7]);
	SDL_FreeSurface(e.image[8]);
	SDL_FreeSurface(e.image[9]);
	SDL_FreeSurface(e.image[10]);
	SDL_FreeSurface(e.image[11]);
	SDL_FreeSurface(e.image[12]);
	SDL_FreeSurface(e.image[13]);
	SDL_FreeSurface(e.image[14]);
	SDL_FreeSurface(e.image[15]);
	SDL_FreeSurface(e.image[16]);
	SDL_FreeSurface(e.image[17]);
	SDL_FreeSurface(e.image[18]);
	SDL_FreeSurface(e.image[19]);
	SDL_FreeSurface(e.image[20]);
	SDL_FreeSurface(e.image[21]);
	SDL_FreeSurface(e.image[22]);
	SDL_FreeSurface(e.image[23]);
	SDL_FreeSurface(e.image[24]);
	SDL_FreeSurface(e.image[25]);
	SDL_FreeSurface(e.image[26]);
	SDL_FreeSurface(e.image[27]);
	SDL_FreeSurface(e.image[28]);
	SDL_FreeSurface(e.image[29]);
	SDL_FreeSurface(e.ImageOriginale);
	SDL_FreeSurface(e.ImageModifiee);
	SDL_FreeSurface(e.background_GameOver);
	SDL_FreeSurface(e.background_Victory);
}
	
	

void interface_win(SDL_Surface* screen, int* boucle, enigme e) // fonction tassuri l affichage mtaa l background win w maaha effet sonore win
{
	SDL_BlitSurface(e.background_Victory, NULL, screen, &e.PositionBackground); // bg
	SDL_Flip(screen);
	Mix_PlayMusic(e.musique_victoire, 0); // effet sonore
	SDL_Delay(3000);
	*boucle=0;
}

void interface_lose(SDL_Surface* screen, int* boucle, enigme e) // fonction tassuri l affichage mtaa l background lose w maaha effet sonore lose
{
	SDL_BlitSurface(e.background_GameOver, NULL, screen, &e.PositionBackground); // bg
	SDL_Flip(screen);
	Mix_PlayMusic(e.musique_defaite, 0); // effet sonore
	SDL_Delay(3000);
	*boucle=0;
}








	
