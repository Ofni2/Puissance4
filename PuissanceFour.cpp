#include <iostream>
#include "PuissanceFour.h"

using namespace std;


/**
*
* Default constructor
*
* it initialize :
*     - a 7x6 board
*     - one human player named "Player 1", he/she plays "x"
*     - one human player named "Player 2", he/she plays "o"
*
**/
PuissanceFour::PuissanceFour()
{
    m_P4Board=new Board;
    m_gameType="vsIA";

    m_P4Players[0]=new HumanPlayer;
    m_P4Players[0]->setName("Player 1");
    m_P4Players[0]->setCoinType('x');
    m_P4Players[0]->setOpponentCoinType('o');

    if (m_gameType=="vsH")
    {
        m_P4Players[1]=new HumanPlayer;
        m_P4Players[1]->setName("Player 2");
        m_P4Players[1]->setCoinType('o');
        m_P4Players[1]->setOpponentCoinType('x');
    }
    else if (m_gameType=="vsIA")
    {
        m_P4Players[1]=new ComputerPlayer;
        m_P4Players[1]->setName("Player 2_IA");
        m_P4Players[1]->setCoinType('o');
        m_P4Players[1]->setOpponentCoinType('x');
    }
}



/**
*
* constructor to initializes a P4 play as necessary
*
**/
PuissanceFour::PuissanceFour(int rows,
                             int cols,
                             string player1Name,
                             char coinType1,
                             string player2Name,
                             char coinType2,
                             string partyType)
{

m_P4Board=new Board(rows,cols);
m_gameType=partyType;

if (partyType=="vsIA")
{
    m_P4Players[0]=new HumanPlayer;
    m_P4Players[1]=new ComputerPlayer;
}
else if (partyType=="vsH")
{
    m_P4Players[0]=new HumanPlayer;
    m_P4Players[1]=new HumanPlayer;
}

m_P4Players[0]->setName(player1Name);
m_P4Players[0]->setCoinType(coinType1);
m_P4Players[0]->setOpponentCoinType(coinType2);

m_P4Players[1]->setName(player2Name);
m_P4Players[1]->setCoinType(coinType2);
m_P4Players[1]->setOpponentCoinType(coinType1);

}



/**
*
* destructor
*
**/
PuissanceFour::~PuissanceFour()
{
        delete m_P4Board;
        delete m_P4Players[0];
        delete m_P4Players[1];
}



/**
*
* method to play a game
*
* @param[out] when game is over return the name of the winner
*
**/
string PuissanceFour::Play()
{
    string winner("none");
    string playerName(" ");
    int turnCounter(0),j(0);

    do
    {
        // player play with a board! (method differs from Human or Computeur)
        winner=m_P4Players[j]->play(m_P4Board);

        // if someone win, exit from while loop
        if (winner==m_P4Players[j]->getName()){break;}

        // change player
        if (j==0) {j=1;}
        else      {j=0;}

        turnCounter++;
    }
    while (  turnCounter < (   ((m_P4Board->getTotalRow())) * ((m_P4Board->getTotalCol()))  )    );
    // while board is not full, the play continue

    // when game is over display the last state of the board
    m_P4Board->DisplayBoard();
    cout<<"Game over !"<<endl;

    return winner;
}


/**
*
* method to change the name of the players
*
**/
void PuissanceFour::initName()
{

    char ans(' ');
    string name(" ");

    cout<<"Players name : "<<endl;
    cout<<"- player 1 's name : "<<m_P4Players[0]->getName()<<endl;
    cout<<"- player 2 's name : "<<m_P4Players[1]->getName()<<endl;

    do
    {
        cout<<"do you want to change players name ? (y/n)"<<endl;
        cin>>ans;
        cout<<endl;

        if (ans == 'y')
        {
            cout<<"input player 1 name : "<<endl;
            cin>>name;
            m_P4Players[0]->setName(name);
            cout<<endl;

            cout<<"input player 2 name : "<<endl;
            cin>>name;
            m_P4Players[1]->setName(name);
            cout<<endl;
        }

    } while (ans != 'y' && ans != 'n');
}



