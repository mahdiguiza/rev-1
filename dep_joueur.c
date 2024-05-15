#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"
#include "background.h"
#include <SDL/SDL_mixer.h>
#include "tik.h"
#include "enemie.h"
#include "minimap.h"

#define SPEED 10 
#define JUMP_SPEED 12 
#define GRAVITY 0.6 
#define MAX_JUMPS 2 
#define TOTAL_FRAMES 12 

typedef struct {
    SDL_Rect position;
    SDL_Surface *sprites[2][TOTAL_FRAMES]; 
    int direction; 
    int frame; 
    int jumps;
    float jump_speed;
    int move_left;
    int move_right;
    int helth;
} Personnage;

void initializePersonnage(Personnage *perso) {
    perso->position.x = 100;
    perso->position.y = 435;
    perso->direction = 0;
    perso->frame = 0;
    perso->jumps = 0;
    perso->jump_speed = 0;
    perso->move_left = 0;
    perso->move_right = 0;
    perso->helth = 5;
}

void move(Personnage *p, int a)
{
    
    if (p->direction == 0) //mouvement a droite
    {
        if (p->position.x < 1000)
            p->position.x = p->position.x + a;
	    p->frame = (p->frame+1) % TOTAL_FRAMES;
    }

    else if (p->direction == 1) //mouvement a gauche
    {
        if (p->position.x > 450)
            p->position.x = p->position.x - a;
	    p->frame = (p->frame+1) % TOTAL_FRAMES;
    }
}

void loadSprites(SDL_Surface *perso[2][TOTAL_FRAMES]) {
    char filename[20];
    for (int i = 0; i < TOTAL_FRAMES; i++) {
        sprintf(filename, "perso/%d.png", i + 1);
        perso[0][i] = IMG_Load(filename); 

        sprintf(filename, "perso/r_%d.png", i + 1);
        perso[1][i] = IMG_Load(filename); 
    }

}

void freeSprites(SDL_Surface *perso[2][TOTAL_FRAMES]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < TOTAL_FRAMES; j++) {
            SDL_FreeSurface(perso[i][j]);
        }
    }
}   

