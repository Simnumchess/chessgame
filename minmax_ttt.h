#ifndef MINMAX_TTT_H_INCLUDED
#define MINMAX_TTT_H_INCLUDED
#include "position_ttt.h"


int algo_minmax_ttt(position_ttt &P);
int minmax_ttt(position_ttt &P, int alpha, int beta);
int Min(int a, int b);
int Max(int a, int b);


#endif // MINMAX_H_INCLUDED
