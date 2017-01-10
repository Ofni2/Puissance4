#include "Player.h"

using namespace std;

Player::Player()
{
}


Player::~Player()
{
}

string Player::getName()
{
    return m_name;
}

void Player::setName(string name)
{
    m_name=name;
}

char Player::getCoinType()
{
    return m_coinType;
}

void Player::setCoinType(char x)
{
    m_coinType=x;
}


void Player::play(int col)
{
}

void Player::setBoard(Board* board)
{
    m_board= *board;
}

