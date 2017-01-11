#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"
#include "Board.h"


class ComputerPlayer : public Player
{
    public:

        ComputerPlayer();

        virtual std::string play(Board* board);

        virtual ~ComputerPlayer();


    protected:

        int m_IALevel;

        bool canPlay(Board* board,int row,int col);
};

#endif // COMPUTEURPLAYER_H
