#include "ComputeurPlayer.h"
#include <stdlib.h>
#include <time.h>


using namespace std;



/**
*
* default constructor with :
*
* ->  m_name="IA"
* ->  m_coinType='o'
* ->  m_IALevel=2
* ->  m_opponentCointype=' '
*
**/
ComputerPlayer::ComputerPlayer()
{
    m_name="IA";
    m_coinType='o';
    m_IALevel=2;
    m_opponentCointype=' ';
}


/**
*
* General constructor
*
**/
ComputerPlayer::ComputerPlayer(string name,char coinType,int IAlevel)
{
    m_name=name;
    m_coinType=coinType;
    m_IALevel=IAlevel;
    m_opponentCointype=' ';
}


/**
*
* Destructor
*
**/
ComputerPlayer::~ComputerPlayer()
{
}


/**
*
* Method to manage how IA plays depending of it IA_level
*
* @param[in]  Board* board  : Pointer to a board
* @param[out] return        : Returns  ComputerPlayer name if it is a winning move, else return "none"
*
**/
string ComputerPlayer::play(Board* board)
{
    string winner("none");


    switch(m_IALevel)
    {

    //IA plays randomly !
    case (0):

        winner=randomPlay(board);
        break;

    //IA checks if opponent can win at the next turn if not, it plays randomly
    case(1):

        winner=IA_1(board);
        break;

    // IA first checks if it can win. If not check if opponent can win. if not play randomly
    case(2):

        winner=IA_2(board);
        break;

    //IA plays randomly !
    default:

        winner=randomPlay(board);
        break;
    }

    return winner;
}


/**
*
* Method to manage IA
*
* IA_1 : IA checks if opponent can win at the next turn (3 coins aligned)
*        if opponent can't win, IA plays randomly
*
* @param[in]  Board* board  : Pointer to a board
* @param[out] return        : Returns  ComputerPlayer name if it is a winning move, else return "none"
*
**/
string ComputerPlayer::IA_1(Board* board)
{
    int colToPlay(-1);
    int rowToPlay(0);
    string winner("none");

    if (board == NULL) {return "Err_Board_IA_1";}

        // check if opponent can win
        colToPlay=selectCol(board,2);

        if (colToPlay >= 0)
        {
            cout<<m_name<<" prevent opponent to play on columns : "<<colToPlay<<endl;
            cout<<endl;

            // play  to prevent opponent victory
            board->putCoin(colToPlay,m_coinType);

            // check if the IA have win with it's move
            rowToPlay=board->getRowOfLastCoin(colToPlay);
            if(board->checkVictory(rowToPlay,colToPlay)) {winner=m_name;}
        }
        else if( colToPlay == -1 )
        {
            winner=randomPlay(board);
        }
        else
        {
            return "Err_selectCol_IA_1";
        }


 return winner;
}



/**
*
* Method to manage IA
*
* IA_2 : IA first checks if it can win. If not check if opponent can win. if not play randomly.
*
* @param[in]  Board* board  : Pointer to a board
* @param[out] return        : Returns  ComputerPlayer name if it is a winning move, else return "none"
*
**/
string ComputerPlayer::IA_2(Board* board)
{
    int colToPlay1(-1);
    int colToPlay2(-1);
    int rowToPlay(0);

    string winner("none");

    if (board == NULL) {return "Err_Board_IA_2";}

        colToPlay2=selectCol(board,2);
        colToPlay1=selectCol(board,1);

        // play to win
        if ( colToPlay1 >=0)
        {
            cout<<m_name<<" win in playing in column : "<<colToPlay1<<endl;
            cout<<endl;

            // normal we know that this move is already a winning one !
            board->putCoin(colToPlay1,m_coinType);
            rowToPlay=board->getRowOfLastCoin(colToPlay1);
            if(board->checkVictory(rowToPlay,colToPlay1)) {winner=m_name;}
        }
        // play to prevent opponent victory
        else if ( colToPlay2 >= 0 )
        {
            cout<<m_name<<" prevents opponent to play on columns : "<<colToPlay2<<endl;
            cout<<endl;

            board->putCoin(colToPlay2,m_coinType);
            rowToPlay=board->getRowOfLastCoin(colToPlay2);
            winner=board->checkVictory(rowToPlay,colToPlay2);
            if(board->checkVictory(rowToPlay,colToPlay2)) {winner=m_name;}
        }
        else if (colToPlay1 == -1 && colToPlay2 == -1)
        {
            winner=randomPlay(board);
        }
        else    return "Err_selectCol_IA_2";

 return winner;
}



/**
*
* Method to put a coin in a random column
*
* @param[in]  Board* board  : Pointer to a board
* @param[out] return        : Returns  ComputerPlayer name if it is a winning move, else return "none"
*
**/
string ComputerPlayer::randomPlay(Board* board)
{
    int colToPlay(0);
    int rowToPlay(0);
    int coinNotInBoard(-1);
    string winner("none");

    if(board == NULL){return "Err_Board_randomPlay";}

    srand(time(NULL));

    do
    {
        colToPlay=rand()%(board->getTotalCol());
        coinNotInBoard=board->putCoin(colToPlay,m_coinType);

    }
    while (coinNotInBoard == -1);
    // IA continues to play as long as it does not play in a free column

    cout<<m_name<<" plays on column : "<<colToPlay<<endl;
    cout<<endl;

    rowToPlay=board->getRowOfLastCoin(colToPlay);

    // check if it is a winning move
    if ( board->checkVictory(rowToPlay,colToPlay) ) winner=m_name;

    return winner;
}



/**
*
* Method to give depending of the option :
*
*   opt=1 : a column where to put a coin to get the victory
*   opt=2 : a column where the opponent can put a coin and get the victory
*
* @param[in]  Board* board  : A pointer to a board
* @param[in]  int opt       : Index of the option
* @param[out] return        : Returns the index of the columns where to play else -1 (and -2 and -3 for errors)
*
**/
int ComputerPlayer::selectCol(Board* board,int opt)
{
    int colToPlay(-1);
    int lastCoinRow(0);
    char coinType(' ');
    int err(-3);

    //Error management to implement
    if (board == NULL) {return -2;}

    // initialization depending of the option
    switch (opt)
    {
    case 1:
        coinType=m_coinType;
        break;

    case 2:
        coinType=m_opponentCointype;
        break;

    default :
        return err;
        break;
    }


    // for all column of the board
    for (int i(0); i<board->getTotalCol(); i++)
    {
        lastCoinRow=board->getRowOfLastCoin(i);

        // if it is possible to play a coin in this column
        if( lastCoinRow>0 )
        {
            // put a coin in the column
            board->putCoin(i,coinType);

            //if we or the opponent can win the game with this move return the index of the column
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

    // colToPlay return -1 if there is no columns
    // that satisfies the option
    return colToPlay;
}



/**
*
* Get the level of the IA
*
**/
int ComputerPlayer::getIALevel()
{
    return m_IALevel;
}



/**
*
* Set the level of the IA
*
**/
void ComputerPlayer::setIALevel(int level)
{
    m_IALevel=level;
}
