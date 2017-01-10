#include "HumanPlayer.h"

using namespace std;

HumanPlayer::HumanPlayer()
{
}

HumanPlayer::~HumanPlayer()
{
}

void HumanPlayer::play(int col)
{
       int coinNotInBoard(-1);

        do
        {
            m_board->DisplayBoard();
            cout<<"indiquer la colonne ou jouer : (0 a "<<(m_board->getTotalCol()-1)<<")"<<endl;
            cin>>col;
            coinNotInBoard=m_board->putCoin(col,getCoinType());
        }
        while( coinNotInBoard == -1 );
}
