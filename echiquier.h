#ifndef ECHIQUIER_H_INCLUDED
#define ECHIQUIER_H_INCLUDED

class echiquier
{
    public:
    int dim;
    piece **echectab;
    bool casevide(int l,int c)
    void print();
    echiquier();
    echiquier(const echiquier &);
    echiquier & operator=(const operator &);
    ~echiquier();


};


#endif // ECHIQUIER_H_INCLUDED
