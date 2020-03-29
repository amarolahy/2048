#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "mylib.h"
#include "constantes.h"
#include "game.h"
#include "graphic.h"

void initialise_data ();
void initialise_touch ();
int recherche_vide ();
void aleatoire (int nb) ;
int verifie_bloque ();
void quitter () ;
int action (SDL_Surface *ecran, int *score) ;
void jouer (SDL_Surface *ecran) ;

#endif // GAME_H_INCLUDED
