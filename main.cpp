#include <iostream>
#include <ostream>
#include "coup.h"
#include "minmax_ab.h"
#include "minmax.h"
#include "echiquier.h"
#include "piece.h"
#include "ttt.h"
#include "position.h"
#include "position_ttt.h"
#include "position_echecs.h"
#include "minmax_ttt.h"
#include "definition.h"

using namespace std

//TicTacToe
cout<<"Bienvenue dans notre TicTacToe"<<endl;
ttt TTT;
TTT.print();
cout<<"C'est à vous de jouer ! Vous êtes les croix"<<endl;
cout<<"Où voulez vous placer votre croix ?"<<endl;
char placement_croix[2];
cin>>placement_croix;




//Echecs
cout<<"Bienvenue dans notre jeu d'Echecs"<<endl;
echiquier E;
E.print();
cout<<"C'est à vous de jouer !"<<endl;
cout<<"Quel coup voulez-vous jouer ?"<<endl;
//à modifier
coup coup_choisi;
cin>>coup;



