#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"
#include "Board.h"


class ComputerPlayer : public Player
{
    public:

        ComputerPlayer();

        virtual std::string play(Board* board);

        int selectCol_1(Board* board);
        int selectCol_2(Board* board);

        virtual ~ComputerPlayer();


    protected:

        int m_IALevel;

        bool canPlay(Board* board,int row,int col);

        std::string randomPlay(Board* board);
};

#endif // COMPUTEURPLAYER_H
