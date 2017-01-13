#include "Player.h"

using namespace std;

/**
*
* default constructor with :
*
* ->  m_name="Player"
* ->  m_coinType='x'
* ->  m_opponentCointype=' '
*
**/
Player::Player()
{
    m_name="Player";
    m_coinType='x';
    m_opponentCointype=' ';
}



/**
*
* General constructor
*
**/
Player::Player(std::string name,char coinType)
{
   m_name=name;
   m_coinType=coinType;
   m_opponentCointype=' ';
}



/**
*
* default destructor
*
**/
Player::~Player()
{
}


/**
*
* Method to get the name of the player
*
**/
string Player::getName()
{
    return m_name;
}



/**
*
* Method to set the name type of the player
*
* @param[in] string name : name of the player
*
**/
void Player::setName(string name)
{
    m_name=name;
}



/**
*
* Method to get the coin type of the player
*
**/
char Player::getCoinType()
{
    return m_coinType;
}



/**
*
* Method to set the coin type of the player
*
* @param[in] char x : type of the coin (it can be 'x', 'o', ...)
*
**/
void Player::setCoinType(char x)
{
    m_coinType=x;
}



/**
*
* Method to set the coin type of the opponent
*
* @param[in]  char x     : type of the coin (it can be 'x', 'o', ...)
* @param[out] return     : returns -1 if error (coinType already taken), else 0
*
**/
int Player::setOpponentCoinType(char x)
{
    //if the chosen coin is already taken by the opponent return -1;
    if (m_coinType == x) {return -1;}

    m_opponentCointype=x;

    return 0;
}



/**
*
* Method to get the coin type of the opponent
*
* @param[in] char x : type of the coin (it can be 'x', 'o', ...)
*
**/
char Player::getOpponentCoinType()
{
    return m_opponentCointype;
}



/**
*
* Virtual Method to play
* Method differs from Human or Computer
*
**/
string Player::play(Board* board)
{
    return " ";
}


int Player::getIALevel()
{
    return 0;
}
