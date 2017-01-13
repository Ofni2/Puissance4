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
    int col(-1);


    switch(m_IALevel)
    {

    //IA plays randomly !
    case (0):

        col=IA_0(board);
        break;

    //IA checks if opponent can win at the next turn if not, it plays randomly
    case(1):

        col=IA_1(board);
        if (col==-1) {col=IA_0(board);}
        break;

    // IA first checks if it can win. If not check if opponent can win. if not play randomly
    case(2):

        col=IA_2(board);
        if (col==-1) {col=IA_0(board);}
        break;

    // IA_3
    case(3):
        // For IA_3 add a more deeper vision (graph of possible move ?)
        // for example IA_2 cannot anticipate that if it plays (o) in columns 5, opponent (x) will win at the next turn
        //
        //
        //   1 2 3 4 5 6 7 8
        //   . . . . . . . .
        //   . . . . . . . .
        //   . . . . . . . .
        //   . . X O . . . .
        //   . . O X X . . .
        //   . O X O O . . .
        //

        col=IA_3(board);
        break;

    //IA plays randomly !
    default:

        col=IA_0(board);
        break;
    }

    winner=putCoin(board,col);

    return winner;
}


/**
*
* Method to put a coin in the board
*
* @param[in]  Board* board  : Pointer to a board
* @param[out] return        : Returns  ComputerPlayer name if it is a winning move, else return "none"
*
**/
string ComputerPlayer::putCoin(Board* board,int colToPlay)
{
    int rowToPlay(0);
    string winner("none");

    if(board == NULL){return "Err_Board_randomPlay";}
    if(colToPlay <0 || colToPlay >= board->getTotalCol()){return "Err_Outside_Play";}

    board->putCoin(colToPlay,m_coinType);

    cout<<m_name<<" plays on column : "<<colToPlay<<endl;
    cout<<endl;

    rowToPlay=board->getRowOfLastCoin(colToPlay);

    // check if it is a winning move
    if ( board->checkVictory(rowToPlay,colToPlay) ) winner=m_name;

    return winner;
}



/**
*
* Method to give of column depending of the option :
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



/**
*
* Method to manage IA
*
* IA_0 : random move
*
* @param[in]  Board* board  : Pointer to a board
* @param[out] return        : Returns  index of the columns where the IA must play
*
**/
int ComputerPlayer::IA_0(Board* board)
{
    int colToPlay;

    srand(time(NULL));
    do
    {
        colToPlay=rand()%(board->getTotalCol());

    } while ( board->getRowOfLastCoin(colToPlay) == 0 );
    // IA continues to play as long as it does not play in a free column

    return colToPlay;
}

/**
*
* Method to manage IA
*
* IA_1 : IA checks if opponent can win at the next turn (3 coins aligned)
*        if opponent can't win, IA plays randomly
*
* @param[in]  Board* board  : Pointer to a board
* @param[out] return        : Returns  index of the columns where the IA must play
*
**/
int ComputerPlayer::IA_1(Board* board)
{
    int colToPlay(-1);
    int  col(-1);

    if (board == NULL) {return -2;}

        // check if opponent can win
        colToPlay=selectCol(board,2);

        if ( colToPlay >= 0 && colToPlay < board->getTotalCol() )
        {
            cout<<"IA prevent opponent to win"<<endl;
            col=colToPlay;
        }
        // if opponent can not win
        else
        {
            col = -1;
        }


 return col;
}



/**
*
* Method to manage IA
*
* IA_2 : IA first checks if it can win. If not check if opponent can win. if not play randomly.
*
* @param[in]  Board* board  : Pointer to a board
* @param[out] return        : Returns  index of the columns to play
*
**/
int ComputerPlayer::IA_2(Board* board)
{
    int colToPlay1(-1);
    int col(-1);

    if (board == NULL) {return -3;}

        //colToPlay2=selectCol(board,2);
        colToPlay1=selectCol(board,1);

        // play to win
        if ( colToPlay1 >=0  &&  colToPlay1 < board->getTotalCol() )
        {
            cout<<m_name<<" will win !"<<endl;
            cout<<endl;

            col=colToPlay1;
        }

        // if IA can not win, play to prevent opponent victory
        if (colToPlay1 == -1)
        {
            col=IA_1(board);
        }

 return col;

}


/**
*
*
*
*
*
*
**/
int ComputerPlayer::IA_3(Board* board)
{
    int colToPlay(-1);
    int col(-1);
    int row(-1);
    bool stop(true);

    if (board == NULL) {return -3;}

    col=IA_2(board);

    //if nobody can win at next turn
    if ( col == -1 )
    {
        do
        {
            // random move
            colToPlay=IA_0(board);
            board->putCoin(colToPlay,m_coinType);

            //if opponent plays in the same columns
            board->putCoin(colToPlay,m_opponentCointype);
            row=board->getRowOfLastCoin(colToPlay);

            // if opponent win
            if ( board->checkVictory(row,colToPlay) )
            {
                // remove opponent coin
                board->removeCoin(colToPlay);

                // remove IA coin
                board->removeCoin(colToPlay);

                // find an other column to play
                stop=true;
            }
            else
            {
                // remove opponent coin
                board->removeCoin(colToPlay);

                // remove IA coin
                board->removeCoin(colToPlay);

                // stop looking for a good columns
                stop=false;
                col=colToPlay;
            }
        } while ( stop );
    }

 return col;

}




