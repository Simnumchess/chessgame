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

echiquier position_echecs::maj(position_echecs pos) //mise a jour de l'echiquier de reference apres les coups joués
{
    echiquier E=pos.echiquier_ref;
    coup cp=pos.coup_joue;
    E.echectab[cp.colonne_final][cp.ligne_final]=cp.piece_jouee;
    E.echectab[cp.colonne_init][cp.ligne_init]=piece();
    return E;
}

double position_echecs::getvaleur(position_echecs pos)// la fonction qui renvoie la valeur d'une position
{
    int val_piece_ordinateur=0;
    int cont_ordinateur=0;
    int val_piece_humain=0;
    int cont_humain=0;
    int alpha=1;
    int beta=1;
    echiquier E=pos.echiquier_ref;
    coup cp=pos.coup_joue;
    E=maj(pos);
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


position_echecs* position_echecs::get_pos_suiv(position_echecs p)
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
        
        p.pos_fille->echiquier_ref=maj(p);
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

void position_echecs::IA(position_echecs & p)
{
    int l1,c1,l2,c2=0;
    cout<<"Choisissez la piece :"<<endl;
    cout<<"ligne=?"<<endl;
    cin>>l1;
    cout<<"colone=?";
    cin>>c1;
    cout<<"Choisissez la case où vous voulez aller :"<<endl;
    cout<<"ligne=?"<<endl;
    cin>>l2;
    cout<<"colone=?"<<endl;
    cin>>c2;
    
    coup cp=coup();
    cp.piece_jouee=echiquier_ref.echectab[l1][c1];
    cp.piece_mangee=echiquier_ref.echectab[l2][c2];
    
        
    if(cp.coup_possible(echiquier_ref)==false)
    {
        cout<<"Coup interdit. Il faut choisir un autre coup..."<<endl;
        IA(p);
    }
    else
    {
        p.coup_joue=cp;
        p.echiquier_ref=maj(p);
    }
    p.echiquier_ref.print();
}
