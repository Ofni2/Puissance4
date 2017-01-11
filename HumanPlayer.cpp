#include "HumanPlayer.h"

using namespace std;

/**
*
* Default human constructor
*
**/
HumanPlayer::HumanPlayer()
{
}



/**
*
* Default human destructor
*
**/
HumanPlayer::~HumanPlayer()
{
}



/**
*
* Methode used for human to play
*
* @param[in] : Board* board : pointer to a board where to play
* @param[out] : if the play is winning, return the name of the player
*               else return "none"
*
**/
string HumanPlayer::play(Board* board)
{
       int col,coinRow,coinNotInBoard(-1);
       string winner("none");

        // if no board to play exit
        if (board==NULL) return "No Board to play !";

        do
        {
            board->DisplayBoard();

            cout<<"Tour de : "<<m_name<<"  vous jouer avec : "<<m_coinType<<endl;

            cout<<"indiquer la colonne ou jouer : (0 a "<<(board->getTotalCol()-1)<<")"<<endl;
            cin>>col;
            cout<<endl;
            cout<<endl;

            // putCoin return -1 while the column slected is out of the board
            coinNotInBoard=board->putCoin(col,m_coinType);
        }
        while( coinNotInBoard == -1 );

        coinRow=board->getTotalRow()-board->getCoinsPerCol(col);

        //if this play is a winning one, set the winner to player's name
        if ( board->checkVictory(coinRow,col) ) winner=m_name;

        return winner;
}
