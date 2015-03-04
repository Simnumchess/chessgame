
#include "minmax_ab.h"
#include "position_echecs.h"

// variante alpha beta
/*
consiste à stopper l'exploration d'une branche qd:
à un niveau correspondant à une phase de maximisation, on trouve une valeur inférieure à une valeur minmax du niveau précédent
-----------------------------------------minimisation-----------------------supérieure--------------------------

*/


//rajouter double alpha, double beta

int minmax_ab(position_echecs &P, int profondeur){

cout<<"variante alpha beta"<<endl;

int a(0), b(0), i(0), max(-1000);// on met le max à -infini

if (profondeur<=0) return 0;

position_echecs *F=P.getPositionFille()
a=F[0].nbfilles;
cout <<"nombre de filles : "<<a<<endl;

//C'est à l'ordinateur de jouer donc position.getJoueur vaut soit ordinateur soit fin_partie

if (P.getJoueur==fin_partie) return P.val_pos;

else if(P.getJoueur==ordinateur) 

  for(i=0;i<a;i++)
  // on parcourt les positions filles, on applique minmax_min à leurs positions filles, et on prend le max
  {
    b=minmax_ab_min(F[i],profondeur-1);
    if(b>=max){
      max=b;
      cout<<"Le max est : "<<max<<endl;
      max_i=i;//indice du max
    }
    
  }

cout<<"la position fille à jouer est :"<<max_i<<endl

return max_i;

}

/*
minmax_min: on stoppe l'exploration qd
à un niveau correspondant à une phase de minimisation, on trouve une valeur superieure à une valeur minmax du niveau précédent
*/


int minmax_ab_min(position_echecs &P, int profondeur){
  cout<<"fonction min du minmax"<<endl;
  
  if (profondeur==0) return P.getvaleur;
  
  int min(1000), a(0), b(0), i(0);
  
  Position_echecs *F=P.getPositionFille()
  a=F[0].nbfilles;
  
  for(i=0;i<a;i++){ //on parcourt toutes les positions filles
    b=minmax_ab_max(F[i],profondeur-1); // on prend le min des minmax des filles
    if(b<=min){
      min=b;
      cout<<"Le min des positions filles est : "<<min<<endl;
    }
  }
  
  return min;
}

/*
minmax_max: on stoppe l'exploration qd
à un niveau correspondant à une phase de maximisation, on trouve une valeur inferieure à une valeur minmax du niveau précédent
*/

int minmax_ab_max(position_echecs &P, int profondeur){
  cout<<"fonction max du minmax"<<endl;
  
  if(profondeur==0) return P.getvaleur;
  
  int max(-1000), a(0), b(0), i(0);
  Position_echecs *F=P.getPositionFille()
  a=F[0].nbfilles;
  
  for(i=0;i<a;i++)
  {
    b=minmax_ab_min(F[i],profondeur-1);
    if(b>=max){
      max=b;
      cout<<"Le max des positions filles est : "<<max<<endl;
    }
  }

  return max;
}


