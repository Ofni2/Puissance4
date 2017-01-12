#include "ComputeurPlayer.h"
#include <stdlib.h>
#include <time.h>


using namespace std;

ComputerPlayer::ComputerPlayer()
{
    m_IALevel=1;
}

ComputerPlayer::~ComputerPlayer()
{
}

string ComputerPlayer::play(Board* board)
{
    int colToPlay(-1);
    int rowToPlay(-1);
    string winner("none");


    switch(m_IALevel)
    {
    case (0):
    //IA plays randomly !
        winner=randomPlay(board);

    case(1):

        //IA checks if opponent can win at the next turn if not it play randomly
        colToPlay=selectCol_1(board);

        if (colToPlay>=0)
        {
            board->putCoin(colToPlay,m_coinType);
            rowToPlay=board->getRowOfLastCoin(colToPlay);
            winner=board->checkVictory(rowToPlay,colToPlay);
        }
        else
        {
            winner=randomPlay(board);
        }

        break;

    case(3):
        break;
        //IA checks if opponent can win at the next turn if not explorer the graph of possible plays
        //deep of the graph increase "intelligence" of IA
    default:
        break;


    }


    return winner;
}


/**
*
* Methode to check is the computer can play at a position
*
* @param[in]  int row   : index of the row where to play
* @param[in]  int col   : index of the column where to play
* @param[out] return    : Returns true if it is possible
*
**/
bool ComputerPlayer::canPlay(Board* board,int row,int col)
{
    bool check(true);
    int lastCoinRow;

    lastCoinRow=board->getTotalRow()-board->getCoinsPerCol(col)-1;

    if (row>=lastCoinRow)  {check=false;}

    return check;
}

string ComputerPlayer::randomPlay(Board* board)
{
    int colToPlay(0);
    int rowToPlay(0);
    int coinNotInBoard(-1);
    string winner("none");

    srand(time(NULL));

    do
    {
        colToPlay=rand()%(board->getTotalCol());
        coinNotInBoard=board->putCoin(colToPlay,m_coinType);

    } while (coinNotInBoard == -1);

        //board->DisplayBoard();
        cout<<"IA plays on columns : "<<colToPlay<<endl;
        cout<<endl;

        rowToPlay=board->getRowOfLastCoin(colToPlay);

        if ( board->checkVictory(rowToPlay,colToPlay) ) winner=m_name;

        return winner;
}


int ComputerPlayer::selectCol_1(Board* board)
{
    int colToPlay(-1);
    int lastCoinRow(0);

    for (int i(0);i<board->getTotalCol();i++)
        {
            lastCoinRow=board->getRowOfLastCoin(i);

            // if there is a free place to put a coin
            if( lastCoinRow>0 )
            {
                board->putCoin(i,m_opponentCointype);

                if ( board->checkVictory(board->getRowOfLastCoin(i),i) )
                {
                    board->removeCoin(i);
                    colToPlay=i;
                    return colToPlay;
                }
                else
                {
                    board->removeCoin(i);
                }
            }
        }


    return colToPlay;
}
