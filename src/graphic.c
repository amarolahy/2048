#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "mylib.h"
#include "constantes.h"
#include "game.h"
#include "graphic.h"

extern Piece T[L][C] ;
extern Pos Tvide[L*C] ;
//extern Node *chaine ;

void initialiser (SDL_Surface *ecran)
{   /* ************* VAR ************** */
    SDL_Surface *fond = NULL, *carre = NULL, *score = NULL, *signature = NULL, *im2048 = NULL;
    SDL_Rect position ;
    Uint32 couleur_ecran ;
    int i, j, nombre ;

    /* ************* FIN VAR ************** */

    couleur_ecran = SDL_MapRGB(ecran->format, rand(), rand(), rand());  //vert
    SDL_FillRect(ecran, NULL, couleur_ecran);

    fond = IMG_Load("espace_jeu.png");
    position.x = X - INTER ;
    position.y = Y - INTER ;
    SDL_BlitSurface(fond, NULL, ecran, &position);

    initialise_data() ;

    carre = IMG_Load("0.png");
    for (i=0 ; i<C ; i++)
    {
        for (j=0 ; j<L ; j++ )
        {
            position.x = X + i*PAS ;
            position.y = Y + j*PAS ;
            SDL_BlitSurface(carre, NULL, ecran, &position);
        }
    }

    position.x = ecran->w - 110;
    position.y = ecran->h - 50;
    signature = IMG_Load("signature.bmp");
    SDL_SetColorKey(signature, SDL_SRCCOLORKEY, SDL_MapRGB(signature->format,255,255,255)) ;
    SDL_BlitSurface(signature, NULL, ecran, &position);

    im2048 = IMG_Load("2048.bmp");
    position.x = 0 ;
    position.y = 0 ;
    SDL_SetColorKey(im2048, SDL_SRCCOLORKEY, SDL_MapRGB(im2048->format,255,255,255)) ;
    SDL_BlitSurface(im2048, NULL, ecran, &position) ;

    for (i=0 ; i<2 ; i++)
    {
        nombre = recherche_vide() ;
        aleatoire(nombre) ;
        actualiser(ecran) ;
    }

    //chaine->av = NULL;
    //chaine->T[L][C] = T ;

    SDL_Flip(ecran) ;
}


