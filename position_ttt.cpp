#include "position.h"
#include "piece.h"
#include "position_ttt.h"
#include "ttt.h"
#include "coup.h"
#include "minmax_ttt.h"
#include <ostream>
#include <iostream>
using namespace std;

position_ttt::~position_ttt() // destructeur de toutes les positions filles
{
    if((pos_fille!=NULL)||(pos_soeur!==NULL))
    delete []pos_fille;
    delete []pos_soeur;
}



position_ttt* position_ttt::get_pos_suiv()
{
    position_ttt* pos_fille=new position_ttt[100]; //un tableau de position fille
    int n=0;
    if(Jeu_pos==humain) //si le humain joue
    {
        for(int l=0;l<8;l++)
        {
            for(int c=0;c<8;c++)
            {
                if((ttt_ref.ttttab[l][c]!=0)&&(echiquier_ref.ehectab[l][c].col==blanc))
                //coup possible??
                //class coup: piece_jouee;piece_mangee;coordonnee avant le coup;coordonnee apres le coup;bool coup_possible()
                coup C;
                C.piece_jouee=ttt_ref.ttttab[l][c];
                if(bool coup_possible(coup C)==true)
                {
                    pos_fille[n]=position_ttt(*this);
                    if(Jeu_pos==humain)
                    {
                        pos_fille[n].Jeu_pos==ordinateur;
                    }
                    else
                    {
                        pos_fille[n].Jeu_pos==humain;
                    }
                    n++;
                }
                
                
                
            }
        }
        return pos_fille;
    }
    else if(Jeu_pos==ordinateur) //si l'ordinateur joue
    {
        for(int l=0;l<8;l++)
        {
            for(int c=0;c<8;c++)
            {
                if(ttttab[l][c]!=0)
                //coup possible??
                
            }
        }
        return pos_fille;
    }
}



int position_ttt::resultat() const
{// à refaire pour le ttt
    if(coup_joue.piece_mangee.type_piece==Roi)
    {
        if(coup_joue.piece_mangee.col==blanc)
        {
            
            cout<<"You lose";
            return mini;
            else 
            cout<<"You win";
            return maxi;
            
        }
    }
    
    else return 0;
    cout<<"Please continue..."
}


position_ttt & position_ttt::explorer() //explorer 4 coups(2 par joueurs)
{
    int l1,l2,c1,c2=0;
    //explorer les coups
    coup cp=coup();
    cp.piece_jouee=ttt_ref[l1][c1];
    cp.ligne_init=l1;
    cp.colone_init=c1;
    cp.ligne_final=l2;
    cp.colone_final=c2;
    cp.col=ttt_ref.ttttab[l1][c1].col;
    
}


position_ttt position_ttt::maj() //mise a jour de l'echiquier de reference apres les coups jouees
{
    //coup possible
}



position_ttt & position_ttt::operator=(const position_ttt & p) //operateur = pour une position_ttt
{
    if(this==&p) 
    return *this;
    else 
    {
        ttt_ref=p.ttt_ref;
        coup_joue=p.coup_joue;
        coup_historique=p.coup_historique;
        pos_fille=p.pos_fille;
        pos_soeur=p.pos_soeur;
        return *this;
    }
}
position_ttt::position_ttt(const position_ttt & p) //operateur par copie
{
    ttt_ref=p.ttt_ref;
    coup_joue=p.coup_joue;
    coup_historique=p.coup_historique;
    pos_fille=p.pos_fille;
    pos_soeur=p.pos_soeur;
    return *this;
}


position_ttt::position_ttt(ttt E) //constructeur de la position initiale
{
    ttt_ref=E;
}


void partie() //definition d'une partie
{
    ttt TTT; //definition d'un ttt
    TTT=ttt(); //initiqlisqtion d'un ttt
    TTT.print();
    
    //coup possible pour le joueur humain
    //coup joue par le joueur huamin
    
    //determiner le meilleur coup du joueur ordinateur(minmax)
    //coup joue par le joueur ordinateur
    position_ttt pos_init=position_ttt(TTT); //definition de la position du ttt TTT
    pos_init.Jeu_pos=humain;
    
    
}

