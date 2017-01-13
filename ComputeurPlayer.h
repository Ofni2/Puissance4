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


        // External methods
        virtual std::string play(Board* board);


        // Destructor
        virtual ~ComputerPlayer();


    protected:

        // Internal methods
        int selectCol(Board* board,int option);

        int IA_1(Board* board);

        int IA_2(Board* board);

        std::string putCoin(Board* board,int colToPlay=-1);


        // Attributes
        int m_IALevel;


};

#endif // COMPUTEURPLAYER_H
