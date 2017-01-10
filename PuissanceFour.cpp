#include <iostream>
#include "PuissanceFour.h"

using namespace std;

PuissanceFour::PuissanceFour()
{
m_P4Board=new Board;


m_P4Players[0]->setName("Player_1");
m_P4Players[0]->setCoinType('x');

m_P4Players[1]->setName("Player_2");
m_P4Players[1]->setCoinType('o');


}



PuissanceFour::PuissanceFour(int rows,int cols,string player1Name, string player2Name )
{
m_P4Board=new Board(rows,cols);




}

PuissanceFour::~PuissanceFour()
{
    //dtor
}

string PuissanceFour::Play()
{
    string winner("none");
    bool PartyEnd;

    int i(0);
    int col(0);
    int CoinRow(0);
    int coinNotInBoard(-1);

    do
    {


        do
        {
            m_P4Board->DisplayBoard();
            cout<<"indiquer la colonne ou jouer : (0 a "<<(m_P4Board->getTotalCol()-1)<<")"<<endl;
            cin>>col;
            coinNotInBoard=m_P4Board->putCoin(col,m_P4Players[0]->getCoinType());
        }
        while( coinNotInBoard == -1 );

        CoinRow=(m_P4Board->getTotalRow())-(m_P4Board->getCoinsPerCol(col));

        if(m_P4Board->checkVictory(CoinRow,col))
        {
            return m_P4Players[0]->getName();
            break;
        }


        i++;
    }
    while (  i <= (   (m_P4Board->getTotalRow()) * (m_P4Board->getTotalCol())  )    );


    return winner;
}
