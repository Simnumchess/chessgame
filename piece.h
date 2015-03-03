#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include "definition.h"
using namespace std;

class Piece
{
    public:
    type type_piece; //definition du type d'unr piece: {Roi, Dame, Tour, Cavalier, FOu, Pion, Piecevide}
    couleur col; //definition du couleur d'une piece: {blanc, noir}
    void print(); //print d'une piece selon son type
    int placementl; //un deplacement relatif en ligne
    int placementc; //un deplacement relatif en colone
    int i; //la position d'une piece en ligne
    int j; //la position d'une piece en colone
    bool deplacement(int l,int c); //regarde si on peut faire un deplacement
    int val; //valeur d'une piece: val_roi=0; val_pion=v; val_reine=9*v; val_tour=5*v; val_fou=3*v; val_cavalier=3*v
    int getvaleurpiece(); //renvoie la valeur d'une piece selon son type
    piece(); //constructeur d'une piece
    piece & operator=(const piece &); //operateur=
    ~piece(); //destructeur d'une piece
};
#endif // PIECE_H_INCLUDED
