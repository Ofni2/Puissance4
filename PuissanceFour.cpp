#include <iostream>
#include <cctype>
#include "PuissanceFour.h"

using namespace std;



/**
*
* default constructor with :
*
* ->  m_P4Board         : a default 7x6 board
* ->  a computer player : named "IA", it plays with 'o'
*
**/
PuissanceFour::PuissanceFour()
{
    m_P4Board=new Board;
    m_gameType="vsIA";

    m_P4Players[0]=new HumanPlayer("Player 1",'x');
    m_P4Players[0]->setOpponentCoinType('o');

    m_P4Players[1]=new ComputerPlayer("IA",'o',2);
    m_P4Players[1]->setOpponentCoinType('x');
}



/**
*
* General constructor
*
**/
PuissanceFour::PuissanceFour(int rows,int cols,string Name1,char coinType1,string Name2,char coinType2,string partyType)
{

m_P4Board=new Board(rows,cols);
m_gameType=partyType;

if (partyType=="vsIA")
{
    m_P4Players[0]=new HumanPlayer(Name1,coinType1);
    m_P4Players[1]=new ComputerPlayer(Name2,coinType2,2);
}
else if (partyType=="vsH")
{
    m_P4Players[0]=new HumanPlayer(Name1,coinType1);
    m_P4Players[1]=new HumanPlayer(Name2,coinType2);
}
else if (partyType=="IAvsIA")
{
    m_P4Players[0]=new ComputerPlayer(Name1,coinType1,2);
    m_P4Players[1]=new ComputerPlayer(Name2,coinType2,2);
}

m_P4Players[0]->setOpponentCoinType(coinType2);
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
* method to manage the game sequence
*
* @param[out] return    : Returns "none" or the name of the winner
*
**/
string PuissanceFour::Play()
{
    string winner("none");
    int turnCounter(0),j(0);

    do
    {
        // player play in a board (method differs from Human or Computer)
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
    string coinsType(" ");

    // to avoid problems when changing the game type
    if (m_P4Players[0]->getCoinType() == m_P4Players[1]->getCoinType())
    {
        m_P4Players[0]->setCoinType('x');
        m_P4Players[0]->setOpponentCoinType('o');

        m_P4Players[1]->setCoinType('o');
        m_P4Players[1]->setOpponentCoinType('x');

    }

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

            m_P4Players[0]->setCoinType(coinsType[0]);
            cout<<endl;

            do
            {
                cout<<"input player 2 coin type : "<<endl;
                cin>>coinsType;

                m_P4Players[1]->setCoinType(coinsType[0]);
                cout<<endl;

            } while(coinsType[0] == m_P4Players[0]->getCoinType());

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
* method to change the type of game (vsH or vsIA)
*
**/
void PuissanceFour::initGameType()
{

    char ans(' ');
    int IALevel(2);

    cout<<"game type is versus : "<<m_gameType <<endl;
    if (m_gameType == "vsIA") {cout<<"IA level : "<<m_P4Players[1]->getIALevel()<<endl;;}


    do
    {
        cout<<"do you want to change the game type (y/n)"<<endl;
        cin>>ans;
        cout<<endl;

        if (ans=='y')
        {
            if (m_gameType=="vsH")
            {
                //creation of a new computer player
                m_P4Players[1]=new ComputerPlayer();

                // switch game type
                m_gameType="vsIA";

                cout<<"game type is now on : "<<m_gameType<<endl;

                do {
                    cout<<"select the IA level (0/1/2) : "<<endl;
                    cin>>IALevel;
                   } while (IALevel > 2 || IALevel <0 );
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

    displaySettings();

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

            displaySettings();
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
void PuissanceFour::displaySettings()
{
 cout<<endl;
 cout<<"-------------------GAME TYPE---------------"<<endl;
 cout<<"game type is : "<<m_gameType<<endl;
 if (m_gameType=="vsIA") {cout<<"IA level is : "<<m_P4Players[1]->getIALevel()<<endl;}
 cout<<endl;
 cout<<"-------------------BOARD-------------------"<<endl;
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
