#include "ComputeurPlayer.h"
#include <stdlib.h>


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
    int i(0);
    int col(0);
    int coinNotInBoard(-1);
    int* coinPerDirection(NULL);
    int lastCoinRow(0);
    int colToPlay(0);
    char coinType(' ');
    string winner("none");


    switch(m_IALevel)
    {
    case (0):
        //IA plays randomly !
        do{
            colToPlay=rand()%(board->getTotalCol());
            coinNotInBoard=board->putCoin(colToPlay,m_coinType);

            //board->DisplayBoard();
            cout<<"IA plays on columns : "<<colToPlay<<endl;
            cout<<endl;

          } while (coinNotInBoard == -1);

        break;

    case(1):
    //IA checks if opponent can win at the next turn if not it play randomly

        // for  each column
        for (int i(0);i<board->getTotalCol();i++)
        {

        lastCoinRow=board->getTotalRow()-board->getCoinsPerCol(col)-1;
        coinType=board->getCoinType(lastCoinRow,col);

            // if the coins is the opponent 's one
            if(coinType != m_coinType && coinType != ' ')
                {
                    //get numbers of adjacent coins in each direction
                    coinPerDirection=board->getCoinsPerDirection(lastCoinRow,col);

                    // check all direction possible
                    for (int j(0);j<8;j++)
                    {
                        //if a coins is in a line of 3
                        //if ((coinPerDirection[j]+coinPerDirection[7-j]-2)==3 && )
                    }

                }

        cout<<"___"<<coinPerDirection[5]<<"___";
        }




        do{
            colToPlay=rand()%(board->getTotalCol());
            coinNotInBoard=board->putCoin(colToPlay,m_coinType);

            //board->DisplayBoard();
            cout<<"IA plays on columns : "<<colToPlay<<endl;
            cout<<endl;

          } while (coinNotInBoard == -1);


        break;

    case(3):
        break;
        //IA checks if opponent can win at the next turn if not explorer the graph of possible plays
        //deep of the graph increase "intelligence" of IA
    default:
        break;








    }




 /*       int col,coinRow,coinNotInBoard(-1);
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

*/











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
