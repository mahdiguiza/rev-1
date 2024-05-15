
#include "background.h"

void initBackground(Background *B, int diff)
{

  B->PositionBg.x = 0;
  B->PositionBg.y = 0;

  B->camera.x = 0;
  B->camera.y = 0;
  B->camera.w = 1200;
  B->camera.h = 700;


  B->BgImg = IMG_Load("BACKGGG.png");
  
  
  B->sprite_coin= IMG_Load("rsz_coin_sprite.png");
  
  B->positionCoin.x= 100;
  B->positionCoin.y= 200;
  
    B->camera_coin.x= 0;
    B->camera_coin.y= 0;
    
        B->camera_coin.h= 100;
            B->camera_coin.w= 99;
            
            B->frame=0;
    
 
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
  B->music = Mix_LoadMUS("music.mp3");
  Mix_PlayMusic(B->music, -1);

  B->vies = IMG_Load("HEARTS.png");
  B->posVie1.x = 0;
  B->posVie1.y = 0;
  B->vie = 100;

  B->posVie2.x = 0;
  B->posVie2.y = 0;
  
  
  
  
  
  
  
  
  B->posVie2.h = 26;
  B->posVie2.w = 116;

  TTF_Init();
  B->police = TTF_OpenFont("font.ttf", 40);

  B->score = 10;
  B->posScore.x = 0;
  B->posScore.y = 50;
}

void affBackground(Background *B, SDL_Surface *screen, int diff)
{
  SDL_BlitSurface(B->BgImg, &(B->camera), screen, &(B->PositionBg));
   SDL_BlitSurface(B->sprite_coin, &(B->camera_coin), screen, &(B->positionCoin));


    SDL_Color couleur = {150, 0, 24};
    SDL_Rect postexte = {230 , 25 , 0 , 0};
    B->score++;
  char s[20];
  sprintf(s, "Score: %d", B->score);

  B->scores = TTF_RenderText_Blended(B->police, s, couleur);
  SDL_BlitSurface(B->scores, NULL, screen, &postexte);
}

void animerBack(Background *B)
{

    B->camera_coin.x= 99 * B->frame;

    
  if (B->frame == 5)
    B->frame = 0;

  B->frame++;
}

void scrolling(Background *B, SDL_Rect posPerso, int direction)
{
  const int speed = 10;

  if (direction == 1)// imin
  {
    if ((B->camera.x < 8192 - B->camera.w) && (posPerso.x >= 800))
    {
      B->camera.x = B->camera.x + speed;
    }
  }
  else if (direction == 0) //isar
  {
    if ((B->camera.x > 0) && (posPerso.x <= 800))
    {
      B->camera.x -= speed;
    }
  }
  else if ((direction == 3)&&(B->camera.y > 50)) //lfou9
  {
    B->camera.y -= speed;
  }
  else if ((direction == 2)&&(B->camera.y < 350)) //louta
  {

    B->camera.y += speed;
  }
  printf("X %d | Y %d \n",B->camera.x,B->camera.y);
  
}






void freeBackground(Background *B)
{
  // SDL_FreeSurface(B->BgImg);
  SDL_FreeSurface(B->vies);
  SDL_FreeSurface(B->scores);
  Mix_FreeMusic(B->music);
}

void sauvegarder(ScoreInfo s, char *file)
{
  FILE *f = fopen(file, "a");
  fprintf(f, "%s %d %d \n", s.name, s.score, s.time);
  fclose(f);
}

void bestScore(ScoreInfo s[], int n, char *file)
{
  int max1 = 0;

  int i;
  for (i = 0; i < n; i++)
  {
    if (s[i].score > max1)
      max1 = s[i].score;
  }

  int max2 = 0;
  for (i = 0; i < n; i++)
  {
    if ((s[i].score > max2) && (s[i].score != max1))
      max2 = s[i].score;
  }

  int max3 = 0;
  for (i = 0; i < n; i++)
  {
    if ((s[i].score > max3) && (s[i].score != max1) && (s[i].score != max2))
      max3 = s[i].score;
  }
}
