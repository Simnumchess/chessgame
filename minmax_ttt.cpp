#include <iostream>
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "minmax_ttt.h"
#include "position_ttt.h"


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



int algo_minmax_ttt(position_ttt &P){
    
    int alpha=-1000;
    int beta=1000;
    //On génere les positions filles (positions que peut jouer l'ordinateur)
    position_ttt *F=P.get_pos_suiv(P);
    int a=P.ttt_ref.nb_casesvides();
    cout <<"nombre de possibilités pour l'ordinateur : "<<a<<endl;
    int max=-1000;
    int indice_position_fille=0;
    
    //C'est à l'ordinateur de jouer donc on prend le max des positions filles (positions que peut jouer l'ordinateur)
    for(int i=0; i<a;i++){
        int val=minmax_ttt(F[i],alpha,beta);
        if(val>max){
            max=val;
            indice_position_fille=i;
        }
    }
    
    return indice_position_fille;
    //maintenant il faut jouer cette position fille !
}



int minmax_ttt(position_ttt &P, int alpha, int beta){
    
    cout<<"minmax classique"<<endl;
    
    

    //On génere les positions filles
    position_ttt *F=P.get_pos_suiv(P);
    int a=P.ttt_ref.nb_casesvides();
    
    
    if (P.fin_partie()=='X') return 0;
    else if(P.fin_partie()=='O') return 100;
        
    
    else if(P.getJoueur()=="ordinateur")
    {
        int max=-1000;
        for(int i=0;i<a;i++)// on parcourt les positions filles
        {
            max=Max(max,minmax_ttt(F[i], alpha, beta));
        }
        return max;
    }
    else if (P.getJoueur()=="humain")
    {
        int min=1000;
        for(int i=0;i<a;i++)// on parcourt les positions filles
        {
            min=Min(min,minmax_ttt(F[i], alpha, beta));
        }
        return min;
    }
    return 0;
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

