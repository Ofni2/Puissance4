#include "Player.h"

using namespace std;

/**
*
* default constructor
*
**/
Player::Player()
{
}



/**
*
* default constructor
*
**/
Player::Player(std::string name,char coinType)
{
   m_name=name;
   m_coinType=coinType;
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
* Methode to get the name of the player
*
**/
string Player::getName()
{
    return m_name;
}



/**
*
* Methode to set the name type of the player
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
* Methode to get the coin type of the player
*
**/
char Player::getCoinType()
{
    return m_coinType;
}



/**
*
* Methode to set the coin type of the player
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
* Methode to set the coin type of the opponent
*
* @param[in] char x : type of the coin (it can be 'x', 'o', ...)
*
**/
int Player::setOpponentCoinType(char x)
{
    if (m_coinType == x) {return -1;}
    m_opponentCointype=x;
    return 0;
}



/**
*
* Methode to get the coin type of the opponent
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
* Virtual methode to play
* methode differs from Human or Computeur
*
**/
string Player::play(Board* board)
{
    return " ";
}


 int Player::getIALevel()
 {

 }
