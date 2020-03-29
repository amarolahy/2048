#include "mylib.h"
#include "constantes.h"
#include "graphic.h"

extern Piece T[L][C] ;
extern Pos Tvide[L*C] ;
//extern Node *chaine ;

void initialise_data ()
{
    int i, j;
    for (i=0 ; i<L ; i++)
    {
        for (j=0 ; j<C ; j++)
        {
            T[i][j].data = 0;
        }
    }
}

void initialise_touch ()
{
    int i, j;
    for (i=0 ; i<L ; i++)
    {
        for (j=0 ; j<C ; j++)
        {
            T[i][j].touch = 0;
        }
    }
}

int recherche_vide ()
{
    int i, j, nb;
    Pos position ;

    nb = -1;
    for (i=0 ; i<L ; i++)
    {
        for (j=0 ; j<C ; j++)
        {
            if (T[i][j].data == 0)
            {
                nb++;
                position.x = i;
                position.y = j;
                Tvide[nb] = position;
            }
        }
    }

    return nb ;
}

void aleatoire (int nb)
{
    int c ;
    unsigned int a ;
    Pos position ;

    if (nb != -1)
    {
        if (nb != 0) c = rand() % nb ;
        else c = 0 ;
        a = rand() % 65535 ;
        position = Tvide[c] ;
        if (a%2==0 || a%3==0 || a%5==0 || a%7==0)
            T[position.x][position.y].data = 2;
        else
            T[position.x][position.y].data = 4;
    }
}

int verifie_bloque ()
{
    int i, j ;

    for (i=0 ; i<L-1 ; i++)
        for (j=0 ; j<C ; j++)
            if (T[i][j].data == T[i+1][j].data  || T[i+1][j].data == 0)
                return 0 ;

    for (j=0 ; j<C-1 ; j++)
        for (i=0 ; i<L ; i++)
            if (T[i][j].data == T[i][j+1].data || T[i][j+1].data == 0)
                return 0 ;

    return 1 ;
}

void quitter ()
{
   SDL_Quit() ;
   atexit(EXIT_SUCCESS);
}

/*void empiler()
{
    Node *p = NULL ;
    p = chaine ;
    chaine = malloc(sizeof(*chaine)) ;
    chaine->av = p ;
    (*chaine).T = T ;
}

void depiler()
{
    Node *p ;
    if (chaine->av != NULL)
    {
        T = chaine->T ;
        p = chaine->av ;
        free(chaine) ;
        chaine = p ;
    }
} */

