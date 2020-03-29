#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#include "mylib.h"
#include "game.h"
#include "graphic.h"

#define L 4
#define C 4

#define TAILLE_BLOC 60
#define INTER 6
#define ECART_COTE 50
#define ECART_BAS 60
#define ECART_HAUT 175
#define COTE_HAUT (TAILLE_BLOC*L + (L+1)*INTER)           // hauter espace de jeu              275
#define COTE_LARG (TAILLE_BLOC*C + (C+1)*INTER)           // largeur espace de jeu             275
#define HEIGHT (ECART_HAUT + COTE_HAUT + ECART_BAS )        // hauteur fenetre
#define WEIGHT (2*ECART_COTE + COTE_LARG)                   // largeur fenetre
#define X (((ecran->w - COTE_LARG) / 2) + INTER)          /* Abscisse X du premier bloc */
#define Y ((ecran->h - COTE_HAUT - ECART_BAS ) + INTER)   /* Ordonnée Y du premier bloc */
#define PAS (TAILLE_BLOC + INTER)



enum{HAUT, BAS, GAUCHE, DROITE};
enum{QUITTER = 0, CONTINUER, BOUGE};

typedef struct pos Pos ;
struct pos
{
    int x;
    int y;
};

typedef struct piece Piece;
struct piece
{
    int data;
    int touch ;
};

typedef struct node Node ;
struct node
{
    Piece T[L][C] ;
    Node *av;
};


#endif // CONSTANTES_H_INCLUDED
