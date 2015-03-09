#ifndef TTT_H_INCLUDED
#define TTT_H_INCLUDED

using namespace std;

class ttt
{
    public:
    char ttttab[3][3]; //le tableau 3*3 de pointeurs de int
    bool casevide(int l,int c) //prend un case de coordonee (l,c) et regarde si la case est vide
    void print(); //print un ttt
    ttt(); //initialisation d'un ttt
    ttt(const ttt &); //operateur par copie
    ttt & operator=(const operator &); //operateur=
    ~ttt(); //destructeur d'un ttt
    string getjoueur();
    int nb_casesvides();
};


#endif // TTT_H_INCLUDED

