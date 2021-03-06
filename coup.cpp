#include "coup.h"
#include "piece.h"
#include <iostream>
#include <ostream>


using namespace std;

bool coup::obstacle(echiquier e)
{

    switch (piece_jouee.type_piece)

    {
        case Pion:
        {
            if ((piece_jouee.deplacement(colonne_final,ligne_final))==true)

            {
                if (piece_jouee.color==blanc)
                {

                    if (e.casevide(colonne_init,ligne_init-1))
                    {
                        return true;
                        break;
                    }
                    else
                    {
                        return false ;
                        break;
                    }


                }

                else
                {
                    if (e.casevide(colonne_init,ligne_init+1))
                    {
                        return true;
                        break;
                    }
                    else
                    {
                        return false;
                        break;
                    }

                }



            }
            else return false;
            break;
        }

        case Tour:
        {

            if ((piece_jouee.deplacement(colonne_final,ligne_final))==true)
            {
                if (ligne_final==ligne_init)
                {
                    if (colonne_init<colonne_final)
                    {
                        for (int i=colonne_init+1; i<colonne_final; i++)
                            if (not(e.casevide(i,ligne_init)))
                            {
                                return false;
                                break;
                            }
                        return true;
                        break;
                    }

                    else

                    {
                        for (int i=colonne_init-1; i>colonne_final; i--)
                            if (not(e.casevide(i,ligne_init)))
                            {
                                return false;
                                break;
                            }
                        return true;
                        break;
                    }

                }
                else

                    if (colonne_final==colonne_init)
                    {
                        if (ligne_init<ligne_final)
                        {

                            for (int i=ligne_init+1; i<ligne_final; i++)
                                if (not(e.casevide(colonne_init,i)))
                                {
                                    return false;
                                    break;
                                }
                            return true;
                            break;
                        }

                        else
                        {
                            for (int i=ligne_init-1; i>ligne_final; i--)
                                if (not(e.casevide(colonne_init,i)))
                                {
                                    return false;
                                    break;
                                }
                            return true;
                            break;
                        }


                    }



            }
            else
            {
                return false;
                break;
            }

        }



        case Fou:

        {

            if ((piece_jouee.deplacement(colonne_final,ligne_final))==true)
            {

                if ((colonne_init>colonne_final) && (ligne_init>ligne_final)) //position finale en haut à gauche
                {
                    for (int i=1; i<colonne_init-colonne_final; i++)
                        if (not(e.casevide(colonne_init-i,ligne_init-i)))
                        {
                            return false;
                            break;
                        }
                    return true;
                    break;
                }


                if ((colonne_init<colonne_final) && (ligne_init<ligne_final)) //position finale en bas à droite
                {
                    for (int i=1; i<colonne_final-colonne_init; i++)
                        if (not(e.casevide(colonne_init+i,ligne_init+i)))
                        {
                            return false;
                            break;
                        }
                    return true;
                    break;
                }
                if ((colonne_init>colonne_final) && (ligne_init<ligne_final)) //position finale en bas à gauche
                {
                    for (int i=1; i<colonne_init-colonne_final; i++)
                        if (not(e.casevide(colonne_init-i,ligne_init+i)))
                        {
                            return false;
                            break;
                        }
                    return true;
                    break;
                }


                if ((colonne_init<colonne_final) && (ligne_init>ligne_final)) //position finale en haut à droite
                {
                    for (int i=1; i<colonne_final-colonne_init; i++)
                        if (not(e.casevide(colonne_init+i,ligne_init-i)))
                        {
                            return false;
                            break;
                        }
                    return true;
                    break;
                }
                else  return true;


            }

            else
            {
                return false;
                break;
            }
        }


        case Dame:
        {

            if ((piece_jouee.deplacement(colonne_final,ligne_final))==true)
            {
                if ((colonne_init>colonne_final) && (ligne_init>ligne_final)) //position finale en haut à gauche
                {
                    for (int i=1; i<colonne_init-colonne_final; i++)
                        if (not(e.casevide(colonne_init-i,ligne_init-i)))
                        {
                            return false;
                            break;
                        }
                    return true;
                    break;
                }


                else if ((colonne_init<colonne_final) && (ligne_init<ligne_final)) //position finale en bas à droite
                {
                    for (int i=1; i<colonne_final-colonne_init; i++)
                        if (not(e.casevide(colonne_init+i,ligne_init+i)))
                        {
                            return false;
                            break;
                        }
                    return true;
                    break;
                }
                else if ((colonne_init>colonne_final) && (ligne_init<ligne_final)) //position finale en bas à gauche
                {
                    for (int i=1; i<colonne_init-colonne_final; i++)
                        if (not(e.casevide(colonne_init-i,ligne_init+i)))
                        {
                            return false;
                            break;
                        }
                    return true;
                    break;
                }


                else if ((colonne_init<colonne_final) && (ligne_init>ligne_final)) //position finale en haut à droite
                {
                    for (int i=1; i<colonne_final-colonne_init; i++)
                        if (not(e.casevide(colonne_init+i,ligne_init-i)))
                        {
                            return false;
                            break;
                        }
                    return true;
                    break;
                }

                else   if (ligne_final==ligne_init)
                {
                    if (colonne_init<colonne_final)
                    {
                        for (int i=colonne_init+1; i<=colonne_final; i++)
                            if (not(e.casevide(i,ligne_init)))
                            {
                                return false;
                                break;
                            }
                        return true;
                        break;
                    }

                    else

                    {
                        for (int i=colonne_init-1; i>=colonne_final; i--)
                            if (not(e.casevide(i,ligne_init)))
                            {
                                return false;
                                break;
                            }
                        return true;
                        break;
                    }

                }
                else

                    if (colonne_final==colonne_init)
                    {
                        if (ligne_init<ligne_final)
                        {

                            for (int i=ligne_init+1; i<=ligne_final; i++)
                                if (not(e.casevide(colonne_init,i)))
                                {
                                    return false;
                                    break;
                                }
                            return true;
                            break;
                        }

                        else
                        {
                            for (int i=ligne_init-1; i>=ligne_final; i--)
                                if (not(e.casevide(colonne_init,i)))
                                {
                                    return false;
                                    break;
                                }
                            return true;
                            break;
                        }


                    }



                    else
                    {
                        return false;
                        break;
                    }
            }
        }

        case Cavalier :
        {
            if ((piece_jouee.deplacement(colonne_final,ligne_final))==true)
            {
                return true;
                break;
            }
        }


        case Roi:

        {
            if ((piece_jouee.deplacement(colonne_final,ligne_final))==true)
            {
                return true;
                break;
            }
        }
        case Piecevide:
        {
            return false;
            break;
        }

    }
}

