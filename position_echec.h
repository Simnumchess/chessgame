#ifndef POSITION_GLOBALE_H_INCLUDED
#define POSITION_GLOBALE_H_INCLUDED
class position_echec : class position
{
    public:
    ~position_echec();
    double getvaleur() const;

    position_echec();
    position_echec(const position_echec &)

    position_echec & operator=(const position_echec &)
    void print();

};


#endif // POSITION_GLOBALE_H_INCLUDED

