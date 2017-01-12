#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

#include "Board.h"

class Player
{
    public:

        // Constructor
        Player();

        Player(std::string name,char coinType);


        // Get
        std::string getName();

        char getCoinType();

        char getOpponentCoinType();


        // Set
        void setName(std::string nom);

        void setCoinType(char x);

        int setOpponentCoinType(char x);


        // Other methods
        virtual std::string play(Board* board);


        // Destructor
        virtual ~Player();


    protected:

        // Attributes
        std::string m_name;

        char m_coinType;

        char m_opponentCointype;
};

#endif // PLAYER_H
