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

if(profondeur<0) cout<<"probleme avec la profondeur"<<endl;

if (alpha>beta)
{
   cout<<"alpha doit être inférieur à beta"<<endl;
}


if (profondeur==0) return P.val_pos;

int val=0;

position_echecs *F=P.getPositionFille()
int a=F[0].nbfilles;
cout <<"nombre de filles : "<<a<<endl;

//C'est à l'ordinateur de jouer donc position.getJoueur vaut soit ordinateur soit fin_partie

if (P.getJoueur==fin_partie) return P.val_pos;

else if(P.getJoueur==ordinateur)
{ 
  max=-1000;
  for(i=0;i<a;i++)// on parcourt les positions filles
  {
      max=Max(max,minmax_ab(F[i], profondeur-1, alpha, beta))
      if (max>=beta) return max; //coupure beta
      else alpha=Max(alpha,max);
  }
}
else if (P.getJoueur==humain)
{
   min=1000;
  for(i=0;i<a;i++)// on parcourt les positions filles
  {
      min=Min(min,minmax_ab(F[i], profondeur-1, alpha, beta))
      if (min<=beta) return min; //coupure alpha
      else beta=Min(beta,min);
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

