#ifndef MINMAX_TTT_H_INCLUDED
#define MINMAX_TTT_H_INCLUDED
#include "position_ttt.h"

//minmax_ttt classique
int minmax_ttt(position_ttt &P, int profondeur);
int minmax_ttt_min(position_ttt &P, int profondeur);//min à l'interieur du minmax
int minmax_ttt_max(position_ttt &P, int profondeur);//max à l'interieur du minmax


#endif // MINMAX_TTT_H_INCLUDED

