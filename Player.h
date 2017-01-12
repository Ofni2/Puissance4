#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

#include "Board.h"

class Player
{
    public:

        Player();

        Player(std::string name,char coinType);

        virtual std::string play(Board* board);

        std::string getName();
        void setName(std::string nom);

        char getCoinType();
        void setCoinType(char x);

        char getOpponentCoinType();
        int setOpponentCoinType(char x);

        virtual int getIALevel();

        virtual ~Player();


    protected:

        std::string m_name;
        char m_coinType;
        char m_opponentCointype;
};

#endif // PLAYER_H
