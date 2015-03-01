#ifndef MINMAX_H_INCLUDED
#define MINMAX_H_INCLUDED

//minmax classique
int minmax(Position &P, int profondeur);
int min(Position &P, int profondeur);//min à l'interieur du minmax
int max(Position &P, int profondeur);//max à l'interieur du minmax

//variante alpha-beta
int alpha_beta(Position &position, int profondeur,int alpha, int beta); 

#endif // MINMAX_H_INCLUDED
