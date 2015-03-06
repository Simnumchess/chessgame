#include "minmax.h"
#include "position_echecs.h"

//rajouter double alpha, double beta

int minmax(position_echecs &P, int profondeur){

int a(0), b(0), i(0), max(-1000);// on met le max à -infini

if (profondeur<=0) return 0;

Position_echecs *F=P.getPositionFille()
a=F[0].nbfilles;
cout <<"nombre de filles : "<<a<<endl;

//C'est à l'ordinateur de jouer donc position.getJoueur vaut soit ordinateur soit fin_partie

if (P.getJoueur==fin_partie) return P.val_pos;

else if(P.getJoueur==ordinateur) 

  for(i=0;i<a;i++)
  // on parcourt les positions filles, on applique minmax_min à leurs positions filles, et on prend le max
  {
    b=minmax_min(F[i],profondeur-1);
    if(b>=max){
      max=b;
      cout<<"Le max est : "<<max<<endl;
      max_i=i;//indice du max
    }
    
  }

cout<<"la position fille à jouer est :"<<max_i<<endl

return max_i;

}




int minmax_min(position_echecs &P, int profondeur){
  cout<<"fonction min du minmax"<<endl;
  
  if (profondeur==0) return P.getvaleur;
  
  int min(1000), a(0), b(0), i(0);
  
  Position_echecs *F=P.getPositionFille()
  a=F[0].nbfilles;
  
  for(i=0;i<a;i++){
    b=minmax_max(F[i],profondeur-1);
    if(b<=min){
      min=b;
      cout<<"Le min des positions filles est : "<<min<<endl;
    }
  }
  
  return min;
}


int minmax_max(position_echecs &P, int profondeur){
  cout<<"fonction max du minmax"<<endl;
  
  if(profondeur==0) return P.getvaleur;
  
  int max(-1000), a(0), b(0), i(0);
  Position_echecs *F=P.getPositionFille()
  a=F[0].nbfilles;
  
  for(i=0;i<a;i++)
  {
    b=minmax_min(F[i],profondeur-1);
    if(b>=max){
      max=b;
      cout<<"Le max des positions filles est : "<<max<<endl;
    }
  }

  return max;
}


int minmax_alpha_beta(Position_echecs &P, int profondeur,int alpha, int beta)

