#ifndef TTT_H_INCLUDED
#define TTT_H_INCLUDED
#include "definition.h"
#include "piece.h"
#include "position.h"
#include "position_ttt.h"
using namespace std;

class ttt
{
    public:
    int dim;
    Piece **ttttab; //le tableau 3*3 de pointeurs de pieces
    bool casevide(int l,int c) //prend un case de coordonee (l,c) et regarde si la case est vide
    void print(); //print un ttt
    ttt(); //initialisation d'un ttt
    ttt(const ttt &); //operateur par copie
    ttt & operator=(const operator &); //operateur=
    ~ttt(); //destructeur d'un ttt
};


#endif // TTT_H_INCLUDED