void deplacer (SDL_Surface *ecran, SDL_Rect position, int x, int y, int sens)
{
    int i, j, depl ;
    SDL_Surface *obj = NULL , *fond = NULL , *carre = NULL, *temp = NULL;
    SDL_Rect place_temp, place, place_carre ;

    place = position ;

        temp = IMG_Load("espace_jeu.png") ;
        for (i=0 ; i<L ; i++)
            for (j=0 ; j<C ; j++)
            {
                    if (T[i][j].data == 0) carre = IMG_Load("0.png") ;
                    else if (T[i][j].data == 2) carre = IMG_Load("2.png") ;
                    else if (T[i][j].data == 4) carre = IMG_Load("4.png") ;
                    else if (T[i][j].data == 8) carre = IMG_Load("8.png") ;
                    else if (T[i][j].data == 16) carre = IMG_Load("16.png") ;
                    else if (T[i][j].data == 32) carre = IMG_Load("32.png") ;
                    else if (T[i][j].data == 64) carre = IMG_Load("64.png") ;
                    else if (T[i][j].data == 128) carre = IMG_Load("128.png") ;
                    else if (T[i][j].data == 256) carre = IMG_Load("256.png") ;
                    else if (T[i][j].data == 512) carre = IMG_Load("512.png") ;
                    else if (T[i][j].data == 1024) carre = IMG_Load("1024.png") ;
                    else if (T[i][j].data == 2048) carre = IMG_Load("2048.png") ;
                    else if (T[i][j].data == 4096) carre = IMG_Load("4096.png") ;
                    else if (T[i][j].data == 8192) carre = IMG_Load("8192.png") ;
                    else if (T[i][j].data == 16384) carre = IMG_Load("16384.png") ;

                    place_carre.x = INTER + j*PAS ;
                    place_carre.y = INTER + i*PAS ;
                    SDL_BlitSurface(carre, NULL, temp, &place_carre) ;
            }

    place_carre.x = INTER + x*PAS ;
    place_carre.y = INTER + y*PAS ;
    SDL_BlitSurface(IMG_Load("0.png"), NULL, temp, &place_carre) ;

    place_temp.x = X - INTER ;
    place_temp.y = Y - INTER ;
    SDL_BlitSurface(temp, NULL, ecran, &place_temp) ;
    SDL_Flip(ecran) ;

    pause() ;

    i=0 ;
    while (i<PAS)
    {
        if (T[x][y].data == 2) obj = IMG_Load("2.png") ;
        else if (T[x][y].data == 4) obj = IMG_Load("4.png") ;
        else if (T[x][y].data == 8) obj = IMG_Load("8.png") ;
        else if (T[x][y].data == 16) obj = IMG_Load("16.png") ;
        else if (T[x][y].data == 32) obj = IMG_Load("32.png") ;
        else if (T[x][y].data == 64) obj = IMG_Load("64.png") ;
        else if (T[x][y].data == 128) obj = IMG_Load("128.png") ;
        else if (T[x][y].data == 256) obj = IMG_Load("256.png") ;
        else if (T[x][y].data == 512) obj = IMG_Load("512.png") ;
        else if (T[x][y].data == 1024) obj = IMG_Load("1024.png") ;
        else if (T[x][y].data == 2048) obj = IMG_Load("2048.png") ;
        else if (T[x][y].data == 4096) obj = IMG_Load("4096.png") ;
        else if (T[x][y].data == 8192) obj = IMG_Load("8192.png") ;
        else if (T[x][y].data == 16384) obj = IMG_Load("16384.png") ;

        depl = 1 ;
        switch(sens)
        {
            case HAUT :
                place_carre.y-=depl;
                break ;
            case BAS :
                place_carre.y+=depl;
                break ;
            case GAUCHE :
                place_carre.x-=depl;
                break ;
            case DROITE :
                place_carre.x+=depl;
                break ;
        } i+=depl;

        SDL_BlitSurface(obj, NULL, temp, &place_carre) ;
        //SDL_Flip (ecran) ;
        place.x = X - INTER ;
        place.y = Y - INTER ;
        SDL_BlitSurface(temp, NULL, ecran, &place) ;
        SDL_Flip(ecran) ;

    }
}

void actualiser (SDL_Surface *ecran)
{
    int i, j ;
    SDL_Rect position ;
    SDL_Surface *obj, *fond ;

    fond = IMG_Load("espace_jeu.png");
    position.x = X - INTER ;
    position.y = Y - INTER ;
    SDL_BlitSurface(fond, NULL, ecran, &position);

    for (i=0 ; i<L ; i++)
    {
        for (j=0 ; j<C ; j++)
        {
            position.x = X + j*PAS ;
            position.y = Y + i*PAS ;

            if (T[i][j].data == 0) obj = IMG_Load("0.png") ;
            else if (T[i][j].data == 2) obj = IMG_Load("2.png") ;
            else if (T[i][j].data == 4) obj = IMG_Load("4.png") ;
            else if (T[i][j].data == 8) obj = IMG_Load("8.png") ;
            else if (T[i][j].data == 16) obj = IMG_Load("16.png") ;
            else if (T[i][j].data == 32) obj = IMG_Load("32.png") ;
            else if (T[i][j].data == 64) obj = IMG_Load("64.png") ;
            else if (T[i][j].data == 128) obj = IMG_Load("128.png") ;
            else if (T[i][j].data == 256) obj = IMG_Load("256.png") ;
            else if (T[i][j].data == 512) obj = IMG_Load("512.png") ;
            else if (T[i][j].data == 1024) obj = IMG_Load("1024.png") ;
            else if (T[i][j].data == 2048) obj = IMG_Load("2048.png") ;
            else if (T[i][j].data == 4096) obj = IMG_Load("4096.png") ;
            else if (T[i][j].data == 8192) obj = IMG_Load("8192.png") ;
            else if (T[i][j].data == 16384) obj = IMG_Load("16384.png") ;

            SDL_BlitSurface (obj, NULL, ecran, &position) ;

        }
    }
    SDL_Flip(ecran) ;
}

