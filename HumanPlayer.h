#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"


class HumanPlayer : public Player
{
    public:

        // Constructor
        HumanPlayer();

        HumanPlayer(std::string name,char coinType);

        // External methods
        std::string play(Board* board);

        int getIALevel();

        // Destructor
        virtual ~HumanPlayer();
};

#endif // HUMANPLAYER_H
