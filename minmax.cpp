
#include "minmax.h"
#include "position_echecs.h"


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



int algo_minmax (position_echecs &P, int profondeur, int a, int b){
   
   //On génere les positions filles (positions que peut jouer l'ordinateur)
   position_echecs *F=P.get_pos_suiv(P);
   int a=P.nbcoup(P);
   cout <<"nombre de possibilités pour l'ordinateur : "<<a<<endl;
   int max=-1000;
   int indice_position_fille=0;

//C'est à l'ordinateur de jouer donc on prend le max des positions filles (positions que peut jouer l'ordinateur)
   for(int i=0; i<a;i++){
         int val=minmax(F[i],profondeur,alpha,beta, a,b);
         if(val>max){
            max=val;
            indice_position_fille=i;
         }
   }
   
   return indice_position_fille;
   //maintenant il faut jouer cette position fille !
}



int minmax(position_echecs &P, int profondeur, int a, int b){

cout<<"minmax classique"<<endl;

if(profondeur<0) {cout<<"probleme avec la profondeur"<<endl;}


if (profondeur==0) return P.getvaleur(P);

//On génere les positions filles
position_echecs *F=P.get_pos_suiv(P)
int a=P.nbcoup(P);


if (P.Jeu_pos==fin_partie) return P.getvaleur(P);

else if(P.Jeu_pos==ordinateur)
{ 
  int max=-1000;
  for(int i=0;i<a;i++)// on parcourt les positions filles
  {
      max=Max(max,minmax(F[i], profondeur-1, a, b));
  }
}
else if (P.Jeu_pos==humain)
{
   int min=1000;
  for(int i=0;i<a;i++)// on parcourt les positions filles
  {
      min=Min(min,minmax_ab(F[i], profondeur-1, a, b));
  }
}

}



int Min(int a, int b){
  int min=0;
  if (a>b) min=b;
  else min=a;
  return min;
}



int Max(int a, int b){
   int max=0;
   if(a>b) max=a;
   else max=b;
  return max;
}

