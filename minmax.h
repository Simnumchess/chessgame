#ifndef MINMAX_H_INCLUDED
#define MINMAX_H_INCLUDED
#include "position_echecs.h"


int algo_minmax(position_echecs &P, int profondeur, int alpha, int beta);
int minmax(position_echecs &P, int profondeur, int alpha, int beta);
int Min(int a, int b);
int Max(int a, int b);


#endif // MINMAX_H_INCLUDED
