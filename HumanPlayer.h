#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"


class HumanPlayer : public Player
{
    public:

        HumanPlayer();

        virtual std::string play(Board* board);

        virtual ~HumanPlayer();
};

#endif // HUMANPLAYER_H
