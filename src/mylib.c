#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "mylib.h"
#include "constantes.h"
#include "game.h"
#include "graphic.h"

double somme_tab (double t[], int taille)
{
    int i=0;
    double somme=0.0;
    for (i=0 ; i<taille ; i++)
    {
        somme += t[i];
    }
    return somme;
}

double moyenne_tab (double t[], int taille)
{
    double moyenne;
    moyenne = somme_tab (t, taille);
    return (moyenne / taille);
}

void tri_croissant (double t[], int taille)
{
    int i, j ;
    double petit;
    if  (taille > 0)
    {
        printf("taille : %d\n", taille);
        printf("adresse du tableu %p", t);
        for (i=0 ; i<(taille-1) ; i++)
        {
            petit = t[i];
            for (j=(i+1) ; j<taille ; j++ )
            {
                if (t[j] < petit)
                {
                    petit = t[j];
                    t[j] = t[i];
                    t[i] = petit;
                }
            }
        }
    }
    else
    {
        printf("Tableau de taille incorect");
    }
}

void tri_decroissant (double t[], int taille)
{
    int i, j ;
    double grand ;
    if (taille > 0)
    {
        for (i=0 ; i<taille-1 ; i++)
        {
            grand = t[i];
            for (j=i+1 ; j<taille ; j++)
            {
                if (t[j]>grand)
                {
                    grand = t[j];
                    t[j] = t[i];
                    t[i] = grand;
                }
            }
        }
    }
    else
    {
        printf("Tableau de taille incorect");
    }
}

void affiche_tab1 (double t[], int taille, char nom[])
{
    int i;
    if (nom == NULL)
    {
        for (i=0 ; i<taille; i++)
            printf("%.3f\n", t[i]);
    }
    else
        for (i=0 ; i<taille; i++)
            printf("%s[%d] = %.3f\n",nom,i+1, t[i]);
}

void met_a_n (double t[], int taille, int n)
{
    int i;
    for (i=0 ; i<taille ; i++)
        t[i] = n;
}

void pause()
{
    int continuer = 1;
    SDL_Event event;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
    }
}


