#include "piece.h"
#include "position_echecs.h"
#include "echiquier.h"
#include "coup.h"
#include <ostream>
#include <iostream>

using namespace std;

position_echecs::position_echecs() //constructeur de la position initiale
{
    coup_joue=coup();
    echiquier_ref=echiquier();
}

position_echecs::~position_echecs()// destructeur de toutes les positions filles
{
    if((pos_fille!=NULL||pos_soeur!=NULL))
    delete []pos_fille;
    delete []pos_soeur;
}

echiquier position_echecs::maj() //mise a jour de l'echiquier de reference apres les coups joués
{
    echiquier E=echiquier_ref;
    coup cp=coup_joue;
    E.echectab[cp.colonne_final][cp.ligne_final]=cp.piece_jouee;
    E.echectab[cp.colonne_init][cp.ligne_init]=piece();
    return E;
}

int position_echecs::getvaleur()// la fonction qui renvoie la valeur d'une position
{
    int val_piece_ordinateur=0;
    int cont_ordinateur=0;
    int val_piece_humain=0;
    int cont_humain=0;
    int alpha=1;
    int beta=1;
    echiquier E=echiquier_ref;
    coup cp=coup_joue;
    E=maj();
    for(int c=0; c<8; c++)
    {
        for(int l=0; l<8; l++)
        {
            if (E.echectab[c][l].color==noir)
            {
                val_piece_ordinateur+=E.echectab[c][l].getvaleurpiece();
                if (E.echectab[c][l].type_piece!=Piecevide) {
                    cont_ordinateur++;
                }
                else if(E.echectab[c][l].color==noir)
                {
                    val_piece_humain+=E.echectab[c][l].getvaleurpiece();
                    if (E.echectab[c][l].type_piece!=Piecevide) {
                        cont_humain++;
                    }
                }
            }
        }
    }
    return alpha*(val_piece_ordinateur-val_piece_humain)+beta*(cont_ordinateur-cont_humain);
}


position_echecs* position_echecs::get_pos_suiv(position_echecs &p)
{
    echiquier E=p.echiquier_ref;
    coup cp=p.coup_joue;
    int nbcoup=0;
    for (int i=0;i<100;i++) {
        if (cp.coup_possible(E)==true) {
            nbcoup++;
        }
    }
    position_echecs* p_current = & p;
    p.pos_fille = &p;
    for(int i=0;i<nbcoup;i++)
    {
        
        p.pos_fille->echiquier_ref=maj();
        p.pos_fille->coup_joue=coup();      //? quels sont les coups possibles d'une position fille
        p.pos_fille->pos_fille= get_pos_suiv(*p.pos_fille);
        p_current->pos_soeur = p.pos_fille;
        p_current = p.pos_fille;
    }
    return  p.pos_fille;
}


position_echecs & position_echecs::operator=(const position_echecs & p) //operateur = pour une position_echec
{
    if(this==&p)
    return *this;
    else
    {
        echiquier_ref=p.echiquier_ref;
        coup_joue=p.coup_joue;
        pos_fille=p.pos_fille;
        pos_soeur=p.pos_soeur;
        return *this;
    }
}
position_echecs::position_echecs(const position_echecs & p) //operateur par copie
{
    echiquier_ref=p.echiquier_ref;
    coup_joue=p.coup_joue;
    pos_fille=p.pos_fille;
    pos_soeur=p.pos_soeur;
}

position_echecs position_echecs::IA()
{
    position_echecs P;
    P.echiquier_ref.print();
    int l1,c1,l2,c2=0;
    cout<<"Choisissez la piece :"<<endl;
    cout<<"Il faut écrire des chiffres"<<endl;
    cout<<"ligne=?"<<endl;
    cin>>l1;
    cout<<"colone=?";
    cin>>c1;
    cout<<"Choisissez la case où vous voulez aller :"<<endl;
    cout<<"ligne=?"<<endl;
    cin>>l2;
    cout<<"colone=?"<<endl;
    cout<<endl;
    cin>>c2;
    
    coup cp=coup();
    cp.piece_jouee=echiquier_ref.echectab[l1-1][c1-1];
    cp.piece_mangee=echiquier_ref.echectab[l2-1][c2-1];
    
        
    if(cp.coup_possible(echiquier_ref)==false)
    {
        cout<<"Coup interdit. Il faut choisir un autre coup..."<<endl;
        IA();
    }
    else
    {
        P.coup_joue=cp;
        P.echiquier_ref=maj();
    }
    P.echiquier_ref.print();
    
    return P;
}

bool position_echecs::fin_partie() //tester si c'est la fin d'une partie
{
    int n=0;
    echiquier E=echiquier_ref;
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (E.echectab[i][j].type_piece==Roi)
            {
                n++;
            }
        }
    }
    if (n==1)
        return true;
    else return false;
}


int position_echecs::nbcoup()
{
    echiquier E=echiquier_ref;
    coup cp=coup_joue;
    int nbcoup=0;
    for (int i=0;i<100;i++) {
        if (cp.coup_possible(E)==true) {
            nbcoup++;
        }
    }
    return nbcoup;
}
