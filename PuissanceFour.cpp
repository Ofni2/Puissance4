#include <iostream>
#include "PuissanceFour.h"

using namespace std;

PuissanceFour::PuissanceFour()
{
m_P4Board=new Board;

m_P4Players[0]=new HumanPlayer;
m_P4Players[0]->setName("Player_1");
m_P4Players[0]->setCoinType('x');

m_P4Players[1]=new ComputeurPlayer;
m_P4Players[1]->setName("Player_2");
m_P4Players[1]->setCoinType('o');


}


PuissanceFour::PuissanceFour(int rows,int cols,string player1Name,string player2Name,string partyType)
{

m_P4Board=new Board(rows,cols);

if (partyType=="vsIA")
{
    m_P4Players[0]=new HumanPlayer;
    m_P4Players[1]=new ComputeurPlayer;
}
else
{
    m_P4Players[0]=new HumanPlayer;
    m_P4Players[1]=new HumanPlayer;
}

m_P4Players[0]->setName(player1Name);
m_P4Players[0]->setCoinType('x');

m_P4Players[1]->setName(player2Name);
m_P4Players[1]->setCoinType('o');


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
        //associate players to the board
        m_P4Players[0]->setBoard(m_P4Board);
        m_P4Players[0]->setBoard(m_P4Board);


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