int main(int argc, char** argv) {

 
	

    char filename[20];
    SDL_Surface *ecran = NULL;
    SDL_Surface *back = NULL, *chose = NULL, *texte = NULL , *vie5[5] ;
    Personnage perso , perso2;
    int speed = SPEED , score = 0;
    char scoreText[32] ;
    SDL_Color couleur = {150, 0, 24};
    SDL_Rect postexte = {230 , 25 , 0 , 0};
    SDL_Rect positionback = {0 , 0 , 0 , 0};
    int dex = 0;
    int direction = -1;



	minimap map;
    	initmap(&map);
    	SDL_Surface *mask;
	mask=IMG_Load("mask.png");

    Uint32 start;
    const int FPS = 35;
    
    int level = 1;
    int check=0;

    Background B;
    initBackground(&B, level);

    TTF_Font *police = TTF_OpenFont("arial.ttf", 40);
    if(police == NULL){
        printf("police invalide ");
    }

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Échec de l'initialisation de SDL : %s\n", SDL_GetError());
        exit(1);
    }
    
    ecran = SDL_SetVideoMode(1200, 680, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (ecran == NULL) {
        fprintf(stderr, "Échec de création de la fenêtre : %s\n", SDL_GetError());
        exit(1);
    }

    /*back = IMG_Load("BACKGGG.png");
    if (back == NULL) {
        fprintf(stderr, "Échec de chargement de l'image de fond : %s\n", SDL_GetError());
        exit(1);
    }*/

    chose = IMG_Load("chose.png");
    if (chose == NULL) {
        fprintf(stderr, "Échec de chargement de l'image de fond : %s\n", SDL_GetError());
        exit(1);
    }
    for (int i = 0; i < 6; i++)
    {
        sprintf(filename, "%dcoeur.png", i );
        vie5[i] = IMG_Load(filename);
    }

    loadSprites(perso.sprites);
    loadSprites(perso2.sprites);
    
    SDL_Rect position_back = {0, 0, 0, 0};
    affBackground(&B, ecran, level);
    afficherminimap(map, ecran);
    map.pos_joueur=MAJMinimap(perso.position,12,B.camera);
    SDL_Flip(ecran); 
	
	

    initializePersonnage(&perso);
    initializePersonnage(&perso2);

    Uint32 startTime = SDL_GetTicks(); 

    int quitter = 0;
    int chs = 0;
    int x,y;
    SDL_Event eventchose;
    SDL_BlitSurface(chose, NULL, ecran, NULL);
    while (!chs) {
        
        while (SDL_PollEvent(&eventchose)) {
            switch (eventchose.type) {
                case SDL_QUIT:
                    chs = 1;
                    quitter = 1;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    x = eventchose.button.x;
                    y = eventchose.button.y;
                    printf("(%d,%d)", x, y);
                    if (x >= 414 && x <= 535 && y >= 300 && y <= 500) {
                        chs = 1;

                    } else if (x >= 678 && x <= 784 && y >= 300 && y <= 490) {
                        chs = 1;
                        dex = 1;
                    }
                    break;
            }
        }
        SDL_BlitSurface(chose, NULL, ecran, NULL);
        SDL_Flip(ecran);
    }


    Ennemie ennemi;
    initEnnemi(&ennemi);
    afficherEnnemi(ennemi, ecran);
    afficherminimap(map, ecran);

    while (!quitter) {
        start = SDL_GetTicks();
        affBackground(&B, ecran, level);
        animerBack(&B);
        scrolling(&B, perso.position, direction);
        afficherminimap(map, ecran);
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            score++;
            switch (event.type) {
                case SDL_QUIT:
                    quitter = 1;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_LEFT:
                            direction = 0;
			    perso.direction=1;
                            break;
                        case SDLK_RIGHT:
                            direction = 1;
			    perso.direction=0;
                            break;
                        case SDLK_UP:
                            if (perso.jumps < MAX_JUMPS) { 
                                perso.jumps++;
                                perso.jump_speed = -JUMP_SPEED;
                            }
                            direction = 3;
                            break;
                        case SDLK_q:
                            perso2.move_left = 1;
                            perso2.direction = 1;
                            break;
                        case SDLK_d:
                            perso2.move_right = 1;
                            perso2.direction = 0; 
                            break;
                        case SDLK_z:
                            if (perso2.jumps < MAX_JUMPS) { 
                                perso2.jumps++;
                                perso2.jump_speed = -JUMP_SPEED;
                            }
                            break;
                        case SDLK_e:
                            speed += 15;
                            break;
                        case SDLK_l:
                            perso.helth --;
                            break;
                        case SDLK_k:
                            perso.helth ++;
                            break;
                        default:
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_LEFT:
                            direction = 11;
                            break;
                        case SDLK_RIGHT:
                            direction = 11;
                            break;
                        case SDLK_q:
                            perso2.move_left = 0;
                            break;
                        case SDLK_d:
                            perso2.move_right = 0;
                            break;
                        case SDLK_e:
                            speed -= 15;
                            break;

                        default:
                            break;  
                    }
                    break;
            }

            
            

        
        }
        /*if(detect_collision_ennemie(&perso.position, &ennemi) == 0){
            perso.helth--;
            perso.position.x -= 100;
        }*/
	
	if (collision(ennemi.pos_ennemie,perso.position)==1)
	{
		perso.helth--;
	}
	
        if(B.camera.x >= 6999){
            quitter = 1;
        }
        
        //update_ennemie(&ennemi, &perso);
        animer_ennemi(&ennemi);
	deplacerIA(&ennemi,perso.position);

