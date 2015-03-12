#include <string>
#ifndef TTT_H_INCLUDED
#define TTT_H_INCLUDED

using namespace std;

class ttt
{
    public:
    
    char ttttab[10];
    bool casevide(int l); //prend un case de coordonee l et regarde si elle est vide
    void print(); //print un ttt
    ttt(); //initialisation d'un ttt
    ttt(const ttt &); //operateur par copie
    ttt & operator=(const ttt &); //operateur=
    ~ttt(); //destructeur d'un ttt
    int nb_casesvides();
};


#endif // TTT_H_INCLUDED

