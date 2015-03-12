
#include "ttt.h"
#include "piece.h"
#include "definition.h"
#include <iostream>
#include <ostream>
#include <string>



ttt::ttt() //initialisation
{
    ttttab[0]='0';
    ttttab[1]='1';
    ttttab[2]='2';
    ttttab[3]='3';
    ttttab[4]='4';
    ttttab[5]='5';
    ttttab[6]='6';
    ttttab[7]='7';
    ttttab[8]='8';
    ttttab[9]='9';

    
}


ttt::~ttt()
{
}


void ttt::print()
{
    cout << "\n\n\tTic Tac Toe\n\n";
    
    cout << "Humain (X)  -  Ordinateur (O)" << endl << endl;
    cout << endl;
    
    cout << "     |     |     " << endl;
    cout << "  " << ttttab[1] << "  |  " << ttttab[2] << "  |  " << ttttab[3] << endl;
    
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    
    cout << "  " << ttttab[4] << "  |  " << ttttab[5] << "  |  " << ttttab[6] << endl;
    
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    
    cout << "  " << ttttab[7] << "  |  " << ttttab[8] << "  |  " << ttttab[9] << endl;
    
    cout << "     |     |     " << endl << endl;
}




ttt::ttt(const ttt & TTT) //constructeur par copie
{
    char ttttab[10];
    for(int i=0;i<10;i++)
    {
        ttttab[i]=TTT.ttttab[i];
    }
}




ttt &ttt::operator=(const ttt & TTT) //operator par copie
{
    char ttttab[10];
    for(int i=1;i<10;i++)
    {
        ttttab[i]=TTT.ttttab[i];
    }
    return *this;
}


bool ttt::casevide(int i)
{
    if(ttttab[i]=='X') return false;
    else if (ttttab[i]=='O') return false;
    else return true;
}


int ttt::nb_casesvides(){
    int nb=0;
    for (int i=1;i<10;i++){
        if(casevide(i)==1)
            nb=nb+1;
    }
    return nb;
}


