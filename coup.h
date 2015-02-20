#ifndef COUP_H_INCLUDED
#define COUP_H_INCLUDED
class Coup
{
    public:
    couleur col;
    piece piece_jouee;
    position pos_ancienne;
    position pos_nouvelle;
    bool coup(echiquier e);
    bool roque(echiquier e);


};

#endif // COUP_H_INCLUDED
