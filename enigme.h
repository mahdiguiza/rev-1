#define SCREEN_W 800 //ordh l ecran
#define SCREEN_H 480 //toul l ecran
#include <SDL/SDL_mixer.h>

typedef struct 
{
	SDL_Surface* image[30]; // el tsawer mtaa el background
	SDL_Surface *background_GameOver, *background_Victory; // el backgrounds mtaa el interface lose w win
	SDL_Rect PositionBackground; // l position mtaa l background 
        int current_frame, previous_frame; // deux variables de types entier bech nestaamlouhom fel animation
	SDL_Surface *ImageOriginale, *ImageModifiee; // ezouz tsawer mtaa l enigme
	SDL_Rect PositionImageOriginale, PositionImageModifiee; // les positions mtaa tsawer mtaa l enigme
	int ReponseCorrecte; // el ijeba eshiha li bech tetkra mel fichier
	Mix_Music *musique_enigme, *musique_victoire, *musique_defaite; // l musica mtaa l enigme, leffet son mtaa win w lose
}enigme;

void initialiserEnigme(enigme* e); // l fonction li tinitialisi les champs mtaa l enigme li mahomch generé aleatoirement
void afficherEnigme(enigme e, SDL_Surface* ecran); // l fonction li taffichi kolchay
void animerEnigme(enigme* e); // l fonction li nethakmou beha fel valeur mtaa current frame bech nassuriw l animation
void genererEnigme(enigme *e); // l fonction li tinitialisi les champs mtaa l enigme li generé aleatoirement
void freeEnigme(enigme e); // fonction tliberi etsawer lkol
void interface_win(SDL_Surface* ecran, int* boucle, enigme e); // fonction tassuri l'affichage mtaa l background win 
void interface_lose(SDL_Surface* ecran, int* boucle, enigme e); // fonction tassuri l'affichage mtaa l background lose
int generateRandomNumber(int min, int max); // fonction tgeneri noumrou aleatoirement fi interval mouayen









