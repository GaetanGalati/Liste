#include <stdio.h>
#include <stdlib.h>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
typedef struct tVector2{

    int nX;
    int nY;

}tVector2;

typedef struct tActor tActor;
struct tActor
{
    SDL_Rect texture;
    tVector2 vect;
    int H;
    int W;
    tActor *suivant;

};

typedef struct Liste Liste;
struct Liste
{
    tActor *premier;
};

void insertion(Liste *liste, tActor Actor);
void suppression(Liste *liste);
void afficherListe(Liste *liste,tActor Player,tActor Monstre,SDL_Renderer *Renderer);

int main(int argc, char* argv[])
{

    Liste *maListe;
    tActor Player;
        Player.texture;
        Player.H = 50;
        Player.W = 50;
        Player.vect.nX = 385;
        Player.vect.nY = 150;

    tActor Monstre;
        Monstre.texture;
        Monstre.H=50;
        Monstre.W=50;
        Monstre.vect.nX = 100;
        Monstre.vect.nY = 200;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* screen = SDL_CreateWindow("WINDOWS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* Renderer=SDL_CreateRenderer(screen,-1,SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
    SDL_Event event;

    int repeat = 0;
    insertion(maListe, Player);
    insertion(maListe, Monstre);
    afficherListe(maListe,Player,Monstre,Renderer);
    suppression(maListe);
    while(!repeat)
    {

        SDL_PollEvent(&event);

        switch(event.type)
        {
            case SDL_QUIT:
            repeat = 1;
            break;
        }
    }
    SDL_DestroyWindow(screen);

    return 0;
}
void insertion(Liste *liste,  tActor Actor)
{
    /* Création du nouvel élément */
    tActor *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->H = Actor.H;
    nouveau->W = Actor.W;
    nouveau->vect.nX= Actor.vect.nX;
    nouveau->vect.nY = Actor.vect.nY;
    nouveau->texture = Actor.texture;

    /* Insertion de l'élément au début de la liste */
    //nouveau->H = liste->premier->H;
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}


void suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        tActor *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}


void afficherListe(Liste *liste,tActor Player,tActor Monstre,SDL_Renderer *Renderer){
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
        printf("Erreur !!! Errreurrrrr ALLERTE ! STOP ! NOOOOOON !");
    }
    SDL_SetRenderDrawColor(Renderer,100,100,100,10);

    SDL_RenderClear(Renderer);


    Player.texture.x=Player.vect.nX;
    Player.texture.y=Player.vect.nY;
    Player.texture.w=Player.W;
    Player.texture.h=Player.H;

    Monstre.texture.x=Monstre.vect.nX;
    Monstre.texture.y=Monstre.vect.nY;
    Monstre.texture.w=Monstre.W;
    Monstre.texture.h=Monstre.H;

    tActor *Playeractuel = liste->premier;

    SDL_SetRenderDrawColor(Renderer,0,255,0,100);

    SDL_RenderFillRect(Renderer,&Playeractuel->texture);



    tActor *EnemyActuel = liste->premier;

    SDL_SetRenderDrawColor(Renderer,255,0,0,100);

    SDL_RenderFillRect(Renderer,&EnemyActuel->texture);



    SDL_RenderPresent(Renderer);

    printf(" Player h : %d  Player w : %d Player y : %d Player z : %d-> "
                ,Playeractuel->H
                ,Playeractuel->W
                ,Playeractuel->vect.nX
                ,Playeractuel->vect.nY
            );

    printf("\n Monstre h : %d  Monstre w : %d Monstre y : %d Monstre z : %d-> "
                ,EnemyActuel->H
                ,EnemyActuel->W
                ,EnemyActuel->vect.nX
                ,EnemyActuel->vect.nY
            );

    printf("NULL\n");
}