/**
*
* method to change the coin type of players
*
**/
void PuissanceFour::initCoinsType()
{
    char ans(' ');
    char coinsType(' ');

    // to avoid problems when changing the game type
    m_P4Players[0]->setCoinType('x');
    m_P4Players[1]->setCoinType('o');

    cout<<"Coins type : "<<endl;
    cout<<m_P4Players[0]->getName()<<" plays with : "<<m_P4Players[0]->getCoinType()<<endl;
    cout<<m_P4Players[1]->getName()<<" plays with : "<<m_P4Players[1]->getCoinType()<<endl;

    do
    {
        cout<<"do you want to change players's coin type ? (y/n)"<<endl;
        cin>>ans;
        cout<<endl;

        if (ans=='y')
        {
            cout<<"input player 1 coin type : "<<endl;
            cin>>coinsType;
            m_P4Players[0]->setCoinType(coinsType);
            cout<<endl;

            do
            {
                cout<<"input player 2 coin type : "<<endl;
                cin>>coinsType;
                m_P4Players[1]->setCoinType(coinsType);
                cout<<endl;

            } while(coinsType == m_P4Players[0]->getCoinType());

            m_P4Players[0]->setOpponentCoinType(m_P4Players[1]->getCoinType());
            m_P4Players[1]->setOpponentCoinType(m_P4Players[0]->getCoinType());
        }

    } while (ans != 'y' && ans != 'n');
}



/**
*
* method to change the size of the board
*
**/
void PuissanceFour::initBoardSize()
{

    char ans(' ');
    int rows(0),cols(0);

    cout<<"Board size : "<<endl;
    cout<<"- rows    : "<<m_P4Board->getTotalRow()<<endl;
    cout<<"- columns : "<<m_P4Board->getTotalCol()<<endl;

    do
    {
        cout<<"do you want to change the board size ? (y/n)"<<endl;
        cin>>ans;
        cout<<endl;

        if (ans=='y')
        {
            cout<<"input number of row  : "<<endl;
            cin>>rows;
            cout<<endl;

            cout<<"input number of row  :  "<<endl;
            cin>>cols;
            cout<<endl;

            m_P4Board=new Board(rows,cols);
        }
    } while (ans != 'y' && ans != 'n');
}


/**
*
* method to
*
**/
void PuissanceFour::initGameType()
{

    char ans(' ');
    ComputerPlayer* IAPlayers;

    cout<<"game type is versus : "<<m_gameType <<endl;


    do
    {
        cout<<"do you want to change the game type (y/n)"<<endl;
        cin>>ans;
        cout<<endl;

        if (ans=='y')
        {
            if (m_gameType=="vsH")
            {
                IAPlayers=new ComputerPlayer();
                m_P4Players[1]=IAPlayers;
                m_P4Players[1]=new ComputerPlayer();
                m_gameType="vsIA";
                cout<<"game type is now on : "<<m_gameType<<endl;
                cout<<endl;
                cout<<"select level of IA :"<<endl;
                //cin>>IAPlayers->setIALevel();
                cout<<endl;
            }
            else if (m_gameType=="vsIA")
            {
                m_P4Players[1]=new HumanPlayer();
                m_gameType="vsH";
                cout<<"game type is now on : "<<m_gameType<<endl;
                cout<<endl;
            }
        }
    } while (ans != 'y' && ans != 'n');
}




/**
*
* method to launch the game
*
**/
void PuissanceFour::launch()

{
    string winner("none");
    char ans(' ');

    DisplaySettings();

    do
    {
        cout<<"change game settings ? (y/n)"<<endl;
        cin>>ans;
        cout<<endl;

        if (ans=='y')
        {
            initGameType();
            initName();
            initCoinsType();
            initBoardSize();

            DisplaySettings();
            ans=' ';
        }
    }
    while (ans !='y' && ans !='n');




    do
    {
        winner=Play();
        cout<<endl<<"********  winner is : "<<winner<<"   ********"<<endl;

        cout<<endl;
        cout<<endl;
        cout<<"Play again ? (y/n)"<<endl;
        cin>>ans;

        if (ans=='y') m_P4Board->reset();

    }
    while (ans !='n');
}



/**
*
* method to display the game settings
*
**/
void PuissanceFour::DisplaySettings()
{
 cout<<endl;
 cout<<"-------------------GAME TYPE---------------"<<endl;
 cout<<"game type is : "<<m_gameType<<endl;
// if (m_gameType=="vsIA") {cout<<"IA level is : "<<m_P4Players[1]->getIALevel()<<endl;}
 cout<<endl;
 cout<<"-------------------BOARD-------------------"<<endl;
 //cout<<"Board size : "<<endl;
 cout<<"Number of rows   : "<<m_P4Board->getTotalCol()<<endl;
 cout<<"Number of columns: "<<m_P4Board->getTotalRow()<<endl;
 cout<<endl;
 cout<<"-------------------PLAYERS------------------"<<endl;
 cout<<"Player 1 : "<<m_P4Players[0]->getName()<<"    plays with : "<<m_P4Players[0]->getCoinType()<<endl;
 cout<<"Player 2 : "<<m_P4Players[1]->getName()<<"    plays with : "<<m_P4Players[1]->getCoinType()<<endl;
 cout<<endl;
 cout<<"-------------------------------------------"<<endl;
 cout<<endl;
}
