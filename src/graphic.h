#ifndef GRAPHIC_H_INCLUDED
#define GRAPHIC_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "mylib.h"
#include "constantes.h"
#include "game.h"
#include "graphic.h"

void initialiser (SDL_Surface *ecran) ;
void deplacer (SDL_Surface *ecran, SDL_Rect position, int x, int y, int sens) ;
void actualiser (SDL_Surface *ecran) ;
void gameover(SDL_Surface *ecran) ;
void gagne (SDL_Surface *ecran, int test) ;

#endif // GRAPHIC_H_INCLUDED
