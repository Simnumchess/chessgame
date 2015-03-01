#ifndef MINMAX_H_INCLUDED
#define MINMAX_H_INCLUDED

int minmax(position &P, int profondeur); //minmax classique

int alpha_beta(position &P, int profondeur,int alpha, int beta); //variante alpha-beta

#endif // MINMAX_H_INCLUDED
