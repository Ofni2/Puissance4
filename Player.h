#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

#include "Board.h"

class Player
{
    public:
        Player();
        virtual ~Player();

        void play(int col);

        std::string getName();
        void setName(std::string nom);

        char getCoinType();
        void setCoinType(char x);

        void setBoard(Board* board);


    protected:

        std::string m_name;
        char m_coinType;
        Board* m_board;


};

#endif // PLAYER_H
