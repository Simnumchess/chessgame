#ifndef MINMAX_H_INCLUDED
#define MINMAX_H_INCLUDED

// rajouter double alpha, double beta

//minmax classique
int minmax(Position_echecs &P, int profondeur);
int minmax_min(Position_echecs &P, int profondeur);//min à l'interieur du minmax
int minmax_max(Position_echecs &P, int profondeur);//max à l'interieur du minmax


#endif // MINMAX_H_INCLUDED
