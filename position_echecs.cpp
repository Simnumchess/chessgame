#include "piece.h"
#include "position_echecs.h"
#include "echiquier.h"
#include "coup.h"
#include "minmax.h"
#include <ostream>
#include <iostream>
using namespace std;

int position_echecs::val_pos_ordinateur()
{
    int val_pos_ordinateur=0;
    for(int l=0; l<8; l++)
    {
        for(int c=0;c<8;c++)
            if(echiquier_ref.echectab[l][c].color==noir)
            val_pos_ordinateur+=echiquier_ref.echectab[l][c].getvaleurpiece();
    }
    return val_pos_ordinateur;
}
int position_echecs::val_pos_humain()
{
    int val_pos_humain=0;
    for(int l=0; l<8; l++)
    {
        for(int c=0;c<8;c++)
            if(echiquier_ref.echectab[l][c].color==blanc)
                val_pos_humain+=echiquier_ref.echectab[l][c].getvaleurpiece();

    }
    return val_pos_humain;
}



position_echecs::~position_echecs()// destructeur de toutes les positions filles
{
    if((pos_fille!=NULL||pos_soeur!=NULL))
    delete []pos_fille;
    delete []pos_soeur;
}
double position_echecs::getvaleur()// la fonction qui renvoie la valeur d'une position
{
    int alpha=1;
    int beta=1;
    int cont_ordinateur=0;
    int cont_humain=0;

    for(int l=0;l<8;l++)
    {
        for(int c=0;c<8;c++)
        if(echiquier_ref.echectab[l][c].type_piece!=Piecevide&&echiquier_ref.echectab[l][c].color==noir)
        cont_ordinateur++;
    }
    for(int l=0;l<8;l++)
    {
        for(int c=0;c<8;c++)
        if(echiquier_ref.echectab[l][c].type_piece!=Piecevide&&echiquier_ref.echectab[l][c].color==blanc)
        cont_humain++;
    }
    double valeur;
    valeur=alpha*(val_pos_humain()-val_pos_ordinateur())+beta*(cont_humain-cont_ordinateur);
    return valeur;
}
position_echecs* position_echecs::get_pos_suiv()
{

    position_echecs* pos_fille=new position_echecs[100]; //un tableau de position fille
    int n=0;
    if(Jeu_pos==humain) //si le humain joue
    {
        for(int l=0;l<8;l++)
        {
            for(int c=0;c<8;c++)
            {
                if((echiquier_ref.echectab[l][c].type_piece!=Piecevide)&&(echiquier_ref.echectab[l][c].color==blanc))
                {
                    coup C;
                    C.piece_jouee=echiquier_ref.echectab[l][c];
                    C.piece_mangee=piece(); //piecevide
                    if(C.coup_possible(echiquier_ref)==true)
                    {
                        pos_fille[n]=position_echecs(*this);
                        if(Jeu_pos==humain)
                        {
                            pos_fille[n].Jeu_pos=ordinateur;
                        }
                        else
                        {
                            pos_fille[n].Jeu_pos=humain;
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
                if((echiquier_ref.echectab[l][c].type_piece!=Piecevide)&&(echiquier_ref.echectab[l][c].color==noir))
                {
                    coup C;
                    C.piece_jouee=echiquier_ref.echectab[l][c];
                    C.piece_mangee=piece(); //piecevide
                    if(C.coup_possible(echiquier_ref)==true)
                    {
                        pos_fille[n]=position_echecs(*this);
                        if(Jeu_pos==humain)
                        {
                            pos_fille[n].Jeu_pos=ordinateur;
                        }
                        else
                        {
                            pos_fille[n].Jeu_pos=humain;
                        }
                        n++;
                    }
                }
            }
            return pos_fille;    }
}
/*
int position_echecs::resultat() const
{
    if(coup_joue.piece_mangee.type_piece==Roi)
    {
        if(coup_joue.piece_mangee.col==blanc)
        {

            cout<<"You lose";
            return mini;
            else if()
            cout<<"You win";
            return maxi;

        }
    }

    else return 0;
    cout<<"Please continue...";
}
*/
/*
position_echecs & position_echecs::explorer() //explorer 4 coups(2 par joueurs)
{
    int l1,l2,c1,c2=0;
    //explorer les coups
    coup cp=coup();
    cp.piece_jouee=echiquier_ref[l1][c1];
    cp.piece_mangee=echiauier_ref[l2][c2];
    cp.ligne_init=l1;
    cp.colone_init=c1;
    cp.ligne_final=l2;
    cp.colone_final=c2;
    cp.col=echiquier_ref.echectab[l1][c1].col;

}
*/
position_echecs position_echecs::maj() //mise a jour de l'echiquier de reference apres les coups jouees
{
    echiquier_ref.echectab[coup_jouee.colonne_final][coup_jouee.ligne_final]=coup_jouee.piece_jouee;
    echiquier_ref.echectab[coup_jouee.colonne_init][coup_jouee.ligne_init]=piece();
    return *this;
}



position_echecs & position_echecs::operator=(const position_echecs & p) //operateur = pour une position_echec
{
    if(this==&p)
    return *this;
    else
    {
        echiquier_ref=p.echiquier_ref;
        coup_joue=p.coup_joue;
        coup_historique=p.coup_historique;
        pos_fille=p.pos_fille;
        pos_soeur=p.pos_soeur;
        return *this;
    }
}
position_echecs::position_echecs(const position_echecs & p) //operateur par copie
{
    echiquier_ref=p.echiquier_ref;
    coup_joue=p.coup_joue;
    coup_historique=p.coup_historique;
    pos_fille=p.pos_fille;
    pos_soeur=p.pos_soeur;
    return *this;
}
//pos_fille= new pos(ech_ref,listecouppossible[0],profondeur-1)
/*
pos1=pos_fille;
for (int i=1, i<nb_coup,i++)
    pos1->pos_soeur

pos1*=pos_fille
pos1*=new
{
    pos_fille->pos_soeur=new position(echiquier ref,c[1],profondeur-1);
}

pos_fille= new position()
position* p=pos_fille;
for i nb fille +11
    p->pos_soeur=new position ()
    p=p->pos_soeur;
*/



position_echecs::position_echecs(int profondeur,echiquier e,coup* coup ) //constructeur de la position initiale
{
    echiquier_ref=e;
    if prof!=0
    pos_fille= new position_echecs(profondeur-1,e)
}
position_ehcec & position_echec::IA()
{
    int l1,c1,l2,c2=0;
    cout<<"Choisissez la piece..."<<endl;
    cout<<"ligne=?"<<endl;
    cin>>l1;
    cout<<"colone=?";
    cin>>c1;
    cout<<"Choisissez la case que vous voulez aller a"<<endl;
    cout<<"ligne=?"<<endl;
    cin>>l2;
    cout<<"colone=?"<<endl;
    cin>>c2;

    coup cp=coup();
    cp.piece_jouee=echiquier_ref.echectab[l1][c1];
    cp.piece_mangee=echiquier_ref.echectab[l2][c2];

    if(cp.coup_possible(echiquier_ref)==false)
    {
        cout<<"coup pas possible"<<endl;
        return IA();
    }
    else
    {
        coup_jouee=cp;
    }
    for(int i=0;i<40;i++)
    {
        if(historique[i].piece_jouee.type_piece!=Piece_vide)
        {
            historique[i]=cp;
        }
    }
    maj();
    echiquier_ref.print();

}
/*
void partie() //definition d'une partie
{
    echiquier E; //definition d'un echiquier
    E=echiquier(); //initiqlisqtion d'un echiquier
    E.print();

    //coup possible pour le joueur humain
    //coup joue par le joueur huamin

    //determiner le meilleur coup du joueur ordinateur(minmax)
    //coup joue par le joueur ordinateur
    position_echecs pos_init=position_echecs(E); //definition de la position de l'echiquier E
    pos_init.Jeu_pos=humain;


}
*/
