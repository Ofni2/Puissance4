#include "HumanPlayer.h"

using namespace std;

/**
*
* default constructor with :
*
* ->  m_name="H_Player"
* ->  m_coinType='x'
* ->  m_opponentCointype=' '
*
**/
HumanPlayer::HumanPlayer()
{
    m_name="H_player";
    m_coinType='x';
    m_opponentCointype=' ';
}


/**
*
* General constructor
*
**/
HumanPlayer::HumanPlayer(string name,char coinType)
{
    m_name=name;
    m_coinType=coinType;
    m_opponentCointype=' ';
}



/**
*
* Default destructor
*
**/
HumanPlayer::~HumanPlayer()
{
}



/**
*
* Method used for human to play
*
* @param[in]  : Board* board    : pointer to a board where to play
* @param[out] : return          : Returns the name of the winner,else return "none" (or Err_ if error occurs)
*
**/
string HumanPlayer::play(Board* board)
{
       int col;
       int coinRow;
       int coinNotInBoard(-1);

       string winner("none");

        // if no board to play exit
        if (board==NULL) return "Err_Board_H_play";

        do
        {
            board->DisplayBoard();

            cout<<"Tour de         : "<<m_name<<endl;
            cout<<"vous jouez avec : "<<m_coinType<<endl;

            cout<<"indiquer la colonne ou jouer : (0 a "<<(board->getTotalCol()-1)<<")"<<endl;
            cin>>col;
            cout<<endl;
            cout<<endl;

            // putCoin return -1 while the column selected is out of the board
            coinNotInBoard=board->putCoin(col,m_coinType);
        }
        while( coinNotInBoard == -1 );

        cout<<m_name<<" plays on columns : "<<col<<endl;
        cout<<endl;

        coinRow=board->getRowOfLastCoin(col);

        //if this play is a winning one, set the winner to player's name
        if ( board->checkVictory(coinRow,col) ) winner=m_name;

        return winner;
}



int HumanPlayer::getIALevel()
{
    return 0;
}