void gameover(SDL_Surface *ecran)
{
    SDL_Surface *fond = NULL, *over = NULL ;
    SDL_Rect position ;
    SDL_Event event, event1 ;
    int continuer = CONTINUER, continuer1 = CONTINUER ;

    position.x = X - INTER ;
    position.y = Y - INTER ;
    fond = IMG_Load("fond_over.bmp") ;
    SDL_SetColorKey(fond, SDL_SRCCOLORKEY, SDL_MapRGB(fond->format, 255, 255, 255)) ;
    SDL_SetAlpha(fond, SDL_SRCALPHA, 128) ;
    SDL_BlitSurface(fond, NULL, ecran, &position) ;

    over = IMG_Load("gameover.png") ;
    position.x = (ecran->w - over->w) / 2 ;
    position.y = ((Y - INTER + COTE_HAUT)) / 2 ;
    SDL_BlitSurface(over, NULL, ecran, &position) ;

    SDL_Flip(ecran) ;

    while (continuer)
    {
        SDL_WaitEvent(&event) ;
        switch(event.type)
        {
            case SDL_QUIT :
                continuer = QUITTER  ;
                quitter() ;
                break ;
            case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                    case SDLK_r :
                    jouer(ecran) ;
                    continuer = QUITTER ;
                    break ;

                    case SDLK_LALT :
                        while (continuer1)
                        {
                            SDL_WaitEvent(&event1) ;
                            switch (event1.type)
                            {
                                case SDL_KEYUP :
                                    switch (event1.key.keysym.sym)
                                    {
                                        case SDLK_LALT :
                                            continuer1 = QUITTER ;
                                            break ;
                                    }
                                    break ;

                                case SDL_KEYDOWN :
                                    switch (event1.key.keysym.sym)
                                    {
                                        case SDLK_F4 :
                                            quitter()  ;
                                            break ;
                                    }
                                    break ;
                            }
                        }
                        break ;
                }
                break ;
        }
    }

}

void gagne (SDL_Surface *ecran, int test)
{
    SDL_Surface *win = NULL , *fond_gagne = NULL;
    SDL_Rect position ;
    SDL_Event event, event1 ;
    int continuer = CONTINUER, continuer1 = CONTINUER ;
    int i, j ;
    if (test == 1) {
        fond_gagne = IMG_Load("fond_over.bmp") ;
        SDL_SetAlpha(fond_gagne, SDL_SRCALPHA, 128) ;
        position.x = X - INTER ;
        position.y = Y - INTER ;
        SDL_BlitSurface(fond_gagne, NULL, ecran, &position) ;

        win = IMG_Load("win.png") ;
        position.x = (ecran->w - win->w) / 2 ;
        position.y = (fond_gagne->h - win->h) / 2 + ECART_HAUT;
        SDL_BlitSurface(win, NULL, ecran, &position) ;

        SDL_Flip(ecran) ;

        while (continuer){
            SDL_WaitEvent(&event) ;
            switch(event.type)
            {
                case SDL_QUIT :
                    continuer = QUITTER  ;
                    actualiser(ecran) ;
                    break ;
                case SDL_KEYDOWN :
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_r :
                        jouer(ecran) ;
                        continuer = QUITTER ;
                        break ;

                        case SDLK_ESCAPE :
                            continuer = QUITTER ;
                            break ;

                        case SDLK_LALT :
                            while (continuer1)
                            {
                                SDL_WaitEvent(&event1) ;
                                switch (event1.type)
                                {
                                    case SDL_KEYUP :
                                        switch (event1.key.keysym.sym)
                                        {
                                            case SDLK_LALT :
                                                continuer1 = QUITTER ;
                                                break ;
                                        }
                                        break ;

                                    case SDL_KEYDOWN :
                                        switch (event1.key.keysym.sym)
                                        {
                                            case SDLK_F4 :
                                                quitter()  ;
                                                break ;
                                        }
                                        break ;
                                }
                            }
                            break ;
                    }
                    break ;
            }
        }
    }
}


