#ifndef MINMAX_H_INCLUDED
#define MINMAX_H_INCLUDED
#include "position_echecs.h"
#include "definition.h"

// rajouter double alpha, double beta

//minmax classique
int minmax(position_echecs &P, int profondeur);
int minmax_min(position_echecs &P, int profondeur);//min à l'interieur du minmax
int minmax_max(position_echecs &P, int profondeur);//max à l'interieur du minmax


#endif // MINMAX_H_INCLUDED
