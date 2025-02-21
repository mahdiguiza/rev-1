#ifndef DER
#define DER
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
// Declaration des structures
typedef struct
{
  SDL_Surface *BgImg;
  SDL_Surface *vies;
  SDL_Surface *scores;

  SDL_Rect PositionBg;
  SDL_Rect positionperso;
  SDL_Rect camera;

  SDL_Rect posVie1;
  SDL_Rect posVie2;

  SDL_Rect posScore;
  TTF_Font *police;

  Mix_Music *music;
  
  SDL_Surface *sprite_coin;
  SDL_Rect positionCoin;
  SDL_Rect camera_coin;

  int frame;

  int vie;
  int score;

} Background;

typedef struct
{
  char name[10];
  int score;
  int time;

} ScoreInfo;
// Declaration Des Fonctions
void scrolling_multiplayer(Background *B,SDL_Rect p,int direction,Background *B2,SDL_Rect p2,int direction2);
void initBackground(Background *B, int diff);
void affBackground(Background *B, SDL_Surface *screen, int diff);
void animerBack(Background *B);
void scrolling(Background *B, SDL_Rect posPerso, int direction);
void sauvegarder(ScoreInfo s, char *file);
void 	bestScore(ScoreInfo s[], int n, char *file);
void freeBackground(Background *B);

#endif
