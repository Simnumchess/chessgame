#ifndef DEFINITION_H_INCLUDED
#define DEFINITION_H_INCLUDED
#include <limits>
using namespace std;

const int mini=numeric_limits<int>::min(); //the minimum value of 'int'
const int maxi=numeric_limits<int>::max(); //the maximum value of 'int'
enum case_TTT {croix , rond , vide};
enum Joueur {humain, ordinateur};
enum type {Roi, Dame, Tour, Cavalier, Fou, Pion, Piecevide};
enum couleur {blanc, noir};

#endif // DEFINITION_H_INCLUDED
//kaeria
