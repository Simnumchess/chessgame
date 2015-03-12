
 #include "position_ttt.h"
#include "ttt.h"
#include "definition.h"
#include <ostream>
#include <iostream>

using namespace std;

position_ttt::position_ttt() //constructeur de la position initiale
{
    ttt_ref=ttt();
    pos_fille=NULL;
    pos_soeur=NULL;
}


position_ttt::~position_ttt()// destructeur de toutes les positions filles
{
    if((pos_fille!=NULL)||(pos_soeur!=NULL))
    {
        delete []pos_fille;
        delete []pos_soeur;
    }
}


ttt position_ttt::maj(int i) //mise a jour de l'echiquier de reference apres les coups joués
{
    if(getJoueur()=="humain") ttt_ref.ttttab[i]='X';
    else ttt_ref.ttttab[i]='O';
    return ttt_ref;

}


position_ttt* position_ttt::get_pos_suiv(position_ttt &p)
{
    ttt E=p.ttt_ref;
    int nbcoup=0;
    for (int i=0;i<10;i++) {
        if (E.casevide(i)==true) {
            nbcoup++;
        }
    }
    position_ttt* p_current = & p;
    p.pos_fille = &p;
    for(int i=0;i<nbcoup;i++)
    {
        
        p.pos_fille->ttt_ref=maj(i);
        p.pos_fille->pos_fille= get_pos_suiv(*p.pos_fille);
        p_current->pos_soeur = p.pos_fille;
        p_current = p.pos_fille;
    }
    return  p.pos_fille;
}


position_ttt & position_ttt::operator=(const position_ttt & p) //operateur = pour une position_echec
{
    if(this==&p)
        return *this;
    else
    {
        ttt_ref=p.ttt_ref;
        pos_fille=p.pos_fille;
        pos_soeur=p.pos_soeur;
        return *this;
    }
}

position_ttt::position_ttt(const position_ttt & p) //operateur par copie
{
    ttt_ref=p.ttt_ref;
    pos_fille=p.pos_fille;
    pos_soeur=p.pos_soeur;
}

position_ttt position_ttt::IA()
{
    position_ttt P;
    P.ttt_ref.print();
    int c=0;
    cout<<"Choisissez la case :"<<endl;
    cout<<"Il faut entrer des chiffres."<<endl;
    cin>>c;
    cout<<endl;
    
    if(ttt_ref.casevide(c)==false)
    {
        cout<<"Coup interdit. Il faut choisir un autre coup..."<<endl;
        IA();
    }
    else
    {
        P.ttt_ref.ttttab[c]='X';
    }
    P.ttt_ref.print();
    
    return P;
}



char position_ttt::fin_partie()
{
    ttt T=ttt_ref;
    
    if (T.nb_casesvides()==0)
    {
        
        cout<<"Fin de la partie !"<<endl;
        
        
        if(T.ttttab[1]==T.ttttab[2]) {
            if(T.ttttab[2]==T.ttttab[3])
                cout<<T.ttttab[1]<<" a gagné !"<<endl;
            return T.ttttab[1];
        }
        
        if(T.ttttab[4]==T.ttttab[5]) {
            if(T.ttttab[5]==T.ttttab[6])
                cout<<T.ttttab[4]<<" a gagné !"<<endl;
            return T.ttttab[4];
        }
        
        if(T.ttttab[7]==T.ttttab[8]) {
            if(T.ttttab[8]==T.ttttab[9])
                cout<<T.ttttab[7]<<" a gagné !"<<endl;
            return T.ttttab[7];
        }
        
        if(T.ttttab[1]==T.ttttab[4]) {
            if(T.ttttab[4]==T.ttttab[7])
                cout<<T.ttttab[1]<<" a gagné !"<<endl;
            return T.ttttab[1];
        }
        
        if(T.ttttab[2]==T.ttttab[5]) {
            if(T.ttttab[5]==T.ttttab[8])
                cout<<T.ttttab[2]<<" a gagné !"<<endl;
            return T.ttttab[2];
        }
        
        if(T.ttttab[3]==T.ttttab[6]) {
            if(T.ttttab[6]==T.ttttab[9])
                cout<<T.ttttab[3]<<" a gagné !"<<endl;
            return T.ttttab[3];
        }
        
        if(T.ttttab[1]==T.ttttab[5]) {
            if(T.ttttab[5]==T.ttttab[9])
                cout<<T.ttttab[1]<<" a gagné !"<<endl;
            return T.ttttab[1];
        }
        
        if(T.ttttab[3]==T.ttttab[5]) {
            if(T.ttttab[5]==T.ttttab[7])
                cout<<T.ttttab[7]<<" a gagné !"<<endl;
            return T.ttttab[3];
        }
        
        else cout<<"Match nul...Retente ta chance !"<<endl;
        
        
    }
    
    else return '0';
    return 0;

}


string position_ttt::getJoueur(){
    string joueur;
    int nb=ttt_ref.nb_casesvides();
    if (nb==9||nb==7||nb==5||nb==3||nb==1) {joueur=humain;}
    else {joueur=ordinateur;}
    return joueur;
}

