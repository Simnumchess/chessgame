#ifndef MINMAX_H_INCLUDED
#define MINMAX_H_INCLUDED

int minmax(Position &position, int profondeur); //minmax classique

int alpha_beta(Position &position, int profondeur,int alpha, int beta); //variante alpha-beta

#endif // MINMAX_H_INCLUDED