/*

 bool coup::coup_possible(echiquier e)
 {
 if (coup_possible_non_complet(e)==true)
 if (echec(e)==false) {return true;}
 else {cout<<"t'es en echec si tu joues ce coup"<<endl; return false;}
 else {return false;}
 }*/

//donne plus de coup que la normal
bool coup::coup_possible(echiquier e)
{
    if (piece_jouee.type_piece==Pion) // le cas du pion
    {
        if ((piece_jouee.color==blanc) && (ligne_final>ligne_init))
        {
            return false;
        }
        else if ((piece_jouee.color==noir) && (ligne_final<ligne_init))
        {
            return false;
        }
        else if ((colonne_final==colonne_init+1) && (ligne_final=ligne_init-1))
        {
            if (piece_jouee.color==blanc && e.echectab[colonne_init+1][ligne_init-1].color==noir  )
            {
                piece_mangee=e.echectab[colonne_init+1][ligne_init-1];
                return true;
            }
            else if (piece_jouee.color==noir && e.echectab[colonne_init+1][ligne_init-1].color==blanc)
            {
                piece_mangee=e.echectab[colonne_final][ligne_final];
                return true;
            }

        }
        else
        {
            if ((colonne_final==colonne_init-1) && (ligne_final=ligne_init-1))
            {
                if (piece_jouee.color==blanc && e.echectab[colonne_init-1][ligne_init-1].color==noir  )
                {
                    piece_mangee=e.echectab[colonne_final][ligne_final];
                    return true;
                }
                else if (piece_jouee.color==noir && e.echectab[colonne_init-1][ligne_init-1].color==blanc)
                {
                    piece_mangee=e.echectab[colonne_final][ligne_final];
                    return true;
                }
            }
        }
    }


    //on test d'abord si la case est vide ou pas. si elle n'est pas vide on regarde si elle est occupé par un joueur adverse, si oui on mange sinon c'est mort.

    if ((e.casevide(colonne_final, ligne_final) == true) &&  (obstacle(e)==true))
        return true; //la case est vide donc peux y aller
    else if ((e.echectab[colonne_final][ligne_final].color==blanc && e.echectab[colonne_init][ligne_init].color==noir && obstacle(e)) || (e.echectab[colonne_final][ligne_final].color==noir && e.echectab[colonne_init][ligne_init].color==blanc && obstacle(e)))
    {
        piece_mangee=e.echectab[colonne_final][ligne_final];    //  else //if ((e.plat[colonne_final][ligne_final].col!=col) && (obstacle(e)==false))
        return true;
    }
    else return false;
}


/*
bool coup::echec(echiquier e)
{
    int a=0;
    int b=0;
    a=e.pos_roi_bl()[0];
    b=e.pos_roi_bl()[1];

    for (int j=0; j<8; j++)
        for (int i=0; i<8; i++)
        {



            if (e.plat[i][j].col==noir)
            {

                coup coup_provisoir=coup();
                coup_provisoir.piece_jouee=e.plat[i][j];
                coup_provisoir.ligne_init=j;
                coup_provisoir.colonne_init=i;
                coup_provisoir.ligne_final=b;
                coup_provisoir.colonne_final=a;

                if (coup_provisoir.coup_possible(e)==true)
                {
                    cout<<"bouge ton roi, t'es en echec"<<endl;
                    return true;
                    break;
                }


            }
        }
    {
        return false;
    }

}
*/


coup & coup::operator=(const coup & p) //operateur = pour une piece
{
    if (this==&p) return *this;
    else
    {
        piece_jouee=p.piece_jouee;
        piece_mangee=p.piece_mangee;
        ligne_init=p.ligne_init;
        colonne_init=p.colonne_init;
        ligne_final=p.ligne_final;
        colonne_final=p.colonne_final;
        color=p.color;
        return *this;
    }
}


coup::~coup()
{

}

coup::coup()
{
    piece_jouee=piece();
    piece_mangee=piece();

}


coup::coup(const coup & p) //operateur par copie
{
    piece_jouee=p.piece_jouee;
    piece_mangee=p.piece_mangee;
    ligne_init=p.ligne_init;
    colonne_init=p.colonne_init;
    ligne_final=p.ligne_final;
    colonne_final=p.colonne_final;
    color=p.color;
}
