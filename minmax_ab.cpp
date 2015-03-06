
#include "minmax_ab.h"
#include "position_echecs.h"

// variante alpha beta
/*
consiste à stopper l'exploration d'une branche qd:
à un niveau correspondant à une phase de maximisation, on trouve une valeur inférieure à une valeur minmax du niveau précédent
-----------------------------------------minimisation-----------------------supérieure--------------------------

*/

/*fonction ALPHABETA(P, alpha, beta) / alpha est toujours inférieur à beta 
   si P est une feuille alors
       retourner la valeur de P
   sinon
       si P est un nœud Min alors
           Val = infini
           pour tout enfant Pi de P faire
               Val = Min(Val, ALPHABETA(Pi, alpha, beta))                
               si alpha ≥ Val alors  / coupure alpha /
                   retourner Val
               finsi    
               beta = Min(beta, Val)
           finpour            
       sinon
           Val = -infini
           pour tout enfant Pi de P faire
               Val = Max(Val, ALPHABETA(Pi, alpha, beta))                
               si Val ≥ beta alors / coupure beta /
                   retourner Val
               finsi   
               alpha = Max(alpha, Val)
           finpour
       finsi
   retourner Val
   finsi
fin
*/



int minmax_ab(position_echecs &P, int profondeur, int alpha, int beta){

cout<<"variante alpha beta"<<endl;

if (alpha>beta)
{
   cout<<"alpha doit être inférieur à beta"<<endl;
}

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
    b=minmax_ab_min(max,minmax_ab(F[i], profondeur-1, alpha, beta));
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


int minmax_ab_min(int a, int b){
  int min=0;
  if (a>b) min=b;
  else min=a;
  return min;
}

/*
minmax_max: on stoppe l'exploration qd
à un niveau correspondant à une phase de maximisation, on trouve une valeur inferieure à une valeur minmax du niveau précédent
*/

int minmax_ab_max(int a, int b){
   int max=0;
   if(a>b) max=a;
   else max=b;
  return max;
}


