#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"
#include "Board.h"


class ComputerPlayer : public Player
{
    public:

        // Constructor
        ComputerPlayer();

        ComputerPlayer(std::string name,char coinType,int IAlevel);


        // Get
        int getIALevel();


        // Set
        void setIALevel(int const level);


        // Other methods
        virtual std::string play(Board* board);

        int selectCol(Board* board,int option);

        std::string IA_1(Board* board);

        std::string IA_2(Board* board);

        // Destructor
        virtual ~ComputerPlayer();


    protected:

        // Attributes
        int m_IALevel;

        std::string randomPlay(Board* board);
};

#endif // COMPUTEURPLAYER_H
