#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#include "mylib.h"
#include "constantes.h"
#include "game.h"
#include "graphic.h"

/****** TYPES *********/
//Listes chainé
typedef struct maillon Maillon;
struct maillon
{
    int data;
    Maillon *suiv;
};


/***** TABLEAUX *******/

double somme_tab (double t[], int taille);
double moyenne_tab (double t[], int taille);
void tri_croissant (double t[], int taille);
void tri_decroissant (double t[], int taille);
void affiche_tab1 (double t[], int taille, char nom[]);


/****** ENTREES / SORTIES ******/


/***** SDL ******** */
void pause() ;



#endif // MYLIB_H_INCLUDED
