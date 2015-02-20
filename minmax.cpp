#include "minmax.h"
#include "position.h"

int generation



int minmax(Position position){

if (position.getJoueur==fin_partie) return position.val_pos;

else if (position.getJoueur==humain) max();

else if (position.getJoueur==ordinateur) min();

else return 0;

}



int min();

int max();

// variante alpha beta
int alpha_beta(int profondeur,int alpha, int beta){

}

