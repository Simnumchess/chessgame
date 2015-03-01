#include "minmax.h"
#include "position.h"

int generation



int minmax(Position &P, int profondeur){

int a(0), i(0), b(0);

if (profondeur<=0) return 0;

Position *F=P.getPositionFille()
a=F[0].nbfilles;
cout <<"nombre de filles : "<<a<<endl;

//C'est à l'ordinateur de jouer donc position.getJoueur vaut soit ordinateur soit fin_partie

if (P.getJoueur==fin_partie) return P.val_pos;

else if(P.getJoueur==ordinateur) 

  for(i=0;i<a;i++){
    b=Min(F[i],profondeur-1)
    
  }

return 0;


}



int min(Position &P, int profondeur);

int max(Position &P, int profondeur);



// variante alpha beta
int alpha_beta(Position &P, int profondeur,int alpha, int beta){

}

