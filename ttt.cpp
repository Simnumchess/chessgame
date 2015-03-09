#include "ttt.h"
#include "piece.h"
#include "definition.h"
#include <iostream>
#include <ostream>


ttt::ttt() //initialisation
{
    char ttttab[3][3];
    for(int i=0;i<3;i++)
    {
        ttttab[i]=new char[3];
        {
            for(int j=0;j<3;j++)
            ttttab[i][j]=' ';
        }
    }
}


ttt::~ttt()
{
    if(ttttab!=NULL)
    for(int i=0:i<3;i++)
    {
        delete []ttttab[i];
        delete []ttttab;
    }
}


void ttt::print()
{
    cout<<endl;
    cout<<"   A   B   C"<<endl;
    
    cout<<"1  "<<ttttab[0][0]<<" | "<<ttttab[0][1]<<" | "<<ttttab[0][2]<<endl;
    cout<<"   ---------"<<endl;
    
    cout<<"2  "<<ttttab[1][0]<<" | "<<ttttab[1][1]<<" | "<<ttttab[1][2]<<endl;
    cout<<"   ---------"<<endl;
    
    cout<<"3  "<<ttttab[2][0]<<" | "<<ttttab[2][1]<<" | "<<ttttab[2][2]<<endl;
    cout<<endl;
    
}




ttt::ttt(const ttt & TTT) //constructeur par copie
{
    dim=TTT.dim;
    char ttttab[3][3];
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        ttttab[i][j]=TTT.ttttab[i][j];
    }
}


ttt::ttt & operator=(const ttt & TTT) //operator par copie
{
    char ttttab[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        ttttab[i][j]=TTT.ttttab[i][j];
    }
    return *this;
}


bool ttt::casevide(int l,int c)
{
    if(ttttab[l][c]==0)
    return true;
    else
    return false;
}

int fin_partie()
{
   if(ttttab[0][0]==ttttab[0][1]) {
       if(ttttab[0][1]==ttttab[0][2])
       cout<<ttttab[0][0]<<"a gagné"<<endl;
       
   }
   
   if(ttttab[1][0]==ttttab[1][1]) {
       if(ttttab[1][1]==ttttab[1][2])
       cout<<ttttab[1][0]<<"a gagné"<<endl;
       
   }    
   
   if(ttttab[2][0]==ttttab[2][1]) {
       if(ttttab[2][1]==ttttab[2][2])
       cout<<ttttab[2][0]<<"a gagné"<<endl;
       
   }
    
   if(ttttab[0][0]==ttttab[1][0]) {
       if(ttttab[1][0]==ttttab[2][0])
       cout<<ttttab[0][0]<<"a gagné"<<endl;
       
   }
   
   if(ttttab[0][1]==ttttab[1][1]) {
       if(ttttab[1][1]==ttttab[2][1])
       cout<<ttttab[0][1]<<"a gagné"<<endl;
       
   }

   if(ttttab[0][2]==ttttab[1][2]) {
       if(ttttab[1][2]==ttttab[2][2])
       cout<<ttttab[0][1]<<"a gagné !"<<endl;
       
   }
    
   if(ttttab[0][0]==ttttab[1][1]) {
       if(ttttab[1][1]==ttttab[2][2])
       cout<<ttttab[0][0]<<"a gagné !"<<endl;
       
   }

   if(ttttab[0][2]==ttttab[1][1]) {
       if(ttttab[1][1]==ttttab[2][0])
       cout<<ttttab[0][2]<<"a gagné !"<<endl;
       
   }
    
    
}
