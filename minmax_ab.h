
#ifndef MINMAX_AB_H_INCLUDED
#define MINMAX_AB_H_INCLUDED
#include "position_echecs.h"

// rajouter double alpha, double beta

//minmax classique
int minmax_ab(position_echecs &P, int profondeur, int alpha, int beta);
int minmax_ab_min(position_echecs &P, int profondeur, int alpha, int beta);//min à l'interieur du minmax
int minmax_ab_max(position_echecs &P, int profondeur, int alpha, int beta);//max à l'interieur du minmax


#endif // MINMAX_AB_H_INCLUDED
