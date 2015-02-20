#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include <iostream>
#include <ostream>
#include <stdlib.h>

using namespace std;
class TypePiece
{
    public:
    TypePiece type;
    enum couleur
    {
        blanc;
        noir;
    }
    enum type
    {
        tour;
        fou;
        cavalier;
        dame;
        roi;
        pion;
    }
    void print();
    int placementl;
    int placementc;
    bool deplacement(int l,int c);
    int val_piece;
    int getvaleurpiece(int v);
};
class Piece
{
    public:
    Piece type;
    enum type
    {
        croix;
        rond;
    }
    enum couleur
    {

    }
    int **position;
    piece();
    piece & operator=(const piece &);
    ~piece();
};
#endif // PIECE_H_INCLUDED
