#ifndef ECHIQUIER_H_INCLUDED
#define ECHIQUIER_H_INCLUDED

class echiquier
{
    public:
    int dim;
    piece **echectab; //le tableau 8*8 de pointeurs de pieces
    bool casevide(int l,int c) //prend un case de coordonee (l,c) et ragarde si la case est vide
    void print();
    echiquier(); //initialisation d'un echiquier
    echiquier(const echiquier &); //operateur par copie
    echiquier & operator=(const operator &); //operateur=
    ~echiquier(); //destructeur d'un echiquier
};


#endif // ECHIQUIER_H_INCLUDED
