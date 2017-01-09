#include <iostream>
#include "PuissanceFour.h"

using namespace std;

PuissanceFour::PuissanceFour()
{
m_Board=new Board;

m_player1.setName("Player_1");
m_player1.setCoinType('x');

m_player1.setName("Player_2");
m_player1.setCoinType('o');


}



PuissanceFour::PuissanceFour(int rows,int cols )
{
m_Board=new Board(rows,cols);

m_player1.setName("Player_1");
m_player1.setCoinType('x');

m_player1.setName("Player_2");
m_player1.setCoinType('o');


}

PuissanceFour::~PuissanceFour()
{
    //dtor
}

string PuissanceFour::Play()
{
    string winner("none");
    int i(0);
    int col(0);

    do
    {
     m_Board->DisplayBoard();
     cout<<"indiquer la colonne ou jouer : (0 a "<<m_Board->getTotalCol()<<")"<<endl;
     cin>>col;


        i++;
    }
    while (  i <= (   (m_Board->getTotalRow()) * (m_Board->getTotalCol())  )    );


    return winner;
}
