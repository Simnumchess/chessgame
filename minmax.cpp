#include "minmax.h"
#include "position.h"

int generation



int minmax(Position &P, int profondeur){

int a(0), b(0), i(0), max(-1000);

if (profondeur<=0) return 0;

Position *F=P.getPositionFille()
a=F[0].nbfilles;
cout <<"nombre de filles : "<<a<<endl;

//C'est à l'ordinateur de jouer donc position.getJoueur vaut soit ordinateur soit fin_partie

if (P.getJoueur==fin_partie) return P.val_pos;

else if(P.getJoueur==ordinateur) 

  for(i=0;i<a;i++){
    
    b=minmax_min(F[i],profondeur-1);
    if(b>=max){
      
      max=b;
      cout<<"Le max est : "<<max<<endl;
      max_i=i;
      
    }
    
  }

cout<<"la position fille à jouer est :"<<max_i<<endl

return max_i;

}




int minmax_min(Position &P, int profondeur){
  cout<<"fonction min du minmax"<<endl;
  
  if (profondeur==0) return P.getvaleur;
  
  int min(1000), a(0), b(10), c(0), i(0);
  
  Position *F=P.getPositionFille()
  a=F[0].nbfilles;
  
  
  return min;
}


int minmax_max(Position &P, int profondeur){
  cout<<"fonction max du minmax"<<endl;
  
  if(profondeur==0) return P.getvaleur;
  
  int max(-1000), a(0), b(10), c(0), i(0);
  Position *F=P.getPositionFille()
  a=F[0].nbfilles;

  return max;
}



// variante alpha beta
int alpha_beta(Position &P, int profondeur,int alpha, int beta){

}

