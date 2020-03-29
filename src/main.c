#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "mylib.h"
#include "constantes.h"
#include "game.h"
#include "graphic.h"

Piece T[L][C] ;
Pos Tvide[L*C] ;
//Node *chaine ;

int main (int argc, char** argv)
{
    /* Variables */
    SDL_Surface *ecran = NULL;
    Uint32 couleur_ecran ;
    SDL_Rect position ;

    /* Fin variables */

    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr,"Erreur lors du chargement de la SDL : %s\n",SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_WM_SetIcon(IMG_Load("icone.bmp"), NULL);
    ecran = SDL_SetVideoMode(WEIGHT, HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (ecran == NULL)
    {
        fprintf(stderr,"Erreur lors du chargement du mode Video : %s\n", SDL_GetError()) ;
        return EXIT_FAILURE ;
    }
    srand(time(NULL)) ;
    couleur_ecran = SDL_MapRGB(ecran->format, rand(), rand(), rand());  //vert
    SDL_FillRect(ecran, NULL, couleur_ecran);
    SDL_WM_SetCaption("My 2048 by J.SAM", NULL);


    jouer (ecran) ;

    SDL_Quit() ;
    return EXIT_SUCCESS;
}