int action (SDL_Surface *ecran, int *score)
{
    int i, j, h, bouge, statut ;
    SDL_Event event ;
    SDL_Rect position ;

    statut = 1 ;
    bouge=CONTINUER ;

    initialise_touch();
    while (statut)
    {
        SDL_WaitEvent(&event) ;
        switch(event.type)
        {
            case SDL_QUIT :
                statut = QUITTER ;
                bouge = QUITTER ;
                break;

            case SDL_KEYDOWN :
                switch (event.key.keysym.sym)
                {
                    case SDLK_UP :
                        for (i=0 ; i<C ; i++)
                        {
                            for (j=1 ; j<L ; j++)
                            {
                                h = j ;
                                while (h!=0 && T[h][i].data != 0 && T[h-1][i].data == 0)
                                {
                                    position.x = X + PAS*i ;
                                    position.y = Y + PAS*h ;
                                    //deplacer(ecran, position, i, h, HAUT) ;
                                    T[h-1][i].data = T[h][i].data ;
                                    T[h][i].data = 0 ;
                                    h-- ;
                                    bouge = BOUGE ;
                                }
                                if (h != 0)
                                if (T[h][i].data == T[h-1][i].data && T[h-1][i].touch == 0 && T[h-1][i].data != 0)
                                {
                                    position.x = X + PAS*i ;
                                    position.y = Y + PAS*h ;
                                    //deplacer(ecran, position, i, h, HAUT) ;
                                    T[h-1][i].data *= 2 ;
                                    *score += T[h-1][i].data ;
                                    T[h][i].data = 0 ;
                                    bouge = BOUGE ;
                                    T[h-1][i].touch = 1 ;
                                }
                            }
                        }
                        statut = QUITTER ;
                        break;

                    case SDLK_DOWN :
                        for (i=0 ; i<C ; i++)
                        {
                            for (j=(L-2) ; j>=0 ; j--)
                            {
                                h = j ;
                                while (h!=(L-1) && T[h][i].data != 0 && T[h+1][i].data == 0)
                                {
                                    position.x = X + PAS*i ;
                                    position.y = Y + PAS*h ;
                                    //deplacer(ecran, position, h, i, BAS) ;
                                    T[h+1][i].data = T[h][i].data ;
                                    T[h][i].data = 0 ;
                                    h++ ;
                                    bouge = BOUGE ;
                                }
                                if (h != (L-1))
                                if (T[h][i].data == T[h+1][i].data && T[h+1][i].touch == 0 && T[h+1][i].data != 0)
                                {
                                    position.x = X + PAS*i ;
                                    position.y = Y + PAS*h ;
                                    //deplacer(ecran, position, h, i, BAS) ;
                                    T[h+1][i].data *= 2 ;
                                    *score += T[h+1][i].data ;
                                    T[h][i].data = 0 ;
                                    bouge = BOUGE ;
                                    T[h+1][i].touch = 1 ;
                                }
                            }
                        }
                        statut = QUITTER ;
                        break ;

                    case SDLK_LEFT :
                        for (i=0 ; i<L ; i++)
                        {
                            for (j=1 ; j<C ; j++)
                            {
                                h = j ;
                                while (h!=0 && T[i][h].data != 0 && T[i][h-1].data==0)
                                {
                                    position.x = X + PAS*h ;
                                    position.y = Y + PAS*i ;
                                    //deplacer(ecran, position, i, h GAUCHE) ;
                                    T[i][h-1].data = T[i][h].data ;
                                    T[i][h].data = 0 ;
                                    h-- ;
                                    bouge = BOUGE ;
                                }
                                if (h!=0)
                                if (T[i][h].data==T[i][h-1].data && T[i][h-1].touch==0 && T[i][h-1].data != 0)
                                {
                                    position.x = X + PAS*h ;
                                    position.y = Y + PAS*i ;
                                    //deplacer(ecran, position, i, h GAUCHE) ;
                                    T[i][h-1].data *= 2 ;
                                    score += T[i][h-1].data ;
                                    T[i][h].data = 0 ;
                                    bouge = BOUGE ;
                                    T[i][h-1].touch = 1 ;
                                }
                            }
                        }
                        statut = QUITTER ;
                        break ;

                    case SDLK_RIGHT :
                        for (i=0 ; i<L ; i++)
                        {
                            for (j=C-1 ; j>=0 ; j--)
                            {
                                h = j ;
                                while (h!=C-1 && T[i][h].data != 0 && T[i][h+1].data==0)
                                {
                                    position.x = X + PAS*h ;
                                    position.y = Y + PAS*i ;
                                    //deplacer(ecran, position,i , h, DROITE) ;
                                    T[i][h+1].data = T[i][h].data ;
                                    T[i][h].data = 0 ;
                                    h++ ;
                                    bouge = BOUGE ;
                                }
                                if (h!=C-1)
                                if (T[i][h].data == T[i][h+1].data && T[i][h+1].touch == 0 && T[i][h+1].data != 0)
                                {
                                    position.x = X + PAS*h ;
                                    position.y = Y + PAS*i ;
                                    //deplacer(ecran, position, i, h, DROITE) ;
                                    T[i][h+1].data *= 2 ;
                                    score += T[i][h+1].data ;
                                    T[i][h].data = 0 ;
                                    bouge = BOUGE ;
                                    T[i][h+1].touch = 1 ;
                                }
                            }
                        }
                        statut = QUITTER ;
                        break ;


                    case SDLK_ESCAPE :
                        statut = QUITTER ;
                        bouge = QUITTER ;
                        break ;

                    case SDLK_r :
                        jouer(ecran) ;
                        statut = QUITTER ;
                        bouge = QUITTER ;
                        break ;

                    case SDLK_u :
//                        depiler() ;
                        actualiser(ecran) ;
                        bouge = CONTINUER ;
                        statut = QUITTER ;
                        break ;
                }
                break;
        }
    }
    return bouge ;
}

void jouer (SDL_Surface *ecran)
{
    int statut = 1, score, nombre, bloque, resultat, i, j, test=0 ;

    initialiser(ecran) ;

    while (statut)
    {
        bloque = verifie_bloque() ;
        if (!bloque)
        {
            resultat = action(ecran, &score);
            if (resultat == BOUGE)
            {
                nombre = recherche_vide() ;
                aleatoire(nombre) ;
                actualiser(ecran) ;
            }
            else if (resultat == QUITTER)
                statut = 0 ;
            else if (resultat == CONTINUER)
                statut = 1 ;
            for (i=0 ; i<L ; i++)
                for (j=0 ; j<C ; j++)
                    if (T[L][C].data == 2048){
                        test ++ ;
                        gagne(ecran, test) ;
                    }
        }
        else
        {
            gameover(ecran) ;
            statut = QUITTER ;
            pause() ;
        }
    }
}




