switch(direction){
	case 0:
	if (collisionPP_droite(perso.position, mask, B.camera) == 0) {
		move(&perso,10);
        	
		
	}
	scrolling(&B, perso.position, 0);
	break;
	case 1:
	if (collisionPP_gauche( perso.position, mask, B.camera)==0)
	{
		move(&perso,10);	
        	
	}
	scrolling(&B, perso.position, 1);
	break;
	
}





        if (perso.jumps > 0) {
            perso.position.y += perso.jump_speed * 1; 
            
            perso.jump_speed += GRAVITY * (1000 / 1000.0); 
            if (perso.position.y >=435) { 
                perso.position.y = 435;
 
                perso.jumps = 0; 
                perso.jump_speed = 0; 
            }
        }

        if (perso2.move_left) {
            perso2.position.x -= speed;
            perso2.frame = (perso2.frame + 1) % TOTAL_FRAMES;
        }
        if (perso2.move_right) {
            if (perso2.position.x <= 600) {
                perso2.position.x += speed;
            }
            perso2.frame = (perso2.frame + 1) % TOTAL_FRAMES; 
        }

        if (perso2.jumps > 0) {
            perso2.position.y += perso2.jump_speed * 1; 
            perso2.jump_speed += GRAVITY * (1000 / 1000.0); 
            if (perso2.position.y >= 435) { 
                perso2.position.y = 435;
                perso2.jumps = 0; 
                perso2.jump_speed = 0; 
            }
        }

        affBackground(&B, ecran, level);
    	afficherminimap(map, ecran);
        animerBack(&B);
        SDL_BlitSurface(back, NULL, ecran, &positionback);
        if(dex == 1){
            SDL_BlitSurface(perso2.sprites[perso2.direction][perso2.frame], NULL, ecran, &perso2.position); 
        }
        
        SDL_BlitSurface(perso.sprites[perso.direction][perso.frame], NULL, ecran, &perso.position); 
        afficherEnnemi(ennemi, ecran);
        
        SDL_BlitSurface(vie5[perso.helth], NULL, ecran, NULL);
        SDL_Flip(ecran);
        SDL_Delay(20);

        Uint32 elapsedTime = SDL_GetTicks() - startTime;

        if (elapsedTime < 1000 / 120) { 
            SDL_Delay((1000 / 120) - elapsedTime);
        }

        startTime = SDL_GetTicks(); 
    }

    enigme e;
            SDL_Event event;
            int boucle = 1;
                int interface=4; //interface=4 si enigme;
                SDL_WM_SetCaption("ENIGME", NULL);

            initialiserEnigme(&e);
            genererEnigme(&e);
            printf("%d",e.ReponseCorrecte);
            Mix_PlayMusic(e.musique_enigme, -1);
            while (boucle==1)
            {
                        if(interface==4) //interface de l'enigme
                        { 
                    animerEnigme(&e);
                    afficherEnigme(e,ecran);
                        }
                if(interface==5) //interface dans le cas de victoire
                {
                    interface_win(ecran,&boucle,e);
                }
                if(interface==6) //interface dans le cas de l'echec
                {
                    interface_lose(ecran,&boucle,e);
                }
                while (SDL_PollEvent(&event))
                {
                    switch (event.type)
                    {
                        case SDL_QUIT :
                            boucle = 0;
                            break;
                        case SDL_KEYDOWN:
                        {
                            switch (event.key.keysym.sym)
                            {
                                case SDLK_ESCAPE :
                                    boucle = 0;
                                    break;
                                case SDLK_q :
                                    if (e.ReponseCorrecte==0) interface=5;
                                    else interface=6;
                                    break;
                                case SDLK_a :
                                    if (e.ReponseCorrecte==1) interface=5;
                                    else interface=6;
                                    break;
                                case SDLK_z :
                                    if (e.ReponseCorrecte==2) interface=5;
                                    else interface=6;
                                    break;
                                case SDLK_e :
                                    if (e.ReponseCorrecte==3) interface=5;
                                    else interface=6;
                                    break;
                                case SDLK_r :
                                    if (e.ReponseCorrecte==4) interface=5;
                                    else interface=6;
                                    break;
                                case SDLK_t :
                                    if (e.ReponseCorrecte==5) interface=5;
                                    else interface=6;
                                    break;
                                case SDLK_y:
                                    if (e.ReponseCorrecte==6) interface=5;
                                    else interface=6;
                                    break;
                                case SDLK_u :
                                    if (e.ReponseCorrecte==7) interface=5;
                                    else interface=6;
                                    break;
                                case SDLK_i :
                                    if (e.ReponseCorrecte==8) interface=5;
                                    else interface=6;
                                    break;
                                case SDLK_o :
                                    if (e.ReponseCorrecte==9) interface=5;
                                    else interface=6;
                                    break;
                                
                            }

                        }
                    } 
                }
		
                SDL_Flip(ecran);
                SDL_Delay(40);
            }
            freeEnigme(e);
    jouer_jeu (ecran);

    freeSprites(perso.sprites);
    freeBackground(&B);
    SDL_FreeSurface(back);
    SDL_FreeSurface(map.img_map);
    SDL_FreeSurface(map.img_joueur);
    SDL_FreeSurface(mask);
    SDL_Quit();

    return 0;
}
    
